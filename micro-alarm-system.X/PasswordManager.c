#include <p32xxxx.h>
#include <stdio.h>
#include <string.h>
#include "UART.h"

int active = 0;
char password[255];

/**
 * Check if user is authenticated.
 * @return 1 if user is authenticated, otherwise 0.
 */
int AUTH_isSystemActive() {
    return active;
}

/**
 * Unlock system.
 */
void AUTH_unlockSystem() {
    active = 1;
}

/**
 * Lock system.
 */
void AUTH_lockSystem () {
    active = 0;
}

/**
 * Change authentication password.
 * @param newpsw New authentication password
 */
void AUTH_changePassword (char newpsw[255]) {
    strcpy(password, newpsw);
}

/**
 * Get authentication password.
 * @return String representing the current authentication password
 */
char* AUTH_getPassword() {
    return password;
}

/**
 * Used to check if the passed password is valid.
 * @param psw Password to compare
 * @return 1 if the password match, otherwise 0
 */
int AUTH_checkPassword (char * psw) {
    return strcmp(password, psw) == 0 ? 1 : 0;
}