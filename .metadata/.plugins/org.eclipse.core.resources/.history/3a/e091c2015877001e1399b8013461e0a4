/*
 * USART_program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Mostafa_Salem
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"

u8 TEMP;

void UART_voidInitialize(){

	UCSRB->RXCIE = ENABLE;
	UCSRB->UDRIE = ENABLE;
	UCSRB->RXEN = ENABLE;
	UCSRB->TXEN = ENABLE;

	SET_BIT(TEMP,7);
	CLR_BIT(TEMP,6);
	CLR_BIT(TEMP,5);
	CLR_BIT(TEMP,4);
	CLR_BIT(TEMP,3);
	SET_BIT(TEMP,2);
	SET_BIT(TEMP,1);
	UCSRB->UCSZ2 = DISABLE;
	CLR_BIT(TEMP,0);

	UCSRC = TEMP;

	UBRRL = 51;//(u8)(((CLOCK_FREQUENCY)/(16*(u32)BAUD_RATE))-1);
}

void UART_voidSendData(u8 Copy_u8Data){

	UDR = Copy_u8Data;
	while(UCSRA->UDRE == 0);
	UCSRA->UDRE = 1;
}

u8 UART_u8ReciveData(){

	while(UCSRA->RXC == 0);
	return UDR;
}
