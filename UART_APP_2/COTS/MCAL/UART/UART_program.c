#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "UART_private.h"
#include "UART_interface.h"

u8 TEMP;

void UART_voidInitialize(){
	
	u16 baud_rate = 0;

	SET_BIT(UCSRB,PIN4);
	SET_BIT(UCSRB,PIN3);
	
	SET_BIT(TEMP,PIN7);
	CLR_BIT(TEMP,PIN6);
	CLR_BIT(TEMP,PIN5);
	CLR_BIT(TEMP,PIN4);
	CLR_BIT(TEMP,PIN3);
	SET_BIT(TEMP,PIN2);
	SET_BIT(TEMP,PIN1);
	
	UCSRC=TEMP;
	
	baud_rate = (u16)(((CLOCK_FREQUENCY)/(16*(u32)BAUD_RATE))-1);

	UBRRH=(baud_rate>>8);
	UBRRL=baud_rate;
}

void UART_voidSendData(u8 Copy_u8Data){
	UDR=Copy_u8Data;
	while((GET_BIT(UCSRA,PIN6))==0);
	SET_BIT(UCSRA,PIN6);
}

u8 UART_u8ReciveData(){
	while((GET_BIT(UCSRA,PIN7))==0);
	return UDR;
}

void UART_voidSendString(u8 *Copy_u8String){
	u8 i=0;
	while(Copy_u8String[i]!='\0'){
		UDR=Copy_u8String[i];
		while((GET_BIT(UCSRA,PIN6))==0);
		SET_BIT(UCSRA,PIN6);
		i++;
	}
}

u8 *UART_u8_ReciveString(){
	static u8 string[20];
	u8 i=0;
	do{
		string[i]=UART_u8ReciveData();
		i++;
	}while(string[i-1]!='!');
	string[i-1]='\0';
	return string;
}

void UART_voidSendNumber(u32 Copy_u32Number){
	u8 arr[MAX_INT_DIGITS];
	u8 i=0;
	if(Copy_u32Number==0){
		UART_voidSendData(ZERO_ASCII);
	}
	else{
		while(Copy_u32Number>0){
			arr[i]=Copy_u32Number%10;
			Copy_u32Number/=10;
			i++;
		}
		for(u8 j=i;j>0;j--){
			UART_voidSendData(arr[j-1]+ZERO_ASCII);
		}		
	}
}
