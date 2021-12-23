#include <stdio.h>
#include <string.h>
#include <p32xxxx.h>
#include "MenuHandler.h"
#include "UART.h"

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
    
    // Enable interrupts on CPU
    macro_enable_interrupts();
    
    while (1) {
        // Print menu
        MENU_print();
        
        // Wait for response
        while (!MENU_isResponseReceived()) {}
        
        // Get user answer
        char* response = MENU_getAnswer(); // TODO: Optimize char array length
        
        // Print answer
        char out[80];
        sprintf(out, "Answer: %s\n\n", MENU_getAnswer());
        putU4_string(out);
        
        
        // FIXME: Capire perchè response non entra in nessun if
        
        // Check for response
        if (strcmp(response, "1") == 0) {
            // Unlock alarm system: insert password
            putU4_string("\n -- Insert password --");
        } else if (strcmp(response, "2") == 0) {
            // Change password
            putU4_string("\n -- Change password --");
        } else if (strcmp(response, "3") == 0) {
            // Print access log
            putU4_string("\n -- Print log --");
        } else if (strcmp(response, "4") == 0) {
            // Clear access log
            putU4_string("\n -- Clear log --");
        } else {
            // Response not recognized, show print menu error
            MENU_printError("Answer not valid. Retry again with a valid one. \n\n");
        }
        
        // Reset menu
        MENU_reset();
    }
}
