/*
 * main.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/MCAL/USART/USART_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"


int main(){

	DIO_voidSetPinDirection(PORTD,PIN0,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN1,PIN_OUTPUT);

	USART_voidInitialize();

	LCD_voidInitialize();

	u8 data;

	while(1){

		data = USART_u8ReciveData();
		LCD_voidGoToXY(0,0);
		LCD_voidWriteData(data);
	}

	return 0;
}
