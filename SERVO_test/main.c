/*
 * main.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/TIMER1/TIMER1_interface.h"
#include "COTS/HAL/SERVO/SERVO_interface.h"
#include "COTS/Services/Mapping/Mapping_interface.h"

int main(){

	DIO_voidSetPinDirection(PORTD,PIN5,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTD,PIN5,PIN_LOW);

	DIO_voidSetPinDirection(PORTD,PIN4,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTD,PIN4,PIN_LOW);

	TIMER1_voidEnable();
	TIMER1_voidInitialize();

	SERVO_voidSetAngle(CHANNEL_A,113);

	SERVO_voidSetAngle(CHANNEL_B,55);

	while(1);

	return 0;
}
