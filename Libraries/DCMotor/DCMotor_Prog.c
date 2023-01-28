/*
 * DCMotor_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "DCMotor_Interface.h"
#include "Timer_Interface.h"
#include "DIO_Interface.h"

void H_DCMotor_Void_DCMotorInit(void)
{
	M_Timer_Void_PWMInit(TIMER1_CHANNEL);
	M_DIO_Void_SetPinDirection(PC5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(PC6_PIN,OUTPUT);
}
void H_DCMotor_Void_DCMotorSetDirection(u8 Copy_MotorDirection)
{
	switch(Copy_MotorDirection)
	{
	case CW:
		M_DIO_Void_SetPinValue(PC5_PIN,LOW);
		M_DIO_Void_SetPinValue(PC6_PIN,HIGH);
		break;
	case ACW:
		M_DIO_Void_SetPinValue(PC6_PIN,LOW);
		M_DIO_Void_SetPinValue(PC5_PIN,HIGH);
		break;
	default:  break;
	}
}
void H_DCMotor_Void_DCMotorSetSpeed(u8 Copy_U8_MotorSpeed)
{
	M_Timer_Void_PWMSetDutyCycle(TIMER1_CHANNEL,Copy_U8_MotorSpeed);
}
void H_DCMotor_Void_DCMotorStart(void)
{
	M_Timer_Void_PWMStart(TIMER1_CHANNEL);
}
void H_DCMotor_Void_DCMotorStop(void)
{
	M_Timer_Void_PWMStop(TIMER1_CHANNEL);
}
