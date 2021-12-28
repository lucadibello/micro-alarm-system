#include <stdio.h>
#include <p32xxxx.h>
#include "I2C.h"

void I2C_Init() {
    // I2CBRG = [1/(2*Fsck) ? PGD]*Pblck ? 2
    I2C1BRG = 390; 
    // Fsck is the freq (100 kHz here), PGD = 104 ns
    
    I2C1CONbits.ON = 1; // turn on the I2C1 module 
}

void I2C_Read (unsigned char slaveAddress,
        unsigned char* data,
        unsigned char nBytes)
{
    // Send a restart command to initiate a start condition
    _i2c_master_restart();
    
    
    // Load slave address into memory + add read flag-bit at the end
    _i2c_assign_slave_address(slaveAddress, 1);
    
    // Check for acknowledge
    if (I2C1STATbits.ACKSTAT) {
        // acknowledge received
        
        // read data sent by slave
        for (int byte = 0; byte < nBytes; byte++) {
            I2C1CONbits.RCEN = 1; //Enable receive mode for I2C
            
            // Wait for reception to complete
            while (I2C1CONbits.RCEN) {}
           
            // Save received bit into data buffer
            data[byte] = I2C1RCV;
            
            // Send ACKDT
            I2C1CONbits.ACKEN = 1;
            
            // Send ACK
            _i2c_master_send_ack(byte == (nBytes - 1) ? 1 : 0);
        }
    }
    
    //Initiate Acknowledge sequence on SDAx and SCLx pins and transmit ACKDT data bit. Wait for Acknowledge sequence to complete
    I2C1CONbits.ACKEN = 1;
    
    // Initiate stop condition
    _i2c_master_stop();
}

void I2C_Stop() {
    // Turn off I2C module
    I2C1CONbits.ON = 0;
}

void _i2c_master_restart() {
    I2C1CONbits.RSEN = 1; // send a restart
    while(I2C1CONbits.RSEN) {} // wait for the restart to clear 
}

void _i2c_assign_slave_address(unsigned char slaveAddress, int isReading) {
    if (isReading) {
        // assign slave + read bit (1)
        I2C1TRN = (slaveAddress << 1) + 1;
    } else {
        // assign slave + write bit (0)
        I2C1TRN = slaveAddress << 1;
    }
    
    // wait for reception
    while(I2C1STATbits.TRSTAT) {}
}

char _i2c_master_recieve() {
    I2C1CONbits.RCEN = 1; // start receiving data 
    while (!I2C1STATbits.RBF) {} // wait to receive  
    return I2C1RCV; // read and return the data
}

void _i2c_master_send_ack(int val)
{   
    // sends ACK = 0 (slave should send another byte)
    // or NACK = 1 (no more bytes requested from slave ) 
    I2C1CONbits.ACKDT = val ; // store ACK/NACK in ACKDT 
    I2C1CONbits.ACKEN = 1; // send ACKDT 
    while(I2C1CONbits.ACKEN) {} // wait for ACK/NACK to be sent
}

void _i2c_master_stop() {
    I2C1CONbits.PEN = 1; // comm is complete and master relinquishes bus
    while(I2C1CONbits.PEN) {} // wait for STOP to complete 
}
