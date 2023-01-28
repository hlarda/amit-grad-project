/*
 * Servo_Prog.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "Servo_Interface.h"

void H_Servo_Void_ServoInit(void)
{
	M_Timer_Void_PWMInit(TIMER1_CHANNEL);
}
void H_Servo_Void_ServoSetAngel(u8 Copy_U8_ServoAngel)
{
	f32 Local_F32_DutyCycle = (((f32)Copy_U8_ServoAngel / 180.0 ) * 5.0) + 5;
	M_Timer_Void_PWMSetDutyCycle(TIMER1_CHANNEL,Local_F32_DutyCycle);
}
void H_Servo_Void_ServoStart(void)
{
	M_Timer_Void_PWMStart(TIMER1_CHANNEL);
}
void H_Servo_Void_ServoStop(void)
{
	M_Timer_Void_PWMStop(TIMER1_CHANNEL);
}
