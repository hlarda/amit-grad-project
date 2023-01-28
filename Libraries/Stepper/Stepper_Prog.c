/*
 * Stepper_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "Stepper_Config.h"
#include <util/delay.h>
#include "DIO_Interface.h"

void H_Stepper_Void_StepperInit(void)
{
	M_DIO_Void_SetPinDirection(STEPPER_PIN_1,OUTPUT);
	M_DIO_Void_SetPinDirection(STEPPER_PIN_2,OUTPUT);
	M_DIO_Void_SetPinDirection(STEPPER_PIN_3,OUTPUT);
	M_DIO_Void_SetPinDirection(STEPPER_PIN_4,OUTPUT);
}
void H_Stepper_Void_StepperStart(u32 Copy_U32_Degrees)
{
	u32 Local_U32_Counter = 0;
	for(Local_U32_Counter=0;Local_U32_Counter < Copy_U32_Degrees;Local_U32_Counter++)
	{
		M_DIO_Void_SetPinValue(STEPPER_PIN_1,HIGH);
		M_DIO_Void_SetPinValue(STEPPER_PIN_2,LOW);
		M_DIO_Void_SetPinValue(STEPPER_PIN_3,LOW);
		M_DIO_Void_SetPinValue(STEPPER_PIN_4,LOW);
		_delay_ms(5);
		M_DIO_Void_SetPinValue(STEPPER_PIN_1,LOW);
		M_DIO_Void_SetPinValue(STEPPER_PIN_2,HIGH);
		M_DIO_Void_SetPinValue(STEPPER_PIN_3,LOW);
		M_DIO_Void_SetPinValue(STEPPER_PIN_4,LOW);
		_delay_ms(5);
		M_DIO_Void_SetPinValue(STEPPER_PIN_1,LOW);
		M_DIO_Void_SetPinValue(STEPPER_PIN_2,LOW);
		M_DIO_Void_SetPinValue(STEPPER_PIN_3,HIGH);
		M_DIO_Void_SetPinValue(STEPPER_PIN_4,LOW);
		_delay_ms(5);
		M_DIO_Void_SetPinValue(STEPPER_PIN_1,LOW);
		M_DIO_Void_SetPinValue(STEPPER_PIN_2,LOW);
		M_DIO_Void_SetPinValue(STEPPER_PIN_3,LOW);
		M_DIO_Void_SetPinValue(STEPPER_PIN_4,HIGH);
		_delay_ms(5);
	}
}
