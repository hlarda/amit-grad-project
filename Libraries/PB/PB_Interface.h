/*
 * PB_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_PB_PB_INTERFACE_H_
#define HAL_PB_PB_INTERFACE_H_

#include "STD.h"
#include "PB_Config.h"
#include "DIO_Interface.h"
#include <util/delay.h>

#define PB0                  0
#define PB1                  1
#define PB2                  2



#define ACTIVE_LOW     1
#define ACTIVE_HIGH    2

#if   ACTIVE_HIGH  == ACTIVE_HIGH
#define PRESSED              1
#define RELEASED             0
#elif ACTIVE_HIGH  == ACTIVE_LOW
#define PRESSED              0
#define RELEASED             1
#endif

void H_PB_Void_PBInit(u8);
u8   H_PB_U8_PBRead(u8);

#endif /* HAL_PB_PB_INTERFACE_H_ */
