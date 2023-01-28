/*
 * I2C_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "I2C_Config.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"

void M_I2C_Void_I2CInit(void)
{
#if   I2C_MODE   ==   I2C_MASTER
	/* TO SELECT FSCL -> 400 KHZ */
	TWBR_REG = 12;
#elif I2C_MODE   ==   I2C_SLAVE
	TWAR_REG = (I2C_SLAVE_ADDRESS << 1) | I2C_GENERAL_CALL;
#endif
	/* TO ENABLE 12C CIRCUIT */
	SET_BIT(TWCR_REG,TWEN_BIT);
}
void M_I2C_Void_StartCondition(void)
{
	SET_BIT(TWCR_REG,TWSTA_BIT);
	SET_BIT(TWCR_REG,TWINT_BIT);          /* TO CLEAR THE FLAG */
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
	while((TWSR_REG & 0xF8) != I2C_START_CONDITION_HAS_BEEN_TRANSMITTED);
}
void M_I2C_Void_StopCondition(void)
{
	SET_BIT(TWCR_REG,TWSTO_BIT);
	SET_BIT(TWCR_REG,TWINT_BIT);          /* TO CLEAR THE FLAG */
}
void M_I2C_Void_RepeatedStart(void)
{
	SET_BIT(TWCR_REG,TWSTA_BIT);
	SET_BIT(TWCR_REG,TWINT_BIT);          /* TO CLEAR THE FLAG */
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
}
void M_I2C_Void_SendSlaveAddressWrite(u8 Copy_U8_SlaveAddress)
{
	TWDR_REG = (Copy_U8_SlaveAddress << 0x01);
	SET_BIT(TWCR_REG,TWINT_BIT);          /* TO CLEAR THE FLAG */
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
}
void M_I2C_Void_SendSlaveAddressRead(u8 Copy_U8_SlaveAddress)
{
	TWDR_REG = (Copy_U8_SlaveAddress << 0x01) | 0x01;
	CLR_BIT(TWCR_REG,TWSTA_BIT);                                            /*     +    */
	SET_BIT(TWCR_REG,TWINT_BIT);          /* TO CLEAR THE FLAG */
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
}
void M_I2C_Void_SendByte(u8 Copy_U8_Data)
{
	u32 Local_U32_Counter = 0;
	TWDR_REG = Copy_U8_Data;
	CLR_BIT(TWCR_REG,TWSTA_BIT);                                           /*     +    */
	SET_BIT(TWCR_REG,TWINT_BIT);          /* TO CLEAR THE FLAG */
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
	while(Local_U32_Counter < 2000000)
	{
		Local_U32_Counter++;
		if((TWSR_REG & 0xF8) == I2C_DATA_BYTE_TRANSMITTED_ACK_REC)
		{
			break;
		}
	}
}
u8   M_I2C_U8_ReadByte(void)
{
	CLR_BIT(TWCR_REG,TWSTA_BIT);                                          /*     +    */
	SET_BIT(TWCR_REG,TWINT_BIT);          /* TO CLEAR THE FLAG */
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
	return TWDR_REG;
}
