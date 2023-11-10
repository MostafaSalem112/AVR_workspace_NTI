/*
 * main.c
 *
 *  Created on: Nov 8, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/EXTI/EXTI_interface.h"
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/MCAL/TIMER0/TIMER0_interface.h"
#include "COTS/MCAL/TIMER1/TIMER1_interface.h"
#include "COTS/MCAL/ADC/ADC_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "COTS/Services/Mapping/Mapping_interface.h"
#include "avr/delay.h"

u32 MAX_u16_NUM = 65536;

u32 period,t_on;
u8 counter = -1;

void EXTI_ISR(){

	static u8 flag = 0;

	if(flag == 0){

		TIMER1_voidPreLoad(0);
		counter = 0;

	}else if(flag == 1){

		period = TIMER1_u16GetTimer() + counter*MAX_u16_NUM;

	}else if(flag == 50){

		EXTI_voidSetSenseCase(EXTI_0,FALLING_EDGE_SENSE);
		TIMER1_voidPreLoad(0);
		counter = 0;

	}else if(flag == 51){

		t_on = TIMER1_u16GetTimer() + counter*MAX_u16_NUM;
		EXTI_voidSetSenseCase(EXTI_0,RISING_EDGE_SENSE);

		LCD_voidGoToXY(0,0);
		LCD_voidWriteNumber(period);
		LCD_voidWriteString((u8*)"     ");

		LCD_voidGoToXY(1,0);
		LCD_voidWriteNumber(t_on);
		LCD_voidWriteString((u8*)"     ");

		LCD_voidGoToXY(2,0);
		LCD_voidWriteNumber((t_on*100)/period);
		LCD_voidWriteString((u8*)"     ");
	}
	flag++;
}

void TIMER1_ISR(){

	counter++;
}

int main(){

	DIO_voidSetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_voidSetPinValue(PORTD,PIN2,PIN_HIGH);
	DIO_voidSetPinDirection(PORTB,PIN3,PIN_OUTPUT);

	EXTI_voidEnable(EXTI_0);
	EXTI_voidSetSenseCase(EXTI_0,RISING_EDGE_SENSE);
	EXTI_SetCallBack(EXTI_0,EXTI_ISR);

	GIE_voidEnable();

	TIMER0_voidEnable();
	TIMER0_voidInitialize();
	TIMER0_voidSetPWM(100);

	TIMER1_voidEnable();
	TIMER1_voidInitialize();
	TIMER1_NORMAL_SetCallBack(TIMER1_ISR);

	ADC_voidInitilize();
	ADC_voidSelectChannel(ADC0);

	LCD_voidInitialize();

	u16 ADC_data;
	u8 duty_cycle;

	while(1){

		ADC_voidStartConversion();
		ADC_data = ADC_u16ReadData();
		duty_cycle = Mapping_u16Map(ADC_data,0,1023,1,99);
		TIMER0_voidSetPWM(duty_cycle);
	}

	return 0;
}
