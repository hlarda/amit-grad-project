/*
 * ExtInt_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_EXTINT_EXTINT_INTERFACE_H_
#define MCAL_EXTINT_EXTINT_INTERFACE_H_

#include "ExtInt_Config.h"
#include "BitMath.h"
#include "STD.h"
#include <avr/interrupt.h>

#define INT0_CHANNEL         0
#define INT1_CHANNEL         1
#define INT2_CHANNEL         2

void M_ExtInt_Void_ExtIntInit(u8);
void M_ExtInt_Void_SetCallBack(u8,void(*)(void));

#endif /* MCAL_EXTINT_EXTINT_INTERFACE_H_ */
