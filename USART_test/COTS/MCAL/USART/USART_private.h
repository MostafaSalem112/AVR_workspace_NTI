/*
 * USART_private.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_USART_USART_PRIVATE_H_
#define COTS_MCAL_USART_USART_PRIVATE_H_

#define MAX_INT_DIGITS		10

/********************************************************************/
#define USART_DISABLE			0
#define USART_ENABLE			1
/*******************************************************************/

/*******************************************************************/
#define Asynchronous_Operation		0
#define Synchronous_Operation		1
/******************************************************************/

/**********************************************************************/
#define DISABLE_POLARITY			0b00
#define EVEN_POLARITY				0b10
#define ODD_POLARITY				0b11
/*********************************************************************/

/**********************************************************************/
#define STOP_1_BIT			0
#define STOP_2_BITS			1
/**********************************************************************/

/***************************************************************/
#define BITS_5			0b000
#define BITS_6			0b001
#define BITS_7			0b010
#define BITS_8			0b011
#define BITS_9			0b111
/***************************************************************/

/**************************************************************************/

#define Transmitte_At_Rising_Edge			0
#define	Transmitte_At_Falling_Edge			1
/********************************************************************/

typedef struct{
	u8 MPCM		:1;
	u8 U2X		:1;
	u8 PE		:1;
	u8 DOR		:1;
	u8 FE		:1;
	u8 UDRE		:1;
	u8 TXC		:1;
	u8 RXC		:1;
}UCSRA_t;

typedef struct{
	u8 TXB8		:1;
	u8 RXB8		:1;
	u8 UCSZ2	:1;
	u8 TXEN		:1;
	u8 RXEN		:1;
	u8 UDRIE	:1;
	u8 TXCIE	:1;
	u8 RXCIE	:1;
}UCSRB_t;

typedef struct{
	u8 UCPOL	:1;
	u8 UCSZ		:2;
	u8 USBS		:1;
	u8 UPM		:2;
	u8 UMSEL	:1;
	u8 URSEL	:1;
}UCSRC_t;

#define UDR			(*((volatile u8*)(0x2C)))
#define UCSRA		((volatile UCSRA_t*)(0x2B))
#define UCSRB		((volatile UCSRB_t*)(0x2A))
#define UCSRC		(*((volatile u8*)(0x40)))
#define UBRRH		(*((volatile u8*)(0x40)))
#define UBRRL		(*((volatile u8*)(0x29)))


#endif /* COTS_MCAL_USART_USART_PRIVATE_H_ */
