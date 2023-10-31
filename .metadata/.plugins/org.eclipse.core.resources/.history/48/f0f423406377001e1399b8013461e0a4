/*
 * SPI_private.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_SPI_SPI_PRIVATE_H_
#define COTS_MCAL_SPI_SPI_PRIVATE_H_

/**********************************************************/
#define SPI_DISABLE		0
#define SPI_ENABLE		1
/*******************************************************/

/***********************************************************/
#define SPI_MSB			0
#define SPI_LSB			1
/********************************************************/

/***********************************************************/

/*********************************************************/

/**********************************************************/
#define SPI_CPOL_IDEAL_LOW			0
#define SPI_CPOL_IDEAL_HIGH			1
/*************************************************************/

/************************************************************/
#define SPI_SAMPLIG_EDGE_LEADING		0
#define SPI_SAMPLIG_EDGE_TRAILING		1
/*************************************************************/

/**************************************************************/
#define fosc_4			0b000
#define fosc_16			0b001
#define fosc_64			0b010
#define fosc_128		0b011
#define fosc_2			0b100
#define fosc_8			0b101
#define fosc_32			0b110
/****************************************************************/




typedef struct{
	u8 SPR		:2;
	u8 CPHA		:1;
	u8 CPOL		:1;
	u8 MSTR		:1;
	u8 DORD		:1;
	u8 SPE		:1;
	u8 SPIE		:1;
}SPCR_t;

typedef struct{
	u8 SPI2X	:1;
	u8 res		:5;
	u8 WCOL		:1;
	u8 SPIF		:1;
}SPSR_t;

#define SPCR		((volatile SPCR_t*)(0x2D))
#define SPSR		((volatile SPSR_t*)(0x2E))
#define SPDR		(*((volatile u8*)(0x2F)))

#endif /* COTS_MCAL_SPI_SPI_PRIVATE_H_ */
