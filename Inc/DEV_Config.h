#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

#include <stdint.h>
#include <stdio.h>
#include <math.h>


#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/**
* IIC 
**/
#define IIC_Addr					    0x73<<1

/**
 * delay x ms
**/
#define DEV_Delay_ms(__xms)	HAL_Delay(__xms)

/*-----------------------------------------------------------------------------*/
void DEV_Set_I2CAddress(UBYTE Add);
void DEV_I2C_WriteByte(UBYTE add_, UBYTE data_);
void DEV_I2C_WriteWord(UBYTE add_, UWORD data_);
UBYTE DEV_I2C_ReadByte(UBYTE add_);
UWORD DEV_I2C_ReadWord(UBYTE add_);


#endif
