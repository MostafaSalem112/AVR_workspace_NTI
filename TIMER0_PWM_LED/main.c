/*
 * main.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/MCAL/TIMER0/TIMER0_interface.h"
#include "COTS/HAL/LEDs/LED_interface.h"

int main(){

	TIMER0_voidEnable();
	TIMER0_voidInitialize();

	DIO_voidSetPinDirection(PORTB,PIN3,PIN_OUTPUT);

	TIMER0_voidSetPWM(100);

	while(1);

	return 0;
}
