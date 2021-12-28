#include <stdio.h>
#include <p32xxxx.h>
#include "Speaker.h"

int securitySystemEnabled = 0;

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
    securitySystemEnabled = 1;
    
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