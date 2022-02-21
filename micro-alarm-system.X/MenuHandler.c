#include <p32xxxx.h>
#include <stdio.h>
#include "UART.h"

#define MAX_MSG_LENGTH 80
/* Define UART interrupt handler */
#pragma interrupt MenuAnswerHandler IPL1AUTO vector 39
void MenuAnswerHandler (void);

/* UART.c external variables */
char flagRx = 0;
char strg[MAX_MSG_LENGTH];
int j = 0;

/**
 * Initialize menu handler with interrupt
 * @param baud UART baud rate
 */
void MENU_init (int baud) 
{
    UART_ConfigurePins();
    UART_ConfigureUart(baud);
}

/**
 * This function send the menu via UART
 */
void MENU_print () {
    putU4_string("1) Attiva\n");      
    putU4_string("2) Cambia password\n");
    putU4_string("3) Vedi Log\n");
    putU4_string("4) Cancella Log\n");
}

/**
 * This function gets the user answer
 * @return User answer
 */
char* MENU_getAnswer() {
    char* msg = strg;
    return msg;
}

/**
 * Send splashscreen via UART
 */
void MENU_splashscreen() {
    putU4_string("     _____ _                _____ _                  _____         _             \n");
    putU4_string("    |     |_|___ ___ ___   |  _  | |___ ___ _____   |   __|_ _ ___| |_ ___ _____ \n");
    putU4_string("    | | | | |  _|  _| . |  |     | | .'|  _|     |  |__   | | |_ -|  _| -_|     |\n");
    putU4_string("    |_|_|_|_|___|_| |___|  |__|__|_|__,|_| |_|_|_|  |_____|_  |___|_| |___|_|_|_|\n");
    putU4_string("                                                          |___|                  \n");
}

/**
 * Reset UART flags: RX flag + strg array
 */
void MENU_reset() {
    // Reset flag
    flagRx = 0;
    // Reset message buffer
    for (int i = 0; i < MAX_MSG_LENGTH; i++) {
        strg[i] = 0;
    }
}

/**
 * Getter function for the UART recived flag
 * @return Return 1 if an answer was received, otherwise 0
 */
int MENU_isResponseReceived() {
    return flagRx;
}

void MENU_printError(char* msg) {
    char out[80];
    sprintf(out, "[!] %s", msg);
    putU4_string(out);
}

/**
 * Uart interrupt handler routine - Reads messages and set data inside strg array
 */
void MenuAnswerHandler () {
    //Read the Uart4 RX buffer while data is available
	if (U4STAbits.URXDA)
    {
        char c = (unsigned char) U4RXREG;
        strg[j++] = c;      
        if(j>0 && (c == '\r' || c == '\n'))
        {
            strg[j-1] = 0;
            j = 0;
            flagRx = 1; // flag goes to 1 when string is received completely. Remember to reset the flag in main.c 
        }
    }
    
    // Procedure finished, exit from interrupt handler
    IFS2bits.U4RXIF = 0; // clear interrupt flag
}

