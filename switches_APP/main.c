/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/Switches/SWITCH_interface.h"

int main(){

	DIO_voidSetPinDirection(PORTB,PIN7,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN4,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN6,PIN_OUTPUT);

	DIO_voidSetPinDirection(PORTD,PIN7,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN6,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN5,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN3,PIN_INPUT);

	DIO_voidSetPinValue(PORTD,PIN7,PIN_HIGH);
	DIO_voidSetPinValue(PORTD,PIN6,PIN_HIGH);
	DIO_voidSetPinValue(PORTD,PIN5,PIN_HIGH);
	DIO_voidSetPinValue(PORTD,PIN3,PIN_HIGH);

	while(1){
		if(!DIO_u8GetPinValue(PORTD,PIN7)){
			DIO_voidSetPinValue(PORTA,PIN6,PIN_HIGH);
		}else{
			DIO_voidSetPinValue(PORTA,PIN6,PIN_LOW);
		}

		if(!DIO_u8GetPinValue(PORTD,PIN6)){
			DIO_voidSetPinValue(PORTA,PIN5,PIN_HIGH);
		}else{
			DIO_voidSetPinValue(PORTA,PIN5,PIN_LOW);
		}

		if(!DIO_u8GetPinValue(PORTD,PIN5)){
			DIO_voidSetPinValue(PORTA,PIN4,PIN_HIGH);
		}else{
			DIO_voidSetPinValue(PORTA,PIN4,PIN_LOW);
		}

		if(!DIO_u8GetPinValue(PORTD,PIN3)){
			DIO_voidSetPinValue(PORTB,PIN7,PIN_HIGH);
		}else{
			DIO_voidSetPinValue(PORTB,PIN7,PIN_LOW);
		}
	}


/*  switches driver
	DIO_voidSetPinDirection(PORTB,PIN7,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN4,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN6,PIN_OUTPUT);

	SWITCH_voidInitialize(SWITCH_1);
	SWITCH_voidInitialize(SWITCH_2);
	SWITCH_voidInitialize(SWITCH_3);
	SWITCH_voidInitialize(SWITCH_4);

	while(1){
		if(!SWITCH_u8GetSwitchValue(SWITCH_1)){
			DIO_voidSetPinValue(PORTA,PIN6,PIN_HIGH);
		}else{
			DIO_voidSetPinValue(PORTA,PIN6,PIN_LOW);
		}

		if(!SWITCH_u8GetSwitchValue(SWITCH_2)){
			DIO_voidSetPinValue(PORTA,PIN5,PIN_HIGH);
		}else{
			DIO_voidSetPinValue(PORTA,PIN5,PIN_LOW);
		}

		if(!SWITCH_u8GetSwitchValue(SWITCH_3)){
			DIO_voidSetPinValue(PORTA,PIN4,PIN_HIGH);
		}else{
			DIO_voidSetPinValue(PORTA,PIN4,PIN_LOW);
		}

		if(!SWITCH_u8GetSwitchValue(SWITCH_4)){
			DIO_voidSetPinValue(PORTB,PIN7,PIN_HIGH);
		}else{
			DIO_voidSetPinValue(PORTB,PIN7,PIN_LOW);
		}
	}
	*/

	return 0;
}
