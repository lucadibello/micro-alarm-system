/*
 * Title: UART.c
 * Description: UART configuration function and UART communication control
 * Author: Luca Di Bello
 * Date: 22.12.2021
*/

#include <p32xxxx.h>
#include "UART.h"

extern char flagRX;   // global - it has to be init in main.c
extern char strg[80]; // global - it has to be init in main.c
extern int j;         // global - it has to be init in main.c


void UART_ConfigurePins()   //used to configure UART4 TX and RX
{
	TRISFbits.TRISF12 = 0;   //TX digital output
    RPF12R = 2;     // 0010 U4TX - Mapping U4TX to RPF12;
    
    TRISFbits.TRISF13  = 1;   //RX digital input
    U4RXR = 9;     // 1001 RF13 - Mapping U4RX to RPF13
}

void UART_ConfigureUart(int baud)
{
    unsigned int PbusClock = 40000000;
    unsigned int UartBrg = 0;
    
	U4MODEbits.ON     = 0;
    U4MODEbits.SIDL   = 0;
    U4MODEbits.IREN   = 0; 
    U4MODEbits.RTSMD  = 0;
    U4MODEbits.UEN0   = 0; 
    U4MODEbits.UEN1   = 0;
    U4MODEbits.WAKE   = 0;
    U4MODEbits.LPBACK = 0; 
    U4MODEbits.ABAUD  = 0;
    U4MODEbits.RXINV  = 0; 
    U4MODEbits.PDSEL1 = 0; 
    U4MODEbits.PDSEL0 = 0; 
    U4MODEbits.STSEL  = 0;  
    
    U4MODEbits.BRGH   = 0; 

    /* calculate brg */
    UartBrg = (int)(((float)PbusClock/(16 * baud) - 1) + 0.5 );
    U4BRG = UartBrg;

    U4STAbits.UTXEN    = 1;
    U4STAbits.URXEN    = 1;
    U4MODEbits.ON      = 1; 
    
    // configure UART interrupt
    IPC9bits.U4IP = 1;
    IPC9bits.U4IS = 3;

	IFS2bits.U4RXIF = 0; //Clear the Uart4 interrupt flag.
    IFS2bits.U4TXIF = 0; //Clear the Uart4 trasmission flag
    
    IEC2bits.U4RXIE = 1; // enable RX interrupt
    
}

int putU4(int c)
{
    while(U4STAbits.UTXBF == 1);
    U4TXREG = c;
}

void putU4_string(char szData[])
{
    char *pData = szData;
    while(*pData)
    {
        putU4((*(pData++)));
    }
}
