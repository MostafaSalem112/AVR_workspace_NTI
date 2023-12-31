/*
 * main.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mostafa_Salem
 */
#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/ADC/ADC_interface.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/EXTI/EXTI_interface.h"
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/MCAL/TIMER0/TIMER0_interface.h"
#include "COTS/HAL/LEDs/LED_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"

volatile u8 flag=0;

void ADC_ISR(){

	flag = 1;
}

void EXTI_ISR(){

	static u8 counter = 0;

	counter++;

	if(counter%2==1){
		TIMER0_voidEnable();
		TIMER0_voidSetTimer(1000);
	}else{
		TIMER0_voidDisable();
	}
}

void TIMER0_ISR(){

	LED_voidToggleLED(RED_LED);
}

int main(){

	GIE_voidEnable();

	ADC_voidInitilize();
	ADC_voidSelectChannel(ADC1);
	ADC_voidEnableAutoTriggerMode(Timer_Counter0_Overflow);
	ADC_SetCallBack(ADC_ISR);

	DIO_voidSetPinDirection(PORTD,PIN3,PIN_INPUT);
	DIO_voidSetPinValue(PORTD,PIN3,PIN_HIGH);

	EXTI_voidEnable(EXTI_1);
	EXTI_voidSetSenseCase(EXTI_1,FALLING_EDGE_SENSE);
	EXTI_SetCallBack(EXTI_1,EXTI_ISR);

	LCD_voidInitialize();
	LCD_voidWriteString((u8*)"temp : ");

	TIMER0_Initialize();
	TIMER0_NORMAL_SetCallBack(TIMER0_ISR);

	LED_voidInitialize(RED_LED);
	LED_voidEnableLED(RED_LED);

	u16 data,temp;

	while(1){

		if(flag == 1){
			data = ADC_u16ReadData();
			temp = (u16)(((u32)data*5000)/(1023*10));

			LCD_voidGoToXY(1,0);
			LCD_voidWriteNumber(temp);
			LCD_voidWriteString((u8*)"      ");

			flag=0;
		}
	}

	return 0;
}




