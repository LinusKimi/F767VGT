#include "DEV_Config.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

UWORD IIC_Addr_t = IIC_Addr; 

void DEV_Set_I2CAddress(UBYTE add_)
{
	IIC_Addr_t = add_;
}

/******************************************************************************
function:	
	I2C Write and Read
******************************************************************************/
void DEV_I2C_WriteByte(UBYTE add_, UBYTE data_)
{
	UBYTE Buf[1] = {0};
	Buf[0] = data_;
	HAL_I2C_Mem_Write(&hi2c1, IIC_Addr_t, add_, I2C_MEMADD_SIZE_8BIT, Buf, 1, 0x10);
}

void DEV_I2C_WriteWord(UBYTE add_, UWORD data_)
{
	UBYTE Buf[2] = {0};
	Buf[0] = data_ >> 8; 
	Buf[1] = data_;
	HAL_I2C_Mem_Write(&hi2c1, IIC_Addr_t, add_, I2C_MEMADD_SIZE_8BIT, Buf, 2, 0x10);
}

UBYTE DEV_I2C_ReadByte(UBYTE add_)
{
	UBYTE Buf[1]={add_};
	HAL_I2C_Mem_Read(&hi2c1, IIC_Addr_t, add_, I2C_MEMADD_SIZE_8BIT, Buf, 1, 0x10);
	return Buf[0];
}

UWORD DEV_I2C_ReadWord(UBYTE add_)
{
    UBYTE Buf[2]={0, 0};
		HAL_I2C_Mem_Read(&hi2c1, IIC_Addr_t, add_, I2C_MEMADD_SIZE_8BIT, Buf, 2, 0x10);
    return ((Buf[1] << 8) | (Buf[0] & 0xff));
}


