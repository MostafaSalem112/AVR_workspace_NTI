/*
 * main.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mostafa_Salem
 */


#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/MCAL/TIMER0/TIMER0_interface.h"
#include "COTS/HAL/LEDs/LED_interface.h"

int main(){

	GIE_voidEnable();

	LED_voidInitialize(RED_LED);

	TIMER0_voidInitialize();
	TIMER0_voidEnable();

	while(1){

		LED_voidEnableLED(RED_LED);
		TIMER0_voidDelayms(1000);

		LED_voidDisableLED(RED_LED);
		TIMER0_voidDelayms(1000);
	}

	return 0;
}
