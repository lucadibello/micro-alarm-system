#define ACCELEROMETER_I2C_ADDRESS 0x1D
#define ACCELEROMETER_CTRL_REGISTER 0x2A
#define ACCELEROMETER_DEVICE_ID 0x0D 
#define ACL_OUT_X_MSB       0x01 
#define ACL_XYZDATACFG      0x0

void ACCELEROMETER_Init();
void ACCELEROMETER_ConfigurePins();
unsigned char ACCELEROMETER_SetRegister(unsigned char bAddress, unsigned char bValue);
unsigned char ACCELEROMETER_GetRegister(unsigned char bAddress);
unsigned char ACCELEROMETER_GetDeviceID();
unsigned char ACCELEROMETER_SetRange(unsigned char bRange);
void ACCELEROMETER_ReadRawValues(unsigned char *rgRawVals);
void ACCELEROMETER_ReadGValues(float *rgGVals);
