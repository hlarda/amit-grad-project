/*
 * SPI_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "SPI_Config.h"
#include "DIO_Interface.h"
#include "BitMath.h"
#include "STD.h"
#include <util/delay.h>

void M_SPI_Void_SPIInit(void);
u8   M_SPI_U8_SPITransive(u8);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
