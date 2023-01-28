/*
 * SPI_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "SPI_Interface.h"
#include "SPI_Private.h"


void M_SPI_Void_SPIInit(void)
{
#if   SPI_MODE   ==   MASTER_MODE
	M_DIO_Void_SetPinDirection(PB4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(PB5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(PB6_PIN,INPUT);
	M_DIO_Void_SetPinDirection(PB7_PIN,OUTPUT);
	SET_BIT(SPCR_REG,MSTR_BIT);
	_delay_ms(1000);
	/* TO SELECT PRESCALER DV -> 128 */
	SET_BIT(SPCR_REG,SPR0_BIT);
	SET_BIT(SPCR_REG,SPR1_BIT);
#elif SPI_MODE   ==   SLAVE_MODE
	M_DIO_Void_SetPinDirection(PB4_PIN,INPUT);
	M_DIO_Void_SetPinDirection(PB5_PIN,INPUT);
	M_DIO_Void_SetPinDirection(PB6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(PB7_PIN,INPUT);
	CLR_BIT(SPCR_REG,MSTR_BIT);
#endif

	/* TO SEND FROM LSB FIRST */
	SET_BIT(SPCR_REG,DORD_BIT);

	/* TO ENABLE SPI CIRCUIT */
	SET_BIT(SPCR_REG,SPE_BIT);
}
u8   M_SPI_U8_SPITransive(u8 Copy_U8_Data)
{
	SPDR_REG = Copy_U8_Data;
	while(GET_BIT(SPSR_REG,SPIF_BIT) == SPI_STILL_PROCESSING);
	return SPDR_REG;
}
