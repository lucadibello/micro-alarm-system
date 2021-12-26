void AUTH_changePassword (char newpsw[255]);
int AUTH_isSystemActive();
char * AUTH_getPassword();
int AUTH_checkPassword(char * psw);
void AUTH_unlockSystem();
void AUTH_lockSystem();