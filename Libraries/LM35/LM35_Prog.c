/*
 * LM35_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "LM35_Interface.h"

void H_LM35_Void_LM35Init(void)
{
	M_ADC_Void_ADCInit();
}
u16  H_LM35_U16_LM35Read(void)
{
	u16 Local_U16_Temp = (M_ADC_Void_ADCRead(LM35_PIN) * (u32)500) / 1023;
	return Local_U16_Temp;
}
