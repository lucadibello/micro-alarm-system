#include <stdio.h>
#include <string.h>
#include <p32xxxx.h>
#include "Speaker.h"
#include "Accelerometer.h"
#include "UART.h"  
#include "Logger.h"
#include "Timer.h"
#include "MenuHandler.h"


extern int timer2IF;
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
    
    ACCELEROMETER_ReadGValues(rgACLGVals);
    float threshold = 0.1;
    float xBase = abs(rgACLGVals[0]);
    float yBase = abs(rgACLGVals[1]);
    float zBase = abs(rgACLGVals[2]);
    
    int attivo = 1;
    
    while(attivo)
    {
       //perform ACL readings only once in a while, to be able to visualize the results
        if(++baseCnt == 400000)
        {
            baseCnt = 0;        
            ACCELEROMETER_ReadGValues(rgACLGVals);
            if (abs(abs(rgACLGVals[0]) - xBase) > threshold || abs(abs(rgACLGVals[1]) - yBase) > threshold || abs(abs(rgACLGVals[2]) - zBase) > threshold) {
                insert("Intrusione rilevata");
                SECURITY_startAlarm();
                ResetTimer2(30);
                while(!timer2IF);
            } else {
               SECURITY_stopAlarm(); 
            }   
        }
    }
}

/**
 * Disable security system
 */
void SECURITY_disable() {
    securitySystemEnabled = 0;
    
    // stop buzzing
    SECURITY_stopAlarm();
}