/*
 * main.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/SPI/SPI_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"


int main(){

	DIO_voidSetPinDirection(PORTB,PIN4,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN5,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN6,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,PIN_INPUT);

	SPI_voidInitialize();

	LCD_voidInitialize();

	u8 data;

	while(1){

		data = SPI_u8Transceive(0);

		LCD_voidGoToXY(0,0);
		LCD_voidWriteData(data);
	}


	return 0;
}
