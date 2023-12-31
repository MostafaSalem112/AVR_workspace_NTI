/*
 * main.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/ADC/ADC_interface.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/TIMER0/TIMER0_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "COTS/Services/Mapping/Mapping_interface.h"


int main(){

	ADC_voidInitilize();
	ADC_voidSelectChannel(ADC0);

	DIO_voidSetPinDirection(PORTB,PIN3,PIN_OUTPUT);

	LCD_voidInitialize();

	LCD_voidGoToXY(0,0);
	LCD_voidWriteString((u8*)"ADC reading : ");

	LCD_voidGoToXY(2,0);
	LCD_voidWriteString((u8*)"Duty cycle : ");

	TIMER0_voidEnable();
	TIMER0_voidInitialize();

	u16 ADC_data;
	u8 duty_cycle;

	while(1){

		ADC_voidStartConversion();
		ADC_data = ADC_u16ReadData();

		LCD_voidGoToXY(1,0);
		LCD_voidWriteNumber(ADC_data);
		LCD_voidWriteString((u8*)"         ");

		duty_cycle = Mapping_u16Map(ADC_data,0,1023,0,100);

		TIMER0_voidSetPWM(duty_cycle);

		LCD_voidGoToXY(3,0);
		LCD_voidWriteNumber(duty_cycle);
		LCD_voidWriteString((u8*)"         ");

	}


	return 0;
}
