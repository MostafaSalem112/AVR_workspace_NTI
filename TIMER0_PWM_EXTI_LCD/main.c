/*
 * main.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/EXTI/EXTI_interface.h"
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/MCAL/TIMER0/TIMER0_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"

u8 duty_cycle = 0;

void EXTI1_ISR(){

	if(duty_cycle == 100){
		duty_cycle = 0;
	}else{
		duty_cycle++;
	}
}

int main(){

	DIO_voidSetPinDirection(PORTB,PIN3,PIN_OUTPUT);

	DIO_voidSetPinDirection(PORTD,PIN3,PIN_INPUT);
	DIO_voidSetPinValue(PORTD,PIN3,PIN_HIGH);

	EXTI_voidEnable(EXTI_1);
	EXTI_voidSetSenseCase(EXTI_1,FALLING_EDGE_SENSE);
	EXTI_SetCallBack(EXTI_1,EXTI1_ISR);

	GIE_voidEnable();

	TIMER0_voidInitialize();
	TIMER0_voidEnable();

	LCD_voidInitialize();
	LCD_voidWriteString((u8*)"Duty Cycle : ");

	while(1){

		TIMER0_voidSetPWM(duty_cycle);

		LCD_voidGoToXY(1,0);
		LCD_voidWriteNumber(duty_cycle);
		LCD_voidWriteString((u8*)"      ");
	}


	return 0;
}
