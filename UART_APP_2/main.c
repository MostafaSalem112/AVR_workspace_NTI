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
#include "COTS/MCAL/TIMER1/TIMER1_interface.h"
#include "COTS/HAL/SERVO/SERVO_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"


int main(){


	DIO_voidSetPinDirection(PORTD,PIN0,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN1,PIN_OUTPUT);

	UART_voidInitialize();

	LCD_voidInitialize();

	//DIO_voidSetPinDirection(PORTD,PIN5,PIN_OUTPUT);

	u8 *data;

	while(1){
		data = UART_u8_ReciveString();

		LCD_voidWriteString(data);
	}
	return 0;
}
