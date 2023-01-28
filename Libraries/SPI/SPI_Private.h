/*
 * SPI_Private.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define SPCR_REG      *(volatile u8*)0x2D
#define SPDR_REG      *(volatile u8*)0x2F
#define SPSR_REG      *(volatile u8*)0x2E

/* SPCR BITS */
#define SPE_BIT                 6
#define DORD_BIT                5
#define MSTR_BIT                4
#define SPR1_BIT                1
#define SPR0_BIT                0

/* SPSR BITS */
#define SPIF_BIT                7

#define MASTER_MODE             1
#define SLAVE_MODE              2
#define SPI_STILL_PROCESSING    0

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
