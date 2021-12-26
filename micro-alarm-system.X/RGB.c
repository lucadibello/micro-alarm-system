#include <stdio.h>
#include <p32xxxx.h>

/**
 * Setup RGB led
 */
void RGB_SetupLeds () {
    // Configure RED led
    RPD2R = 0; // No remappable
    TRISDbits.TRISD2 = 0; // output
    ANSELDbits.ANSD2 = 0; // digital
            
    // Configure GREEN led
    RPD12R = 0; // No remappable
    TRISDbits.TRISD12 = 0; // output
    // already digital
    
    
    // Configure BLUE led
    RPD3R = 0; // No remappable
    TRISDbits.TRISD3 = 0; // output
    ANSELDbits.ANSD3 = 0; // digital
}

/**
 * Set RGB led to RED
 */
void RGB_setRed() {
    LATDbits.LATD2 = 1; // turn on red
    LATDbits.LATD12 = 0; // turn off green
    LATDbits.LATD3 = 0; // turn off blue
}

/**
 * Set RGB led to GREEN
 */
void RGB_setGreen() {
    LATDbits.LATD2 = 0; // turn on red
    LATDbits.LATD12 = 1; // turn off green
    LATDbits.LATD3 = 0; // turn off blue
}

/**
 * Set RGB led to BLUE
 */
void RGB_setBlue() {
    LATDbits.LATD2 = 0; // turn on red
    LATDbits.LATD12 = 0; // turn off green
    LATDbits.LATD3 = 1; // turn off blue
}