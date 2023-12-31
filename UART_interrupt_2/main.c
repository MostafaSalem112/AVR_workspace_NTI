/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/UART/UART_interface.h"
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"

volatile u8 string[20];

void UART_RXC_ISR(){

	static u8 current_index = 0;

	u8 data = UART_u8ReciveData();

	if(data != '\0'){
		string[current_index++] = data;
	}else{
		string[current_index] = data;

		LCD_voidWriteString(string);
		current_index = 0;
	}
}

int main(){

	GIE_voidEnable();

	DIO_voidSetPinDirection(PORTD,PIN0,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN1,PIN_OUTPUT);

	UART_voidInitialize();
	UART_RXC_SetCallBack(UART_RXC_ISR);

	LCD_voidInitialize();

	while(1){

	}

	return 0;
}
