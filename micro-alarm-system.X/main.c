#include <stdio.h>
#include <string.h>
#include <p32xxxx.h>
#include "MenuHandler.h"
#include "PasswordManager.h"
#include "RGB.h"
#include "SecuritySystem.h"
#include "Logger.h"
#include "UART.h"
#include "Speaker.h"
#include "I2C.h"

#define _SUPPRESS_PLIB_WARNING

#define macro_enable_interrupts() \
{  unsigned int val = 0;\
asm volatile("mfc0 %0,$13":"=r"(val));  \
val |= 0x00800000;  \
asm volatile("mtc0 %0,$13" : "+r"(val)); \
INTCONbits.MVEC = 1; \
__builtin_enable_interrupts();}

/* Disable JTAG to use RA0 */
#pragma config JTAGEN = OFF
#pragma config FWDTEN = OFF

/* Device Config Bits in DEVCFG1: */
#pragma config FNOSC = FRCPLL
#pragma config FSOSCEN = OFF
#pragma config POSCMOD = XT
#pragma config OSCIOFNC = ON
#pragma config FPBDIV = DIV_2

/* Device Config Bits in DEVCFG2: */
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLMUL = MUL_20
#pragma config FPLLODIV = DIV_1

/*
 * Program entry point
 */
int main() {
    // Initialize menu with baud rate
    MENU_init(9600);
    
    // Set default password
    AUTH_changePassword("0000");
    
    // Enable interrupts on CPU
    macro_enable_interrupts();
    
    // Setup RGB led
    RGB_SetupLeds();
    RGB_setRed();
    
    // Setup logger
    LOGGER_Init();
    
    // Setup alarm speaker
    SPEAKER_Init();
    
    // Setup I2C communication
    I2C_Init();
    
    // Print splash screen when init finished
    MENU_splashscreen();
    
    // start security system
    while (1) {
        
        // Check if system enabled
        if (!AUTH_isSystemActive()) {
            putU4_string("Insert alarm system password:\n");
            while (!MENU_isResponseReceived()) {} // Wait for response
            
            // Check if inserted password is valid...
            if (AUTH_checkPassword(MENU_getAnswer())) {
                // Password valid
                AUTH_unlockSystem();
                putU4_string("\n\n-- VALID PASSWORD: ALARM SYSTEM UNLOCKED --\n\n");
            } else {
                // Password not valid
                putU4_string("[!] Password not valid! \n");
            }
        } else {
            // SYSTEM IS UNLOCKED
            
            // Print menu
            MENU_print(SECURITY_isSecuritySystemEnabled());

            // Wait for response
            while (!MENU_isResponseReceived()) {}

            // Get user answer + clear data
            char response[80];
            sprintf(response, "%s", MENU_getAnswer()); // TODO: Optimize char array length

            // Print answer
            char out[80];
            sprintf(out, "Answer: %s\n\n", response);
            putU4_string(out);

            // Check for response
            if (strcmp(response, "1") == 0) {
                // Check if system is enabled or not
                if (SECURITY_isSecuritySystemEnabled()) {
                    // Disable system
                    putU4_string("\n -- Disabling alarm system... WIP  -- \n");
                    RGB_setRed(); // change led color
                    SECURITY_disable(); // disable alarm system
                } else {
                    // Enable system
                    putU4_string("\n -- Activating alarm system... WIP  -- \n");
                    RGB_setBlue(); // change led color
                    SECURITY_enable(); // enable alarm system
                }
            } else if (strcmp(response, "2") == 0) {
                // Unlock alarm system: insert password
                putU4_string("\n -- Changing alarm system password-- \n");
                
                // Reset menu flag
                MENU_reset();
                
                // Insert current password
                putU4_string("\nInsert current password:");
                while (!MENU_isResponseReceived()) {}
                if (AUTH_checkPassword(MENU_getAnswer())) {
                    // If password is valid, change password
                    
                    // Receive new password
                    putU4_string("\nInsert new password: ");
                    MENU_reset();
                    while (!MENU_isResponseReceived()) {}
                    char * firstPsw = MENU_getAnswer();
                    
                    // Receive confirm password
                    putU4_string("\nConfirm password: ");
                    MENU_reset();
                    while (!MENU_isResponseReceived()) {}
                    char * secondPsw = MENU_getAnswer();
                    
                    // compare two password
                    if (strcmp(firstPsw, secondPsw) == 0) {
                        // Change current password with the one inserted
                        AUTH_changePassword(secondPsw);
                        putU4_string("\n [!] Password changed successfully, authentication needed \n"); // Print message
                        AUTH_lockSystem(); // re-lock system
                    } else {
                        putU4_string("\n [!] The two password does not match. The system will exit this wizard \n"); // Print error
                    }
                } else {
                    putU4_string("\n [!] Password not valid. The system will exit this wizard \n"); // Print error
                }
            } else if (strcmp(response, "3") == 0) {
                // Print access log
                putU4_string("\n -- Print log --");
                // Output data saved inside Logger
            } else if (strcmp(response, "4") == 0) {
                // Clear access log
                putU4_string("\n -- Clear log --");
                // Clear data saved inside Logger
            } else {
                // Response not recognized, show print menu error
                MENU_printError("Answer not valid. Retry again with a valid one. \n\n");
            }
        }
        // Reset menu
        MENU_reset();
    }
}
