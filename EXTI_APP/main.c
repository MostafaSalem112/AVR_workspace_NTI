/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mostafa_Salem
 */
#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/MCAL/EXTI/EXTI_interface.h"
#include "COTS/HAL/LEDs/LED_interface.h"

void toggle_led(void){
	LED_voidToggleLED(RED_LED);
}

int main(){

	DIO_voidSetPinDirection(PORTD,PIN3,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTD,PIN3,PIN_HIGH);

	GIE_voidEnable();
	EXTI_voidEnable(EXTI_1);
	EXTI_voidSetSenseCase(EXTI_1,FALLING_EDGE_SENSE);

	LED_voidInitialize(RED_LED);
	LED_voidEnableLED(RED_LED);

	EXTI_SetCallBack(EXTI_1,toggle_led);

	while(1){

	}
	return 0;
}

