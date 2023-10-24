/*
 * main.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Mostafa_Salem
 */
#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/ADC/ADC_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "COTS/Services/Mapping/Mapping_interface.h"
#include "avr/delay.h"


int main(){

	LCD_voidInitialize();
	LCD_voidWriteString((u8*)"temp = ");

	u16 data=0,temp;

	ADC_voidInitilize();
	ADC_voidSelectChannel(ADC1);

	while(1){


		data = ADC_voidStartConversion();
		temp = Mapping_u16Map(data,0,1023,1,500);
		LCD_voidGoToXY(1,0);
		LCD_voidWriteNumber(temp);
		LCD_voidWriteString((u8*)"     ");

		_delay_ms(500);
	}

	return 0;
}

