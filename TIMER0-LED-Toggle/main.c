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

void TIMER0_ISR(){

	LED_voidToggleLED(RED_LED);
}

int main(){

	TIMER0_INITIALZE();

	TIMER0_voidSetTimer(1000);
	TIMER0_NORMAL_SetCallBack(TIMER0_ISR);

	LED_voidInitialize(RED_LED);
	LED_voidEnableLED(RED_LED);

	GIE_voidEnable();
	TIMER0_voidEnable();

	while(1){

	}

	return 0;
}

