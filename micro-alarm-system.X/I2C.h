void I2C_Init();
unsigned char I2C_Read (unsigned char slaveAddress, unsigned char* data, unsigned char nBytes);
unsigned char I2C_Write(unsigned char slaveAddress, unsigned char* dataBuffer, unsigned char bytesNumber, unsigned char stopBit);
void I2C_Stop();
