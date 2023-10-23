/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "COTS/HAL/SevenSegment/SEVSEG_interface.h"
#include "avr/delay.h"

void counter(){

	for(u8 i=0;i<10;i++){
		SEVSEG_voidWriteNumber(i);

		LCD_voidGoToXY(1,0);
		LCD_voidWriteNumber(i);

		_delay_ms(1000);
	}
}

int main(){

	SEVSEG_voidInitialize();
	SEVSEG_voidEnableSegment(SEVSEG_4);

	DIO_voidSetPinDirection(PORTB,PIN7,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN4,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN6,PIN_OUTPUT);

	LCD_voidInitialize();
	LCD_voidWriteString((u8*)"COUNTER:");

	while(1){
		DIO_voidSetPinValue(PORTB,PIN7,PIN_HIGH);
		DIO_voidSetPinValue(PORTA,PIN4,PIN_LOW);
		DIO_voidSetPinValue(PORTA,PIN6,PIN_LOW);
		LCD_voidGoToXY(2,0);
		LCD_voidWriteString((u8*)"RED light    ");
		counter();

		DIO_voidSetPinValue(PORTB,PIN7,PIN_LOW);
		DIO_voidSetPinValue(PORTA,PIN4,PIN_LOW);
		DIO_voidSetPinValue(PORTA,PIN6,PIN_HIGH);
		LCD_voidGoToXY(2,0);
		LCD_voidWriteString((u8*)"YELLOW light   ");
		counter();

		DIO_voidSetPinValue(PORTB,PIN7,PIN_LOW);
		DIO_voidSetPinValue(PORTA,PIN4,PIN_HIGH);
		DIO_voidSetPinValue(PORTA,PIN6,PIN_LOW);
		LCD_voidGoToXY(2,0);
		LCD_voidWriteString((u8*)"GREEN light    ");
		counter();
	}

	return 0;
}
