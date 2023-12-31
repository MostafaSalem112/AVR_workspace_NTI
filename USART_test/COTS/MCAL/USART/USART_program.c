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

void (*GP_USART_RXC)(void) = NULL;
void (*GP_USART_TXC)(void) = NULL;
void (*GP_USART_UDRE)(void) = NULL;

u8 TEMP = 0;

void USART_voidInitialize(){

	u16 BAUD_RATE_REG;

	UCSRA->U2X = Double_Transmission_Speed_STATUS;

	UCSRB->RXCIE = RX_Complete_Interrupt_STATUS;
	UCSRB->TXCIE = TX_Complete_Interrupt_STATUS;
	UCSRB->UDRIE = Data_Register_Empty_Interrupt_STATUS;

	UCSRB->RXEN = USART_ENABLE;
	UCSRB->TXEN = USART_ENABLE;

	SET_BIT(TEMP,7);
	TEMP |= (OPERATION_MODE<<6);
	TEMP |= (POLARITY_CHECK_MODE<<4);
	TEMP |= (STOP_BIT_MODE<<3);
	TEMP |= ((CHAR_SIZE&0b011)<<1);
	UCSRB->UCSZ2 = ((CHAR_SIZE>>2)&0b1);
	TEMP |= (CLOCK_POLARITY<<0);

	UCSRC = TEMP;

	#if OPERATION_MODE == Synchronous_Operation
		BAUD_RATE_REG = (CLOCK_FREQUENCY/(2*(u32)BAUD_RATE))-1;
	#elif OPERATION_MODE == Asynchronous_Operation
		#if Double_Transmission_Speed_STATUS == USART_ENABLE
			BAUD_RATE_REG = (CLOCK_FREQUENCY/(8*(u32)BAUD_RATE))-1;
		#elif Double_Transmission_Speed_STATUS == USART_DISABLE
			BAUD_RATE_REG = (CLOCK_FREQUENCY/(16*(u32)BAUD_RATE))-1;
		#endif
	#endif

	UBRRH = (u8)(BAUD_RATE_REG>>8);
	UBRRL = (u8)BAUD_RATE_REG;
}

void USART_voidSendData(u8 Copy_u8Data){

	UDR = Copy_u8Data;

	#if Data_Register_Empty_Interrupt_STATUS == USART_DISABLE
		while(UCSRA->UDRE == 0);
	#endif
}

u8 USART_u8ReciveData(){

	#if RX_Complete_Interrupt_STATUS == USART_DISABLE
		while(UCSRA->RXC == 0);
	#endif

	return UDR;
}

void USART_voidSendString(u8 *Copy_u8String){
	u8 i=0;
	while(Copy_u8String[i]!='\0'){
		USART_voidSendData(Copy_u8String[i]);
		i++;
	}
}

u8 *USART_u8_ReciveString(){
	static u8 string[20];
	u8 i=0;
	do{
		string[i]=USART_u8ReciveData();
		i++;
	}while(string[i-1]!='\0');
	string[i-1]='\0';
	return string;
}

void USART_voidSendNumber(s32 Copy_u32Number){
	u8 arr[MAX_INT_DIGITS];
	u8 i=0;
	if(Copy_u32Number == 0){
		USART_voidSendData('0');
	}
	else if(Copy_u32Number > 0){
		while(Copy_u32Number>0){
			arr[i]=Copy_u32Number%10;
			Copy_u32Number/=10;
			i++;
		}
		for(u8 j=i;j>0;j--){
			USART_voidSendData(arr[j-1]+'0');
		}
	}
	else{
		USART_voidSendData('-');
		Copy_u32Number*=-1;
		while(Copy_u32Number>0){
			arr[i]=Copy_u32Number%10;
			Copy_u32Number/=10;
			i++;
		}
		for(u8 j=i;j>0;j--){
			USART_voidSendData(arr[j-1]+'0');
		}
	}
}

void USART_RXC_SetCallBack(void(*ptr)(void)){

	GP_USART_RXC = ptr;
}

void USART_TXC_SetCallBack(void(*ptr)(void)){

	GP_USART_TXC = ptr;
}

void USART_UDRE_SetCallBack(void(*ptr)(void)){

	GP_USART_UDRE = ptr;
}

void __vector_13()__attribute__((signal));
void __vector_13(){

	if(GP_USART_RXC!=NULL){
		GP_USART_RXC();
	}
}

void __vector_14()__attribute__((signal));
void __vector_14(){

	if(GP_USART_UDRE!=NULL){
		GP_USART_UDRE();
	}
}

void __vector_15()__attribute__((signal));
void __vector_15(){

	if(GP_USART_TXC!=NULL){
		GP_USART_TXC();
	}
}
