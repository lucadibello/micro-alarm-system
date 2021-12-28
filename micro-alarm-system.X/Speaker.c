#include <stdio.h>
#include <p32xxxx.h>
#include "Speaker.h"

#define PB_FRQ 40000000
#define TMR_FREQ_SINE 48000 // 48 kHz
#define RGSIN_SIZE  (sizeof(rgSinSamples) / sizeof(rgSinSamples[0]))


// This array contains the values that implement one syne period, over 25 samples. 
// They are generated using this site: 
// http://www.daycounter.com/Calculators/Sine-Generator-Calculator.phtml
unsigned short rgSinSamples[] = {
    256,320,379,431,472,499,511,507,488,453,
    406,350,288,224,162,106, 59, 24,  5,  1,
    13, 40, 81,133,192
};

// global variables that store audio buffer position and size
int cntAudioBuf, idxAudioBuf;

/* Define UART interrupt handler */
#pragma interrupt TimerHandler IPL7AUTO vector 12
void TimerHandler (void);

void TimerHandler () {
    OC1RS = 4*rgSinSamples[(++idxAudioBuf) % cntAudioBuf];
    IFS0bits.T3IF = 0;      // clear Timer3 interrupt flag
}

void SPEAKER_ConfigurePins()
{
    TRISBbits.TRISB14 = 0; // Output
    RPB14R = 0x0C; // MAPPING 1100 = OC1 
    ANSELBbits.ANSB14 = 0; // Digital
}

void SPEAKER_Init () {
    // Stop timer and speaker
    SPEAKER_Stop();
    
    // Configure pins
    SPEAKER_ConfigurePins();
    
    // Setup timer 3
    PR3 = (int)((float)((float)PB_FRQ/TMR_FREQ_SINE) + 0.5);
    TMR3 = 0;
    T3CONbits.TCKPS = 0;     // 1:1 prescaler
    T3CONbits.TGATE = 0;     // disable gated input (default)
    T3CONbits.TCS = 0;       // PCBLK input (default)
    // T3CONbits.ON = 1;        // turn on Timer3
    
    // Setup Speaker
    OC1CONbits.ON = 0;       // Turn off OC1.
    OC1CONbits.OCM = 6;      // PWM mode OC1
    OC1CONbits.OCTSEL = 1;   // Timer3 is the clock source for this Output Compare module
    // OC1CONbits.ON = 1;       // Start the OC1
    
    // Setup interrupt
    IPC3bits.T3IP = 7;      // interrupt priority
    IPC3bits.T3IS = 3;      // interrupt subpriority
    IEC0bits.T3IE = 1;      // enable Timer3 interrupt    
    IFS0bits.T3IF = 0;      // clear Timer3 interrupt flag
    
    // Load first value
    idxAudioBuf = 0;
    cntAudioBuf = RGSIN_SIZE;

    // load first value
    OC1RS = rgSinSamples[0];
}

void SPEAKER_Start(int syneSample) {
    T3CONbits.ON = 1;
     OC1CONbits.ON = 1;
}

void SPEAKER_Stop() {
   T3CONbits.ON = 0; // Turn off timer 3
   OC1CONbits.ON = 0; // Turn off OC1
}