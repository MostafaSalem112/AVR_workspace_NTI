/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"

void delay(void){

	u64 wait;
	for(u32 i=0;i<10000;i++){
		wait=0;
		while(wait++);
	}
}

int main(){

	DIO_voidSetPinDirection(PORTB,PIN7,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN4,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN6,PIN_OUTPUT);

	u8 ports[]={PORTB,PORTA,PORTA,PORTA};
	u8 pins[]={PIN7,PIN4,PIN5,PIN6};


	while(1){

		for(u8 i=0;i<4;i++){
			DIO_voidSetPinValue(ports[i],pins[i],PIN_HIGH);
			delay();
			DIO_voidSetPinValue(ports[i],pins[i],PIN_LOW);
			delay();
		}
		for(s8 i=2;i>0;i--){
			DIO_voidSetPinValue(ports[i],pins[i],PIN_HIGH);
			delay();
			DIO_voidSetPinValue(ports[i],pins[i],PIN_LOW);
			delay();
		}
	}

	return 0;
}
