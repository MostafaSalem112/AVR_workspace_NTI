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
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/MCAL/TIMER0/TIMER0_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"

volatile u8 flag=0;

void func(){
	flag = 1;
}

int main(){

	GIE_voidEnable();

	ADC_voidInitilize();
	ADC_voidSelectChannel(ADC1);
	ADC_voidEnableAutoTriggerMode(Timer_Counter0_Overflow);
	ADC_SetCallBack(func);

	TIMER0_Initialize();
	TIMER0_voidEnable();

	LCD_voidInitialize();
	LCD_voidWriteString((u8*)"temp : ");

	u16 data,temp;

	while(1){

		if(flag == 1){
			data = ADC_u16ReadData();
			temp = (u16)(((u32)data*5000)/(1023*10));

			LCD_voidGoToXY(1,0);
			LCD_voidWriteNumber(temp);

			flag=0;

		}
	}

	return 0;
}

