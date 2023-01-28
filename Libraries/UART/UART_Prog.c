/*
 * UART_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"


void M_UART_Void_UARTInit(void)
{
	u8 Local_U8_UCSRC = 0b10000000;

	/* TO SELECT BAUDRATE -> 9600 */
	UBRRL_REG = 103;

	/* TO DISABLE PARITY */
	CLR_BIT(Local_U8_UCSRC,UPM0_BIT);
	CLR_BIT(Local_U8_UCSRC,UPM1_BIT);

	/* TO SELECT 1 STOP BIT */
	CLR_BIT(Local_U8_UCSRC,USBS_BIT);

	/* TO SELECT ASYNCH. MODE */
	CLR_BIT(Local_U8_UCSRC,UMSEL_BIT);

	/* TO SELECT CHARACTER SIZE -> 8 BITS */
	SET_BIT(Local_U8_UCSRC,UCSZ0_BIT);
	SET_BIT(Local_U8_UCSRC,UCSZ1_BIT);
	CLR_BIT(UCSRB_REG,UCSZ2_BIT);

	UCSRC_REG = Local_U8_UCSRC;

	/* TO ENABLE RX CIRCUIT */
	SET_BIT(UCSRB_REG,RXEN_BIT);

	/* TO ENABLE TX CIRCUIT */
	SET_BIT(UCSRB_REG,TXEN_BIT);
}
void M_UART_Void_UARTSend(u8 Copy_U8_Data)
{
	UDR_REG = Copy_U8_Data;
	while(GET_BIT(UCSRA_REG,TXC_BIT) == 0);
}
u8   M_UART_Void_UARTRec(void)
{
	while(GET_BIT(UCSRA_REG,RXC_BIT) == 0);
	return UDR_REG;
}







