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
#include "COTS/HAL/KeyPad/KeyPad_interface.h"
#include "avr/delay.h"

/*
int main(){

	DIO_voidSetPinDirection(PORTA,PIN0,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
	DIO_voidSetPinDirection(PORTA,PIN1,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);

	DIO_voidSetPinDirection(PORTB,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN6,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,PIN_OUTPUT);

	SPI_voidInitialize();

	KeyPad_voidInitialize();

	u8 data,SPI_value,flag=0;

	while(1){

		data = KeyPad_u8GetPressedKey();

		if(data != 0xFF){
			if(data == '#'){
				if(!flag){
					flag = 1;
				}else{
					flag = 0;
				}
			}else{
				if(!flag){
					DIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
					SPI_value = SPI_u8Transceive(data);
					DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
				}else{
					DIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
					SPI_value = SPI_u8Transceive(data);
					DIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);
				}
			}

		}
	}

	return 0;
}*/

int main(){


	DIO_voidSetPinDirection(PORTA,PIN0,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
	DIO_voidSetPinDirection(PORTA,PIN1,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);

	DIO_voidSetPinDirection(PORTB,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN6,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,PIN_OUTPUT);

	SPI_voidInitialize();

	u8 SPI_value;

	while(1){
		DIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
		SPI_value = SPI_u8Transceive('O');
		DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);

		_delay_ms(1000);

		DIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
		SPI_value = SPI_u8Transceive('P');
		DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);

		DIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
		SPI_value = SPI_u8Transceive('O');
		DIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);

		_delay_ms(1000);

		DIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
		SPI_value = SPI_u8Transceive('P');
		DIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);

	}

	return 0;
}
