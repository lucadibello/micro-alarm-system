#include <stdio.h>
#include <p32xxxx.h>
#include "Speaker.h"
#include "Accelerometer.h"
#include "UART.h" // FIXME: Temporaneo, solo per debug dell'accelerometro 

int securitySystemEnabled = 0;

void SECURITY_Init () {
    // Initialize Accelerometer
    ACCELEROMETER_Init();
}

/**
 * Check if the security system is enabled
 * @return 1 is the security system is enabled, otherwise 0
 */
int SECURITY_isSecuritySystemEnabled () {
    return securitySystemEnabled;
}

void SECURITY_startAlarm() {
    SPEAKER_Start();
}

void SECURITY_stopAlarm() {
    SPEAKER_Stop();
}

/**
 * Enable security system
 */
void SECURITY_enable() {
    // Enable security system
    securitySystemEnabled = 1;
    
    // Start reading accelerometer
    float rgACLGVals[3];
    unsigned int baseCnt = 0;
    char str[80];
    while(1)
    {
       //perform ACL readings only once in a while, to be able to visualize the results
        if(++baseCnt == 400000)
        {
            baseCnt = 0;        
            ACCELEROMETER_ReadGValues(rgACLGVals);
            //display on the LCD screen the Y and Z values, second row
            sprintf(str, "X:%f Y:%f Z:%f\n", rgACLGVals[0], rgACLGVals[1], rgACLGVals[2]);            
            putU4_string(str);     
        }
    }
    
    // FIXME: start buzzer only when board moved
    SECURITY_startAlarm();
}

/**
 * Disable security system
 */
void SECURITY_disable() {
    securitySystemEnabled = 0;
    
    // stop buzzing
    SECURITY_stopAlarm();
}