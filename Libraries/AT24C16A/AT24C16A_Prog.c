/*
 * AT24C16A_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "AT24C16A_Interface.h"

void H_AT24C16A_Void_EEPROMInit(void)
{
	M_I2C_Void_I2CInit();
}
void H_AT24C16A_Void_EEPROMWrite(u8 Copy_U8_PageNumber,u8 Copy_U8_ByteNumber,u8 Copy_U8_Data)
{
	M_I2C_Void_StartCondition();
	M_I2C_Void_SendSlaveAddressWrite(0x50 | Copy_U8_PageNumber);
	M_I2C_Void_SendByte(Copy_U8_ByteNumber);         /* TO SEND BYTE NUMBER */
	M_I2C_Void_SendByte(Copy_U8_Data);               /* TO SEND DATA        */
	M_I2C_Void_StopCondition();
}
u8   H_AT24C16A_Void_EEPROMRead(u8 Copy_U8_PageNumber,u8 Copy_U8_ByteNumber)
{
	u8 Local_U8_Data = 0;
	M_I2C_Void_StartCondition();
	M_I2C_Void_SendSlaveAddressWrite(0x50 | Copy_U8_PageNumber);
	M_I2C_Void_SendByte(Copy_U8_ByteNumber);         /* TO SEND BYTE NUMBER */
	M_I2C_Void_RepeatedStart();
	M_I2C_Void_SendSlaveAddressRead(0x50 | Copy_U8_PageNumber);
	Local_U8_Data = M_I2C_U8_ReadByte();
	M_I2C_Void_StopCondition();
	return Local_U8_Data;
}





