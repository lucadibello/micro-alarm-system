void I2C_Init();
void I2C_Read (unsigned char slaveAddress, unsigned char* data, unsigned char nBytes);
void I2C_Stop();
void _i2c_master_restart();
void _i2c_assign_slave_address(unsigned char slaveAddress, int isReading);
char _i2c_master_recieve();
void _i2c_master_send_ack(int val);
void _i2c_master_stop();
