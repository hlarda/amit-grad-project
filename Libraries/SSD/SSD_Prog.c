/*
 * SSD_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "SSD_Interface.h"

void H_SSD_Void_SSDInit()
{
	M_DIO_Void_SetPinDirection(SSD_A_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_B_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_C_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_D_PIN,OUTPUT);

	M_DIO_Void_SetPinDirection(SSD1_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD2_EN_PIN,OUTPUT);
}
void H_SSD_Void_SSDDisplay(u8 Copy_U8_Num)
{
	u8 Local_U8_Ones = Copy_U8_Num % 10;
	u8 Local_U8_Tens = Copy_U8_Num / 10;
	u16 Local_U16_Counter =0;
	for(Local_U16_Counter=0;Local_U16_Counter<500;Local_U16_Counter++)
	{
		M_DIO_Void_SetPinValue(SSD_A_PIN,GET_BIT(Local_U8_Ones,0));
		M_DIO_Void_SetPinValue(SSD_B_PIN,GET_BIT(Local_U8_Ones,1));
		M_DIO_Void_SetPinValue(SSD_C_PIN,GET_BIT(Local_U8_Ones,2));
		M_DIO_Void_SetPinValue(SSD_D_PIN,GET_BIT(Local_U8_Ones,3));

		M_DIO_Void_SetPinValue(SSD2_EN_PIN,HIGH);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD2_EN_PIN,LOW);

		M_DIO_Void_SetPinValue(SSD_A_PIN,GET_BIT(Local_U8_Tens,0));
		M_DIO_Void_SetPinValue(SSD_B_PIN,GET_BIT(Local_U8_Tens,1));
		M_DIO_Void_SetPinValue(SSD_C_PIN,GET_BIT(Local_U8_Tens,2));
		M_DIO_Void_SetPinValue(SSD_D_PIN,GET_BIT(Local_U8_Tens,3));

		M_DIO_Void_SetPinValue(SSD1_EN_PIN,HIGH);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD1_EN_PIN,LOW);
	}
}
