/*
 * Title: Timer.c
 * Description: Timer configuration function and Timer control
 * Author: CTa
 * Date: 09.10.2021
*/

#include <proc/p32mx370f512l.h>  // or p32xxxx.h

extern int timer2IF;   // external timer count in main.c
int counter = 0;

void Timer2_init(void)
{
    T2CONbits.ON = 0;   // Disable Timer2
    T2CONbits.T32 = 0;  // not use 32-bit mode - use 16-bit mode
    T2CONbits.TCKPS = 0b111; //select prescaler 256
    T2CONbits.TCS = 0;  //select internal peripheral clock
    TMR2 = 0;           //Clear TMR2 register
    //(500*10^-3)/((1/20000000)*256)
    PR2 = 39062;        // Set PR2 register - Calculated to have 0.5s - Change it for new delays (See also PBCLK due to #pragma)
    IPC2bits.T2IP = 1; // priority IPC2bits Timer2
    IPC2bits.T2IS = 0; // sub?priority Timer2
    
    IEC0bits .T2IE = 1; // interrupt Timer2 enable
    T2CONbits .ON = 1; // Enable Timer2
}

void ResetTimer2(int c){
    timer2IF = 0;
    counter = c;
}

#pragma interrupt Timer2Handler IPL1AUTO vector 8 
void Timer2Handler(void)
{
    if(counter >= 40){
        timer2IF = 1;
    }
    IFS0bits.T2IF = 0;
    counter++;
}
