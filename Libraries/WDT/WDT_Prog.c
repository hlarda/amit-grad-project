/*
 * WDT_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "STD.h"
#include "BitMath.h"
#include "WDT_Interface.h"
#include "WDT_Private.h"

#define WDTCR_REG      *(volatile u8*)0x41


void M_WDT_Void_WDTInit(void)
{
	SET_BIT(WDTCR_REG,3);

	SET_BIT(WDTCR_REG,2);
	SET_BIT(WDTCR_REG,1);
	SET_BIT(WDTCR_REG,0);

}
void M_WDT_Void_WDTRefresh(void)
{
	asm("WDR");
}
