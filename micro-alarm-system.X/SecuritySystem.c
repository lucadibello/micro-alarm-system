#include <stdio.h>
#include <p32xxxx.h>

int securitySystemEnabled = 0;

/**
 * Check if the security system is enabled
 * @return 1 is the security system is enabled, otherwise 0
 */
int SECURITY_isSecuritySystemEnabled () {
    return securitySystemEnabled;
}

/**
 * Enable security system
 */
void SECURITY_enable() {
    securitySystemEnabled = 1;
}

/**
 * Disable security system
 */
void SECURITY_disable() {
    securitySystemEnabled = 0;
}