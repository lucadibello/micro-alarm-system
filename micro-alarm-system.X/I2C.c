#include <stdio.h>
#include <p32xxxx.h>
#include "I2C.h"

#define PB_CLK 40000000
#define I2C_WAIT_TIMEOUT 0x0FFF

void I2C_Init(unsigned int frequency) {
    I2C1CON = 0;            //Clear the content of I2C1CON register 
    I2C1BRG = PB_CLK / (2 * frequency) - 2; // setup I2C communication frequency
    I2C1CONbits.ON = 1; // turn on the I2C1 module
    I2C1CONbits.ACKEN = 1; // send ACKDT
}

unsigned char I2C_Read(unsigned char slaveAddress,
                    unsigned char* dataBuffer,
                    unsigned char bytesNumber)
{
    unsigned char status = 0;
    unsigned char acknowledge = 0;
    unsigned char byte = 0;
    int cnt_timeout;
    I2C1CONbits.RSEN = 1;            // Initiate a start condition
    cnt_timeout = 0;
    while(I2C1CONbits.RSEN && (++cnt_timeout < I2C_WAIT_TIMEOUT));         //Wait for start condition to complete
    if(cnt_timeout >= I2C_WAIT_TIMEOUT)
    {
        return 0xFE;    // timeout error
    }
    I2C1TRN = (slaveAddress << 1) + 1;
    cnt_timeout = 0;
    while(I2C1STATbits.TRSTAT && (++cnt_timeout < I2C_WAIT_TIMEOUT));     // Wait for reception to complete
    if(cnt_timeout >= I2C_WAIT_TIMEOUT)
    {
        return 0xFE;    // timeout error
    }
    acknowledge = I2C1STATbits.ACKSTAT;
    if(acknowledge == 0)            //Acknowledge was received
    {
        for(byte = 0; byte < bytesNumber; byte++)
        {
           I2C1CONbits.RCEN = 1;       //Enable receive mode for I2C
            if(byte == (bytesNumber - 1))
            {
                I2C1CONbits.ACKDT = 1;
            }
            else
            {
                I2C1CONbits.ACKDT = 0;
            }
            cnt_timeout = 0;
            while(I2C1CONbits.RCEN && (++cnt_timeout < I2C_WAIT_TIMEOUT));    //Wait for reception to complete
            if(cnt_timeout >= I2C_WAIT_TIMEOUT)
            {
                return 0xFE;    // timeout error
            }
            dataBuffer[byte] = I2C1RCV;
            I2C1CONbits.ACKEN = 1;
            cnt_timeout = 0;
            while(I2C1CONbits.ACKEN && (++cnt_timeout < I2C_WAIT_TIMEOUT));
            if(cnt_timeout >= I2C_WAIT_TIMEOUT)
            {
                return 0xFE;    // timeout error
            }
        }
    }
    else
    {
        status = 0xFF;
    }
    I2C1CONbits.ACKEN = 1;          //Initiate Acknowledge sequence on SDAx and SCLx pins and transmit ACKDT data bit. Wait for Acknowledge sequence to complete 
    I2C1CONbits.PEN = 1;            //Initiate a stop condition 
    cnt_timeout = 0;
    while(I2C1CONbits.PEN && (++cnt_timeout < I2C_WAIT_TIMEOUT));         //Wait for stop condition to complete
    if(cnt_timeout >= I2C_WAIT_TIMEOUT)
    {
        return 0xFE;    // timeout error
    }

    return status;
}

unsigned char I2C_Write(unsigned char slaveAddress,
                        unsigned char* dataBuffer,
                        unsigned char bytesNumber,
                        unsigned char stopBit) 
{
    unsigned char status = 0;
    unsigned char acknowledge = 0;
    unsigned char byte = 0;
    
    int cnt_timeout;
    I2C1CONbits.SEN = 1; //Initiate a start condition
    cnt_timeout = 0;
    while(I2C1CONbits.SEN); // Wait for start condition to complete
    I2C1TRN = slaveAddress << 1; //RW bit set to 0
    cnt_timeout = 0;
    while(I2C1STATbits.TRSTAT); //Wait for transmission to complete 
    acknowledge = I2C1STATbits.ACKSTAT;
    if(acknowledge == 0) //Acknowledge was received 
    {
        for(byte = 0; byte < bytesNumber; byte++)
        {
            I2C1TRN = dataBuffer[byte];
            cnt_timeout = 0;
            while(I2C1STATbits.TRSTAT); // Wait for transmission to complete 
        }
    }
    else
    {
        status = 0xFF;
    }
    if(stopBit)
    {
        I2C1CONbits.PEN = 1; //Initiate a stop condition
        cnt_timeout = 0;
        while(I2C1CONbits.PEN); //Wait for stop condition to complete
    }

    return status;
} 

void I2C_Stop() {
    // Turn off I2C module
    I2C1CONbits.ON = 0;
}

