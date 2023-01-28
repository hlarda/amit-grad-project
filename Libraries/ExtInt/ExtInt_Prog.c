/*
 * ExtInt_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "ExtInt_Interface.h"
#include "ExtInt_Private.h"

void (*ExtInt0_CallBack)(void);
void (*ExtInt1_CallBack)(void);
void (*ExtInt2_CallBack)(void);

void M_ExtInt_Void_ExtIntInit(u8 Copy_U8_ExtIntChannel)
{
	switch(Copy_U8_ExtIntChannel)
	{
	case INT0_CHANNEL:
#if   EXTINT0_SENSE_CONTROL_MODE   ==   RISING_EDGE
		SET_BIT(MCUCR_REG,ISC01_BIT);
		SET_BIT(MCUCR_REG,ISC00_BIT);
#elif EXTINT0_SENSE_CONTROL_MODE   ==   FALLING_EDGE
		SET_BIT(MCUCR_REG,ISC01_BIT);
		CLR_BIT(MCUCR_REG,ISC00_BIT);
#elif EXTINT0_SENSE_CONTROL_MODE   ==   LOW_LEVEL
		CLR_BIT(MCUCR_REG,ISC01_BIT);
		CLR_BIT(MCUCR_REG,ISC00_BIT);
#elif EXTINT0_SENSE_CONTROL_MODE   ==   LOGICAL_CHANGE
		CLR_BIT(MCUCR_REG,ISC01_BIT);
		SET_BIT(MCUCR_REG,ISC00_BIT);
#endif
		// to enable local int
		SET_BIT(GICR_REG,INT0_BIT);
		break;
	case INT1_CHANNEL:

		break;
	case INT2_CHANNEL:

		break;
	default: break;
	}
}

void M_ExtInt_Void_SetCallBack(u8 Copy_U8_ExtIntChannel,void(*Copy_Ptr)(void))
{
	switch(Copy_U8_ExtIntChannel)
	{
	case INT0_CHANNEL:	ExtInt0_CallBack = Copy_Ptr; break;
	case INT1_CHANNEL:	ExtInt1_CallBack = Copy_Ptr; break;
	case INT2_CHANNEL:	ExtInt2_CallBack = Copy_Ptr; break;
	default:                                         break;
	}
}

ISR(INT0_vect)
{
	ExtInt0_CallBack();
}
ISR(INT1_vect)
{
	ExtInt1_CallBack();
}
ISR(INT2_vect)
{
	ExtInt2_CallBack();
}
