#include <p32xxxx.h>
#include <stdio.h>
#include "I2C.h"
#include "Accelerometer.h"
#include "UART.h"

float fGRangeLSB;   // global variable used to pre-compute the value in g corresponding to each count of the raw value

/**
 * Initialize Accelerator (Pins + I2C communication)
 */
void ACCELEROMETER_Init()
{
    ACCELEROMETER_ConfigurePins(); // Setup pins
    I2C_Init(100000); // Setup I2C module for communication
    ACCELEROMETER_SetRange(0); // +/- 2g
    ACCELEROMETER_SetRegister(ACCELEROMETER_CTRL_REGISTER, 1);        // Output data rate at 800Hz, no auto wake, no auto scale adjust, no fast read mode
}

/**
 * Configure Accelerator module pins
 */
void ACCELEROMETER_ConfigurePins()
{
    // Configure ACL signals as digital input.
    TRISGbits.TRISG0 = 1;
}


unsigned char ACCELEROMETER_SetRegister(unsigned char bAddress, unsigned char bValue)
{
    unsigned char rgVals[2], bResult;
    rgVals[0] = bAddress;       // register address
    rgVals[1] = bValue;         // register value
    
    // Send data
    bResult = I2C_Write(ACCELEROMETER_I2C_ADDRESS, rgVals, 2, 1);
    
    // Return result
    return bResult;
}

unsigned char ACCELEROMETER_GetRegister(unsigned char bAddress)
{
    unsigned char bResult;
    I2C_Write(ACCELEROMETER_I2C_ADDRESS, &bAddress, 1, 0);
    I2C_Read(ACCELEROMETER_I2C_ADDRESS, &bResult, 1);

    return bResult;
}

unsigned char ACCELEROMETER_GetDeviceID()
{
    return ACCELEROMETER_GetRegister(ACCELEROMETER_DEVICE_ID);
}

unsigned char ACCELEROMETER_SetRange(unsigned char bRange)
{
    unsigned char bResult, bVal;

    //Set accelerometer to standby mode
    ACCELEROMETER_SetRegister(ACCELEROMETER_CTRL_REGISTER, (ACCELEROMETER_GetRegister(ACCELEROMETER_CTRL_REGISTER) & 0xFE));

    //Change accelerometer Dynamic Range
    bVal = ACCELEROMETER_GetRegister(ACL_XYZDATACFG); // get old value of the register
    bVal &= 0xFC; // mask out the 2 LSBs
    bVal |= bRange;  // set the 2 LSBs according to the range value
    bResult = ACCELEROMETER_SetRegister(ACL_XYZDATACFG, bVal);

    // set fGRangeLSB according to the selected range
    bRange &= 3;
    unsigned char bValRange = 1<<(bRange + 2);
    fGRangeLSB = ((float)bValRange)/(1<<12);     // the range is divided to the resolution corresponding to number of bits (12)

    //Set accelerometer back to active mode
    ACCELEROMETER_SetRegister(ACCELEROMETER_CTRL_REGISTER, (ACCELEROMETER_GetRegister(ACCELEROMETER_CTRL_REGISTER) | 0x01));

    return bResult;
}

void ACCELEROMETER_ReadRawValues(unsigned char *rgRawVals)
{
    unsigned char bVal = ACL_OUT_X_MSB;

    I2C_Write(ACCELEROMETER_I2C_ADDRESS, &bVal, 1, 0);
    I2C_Read(ACCELEROMETER_I2C_ADDRESS, rgRawVals, 6);
}

float ACCELEROMETER_ConvertRawToValueG(unsigned char *rgRawVals)
{
    // Convert the accelerometer value to G's.
    // With 12 bits measuring over a +/- ng range we can find how to convert by using the equation:
    // Gs = Measurement Value * (G-range/(2^12))

    unsigned short usReading = (((unsigned short)rgRawVals[0]) << 4) + (rgRawVals[1] >> 4);
    // extend sign from bit 12 bits to 16 bits
    if(usReading & (1<<11))
    {
        usReading |= 0xF000;
    }
  // fGRangeLSB is pre-computed in ACL_SetRange
    float fResult = ((float)((short)usReading)) * fGRangeLSB;
    return fResult;
}


void ACCELEROMETER_ReadGValues(float *rgGVals)
{
    unsigned char rgRawVals[6];
    ACCELEROMETER_ReadRawValues(rgRawVals);
    rgGVals[0] = ACCELEROMETER_ConvertRawToValueG(rgRawVals);
    rgGVals[1] = ACCELEROMETER_ConvertRawToValueG(rgRawVals + 2);
    rgGVals[2] = ACCELEROMETER_ConvertRawToValueG(rgRawVals + 4);
}