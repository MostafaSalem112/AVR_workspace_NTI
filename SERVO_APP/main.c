/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/TIMER1/TIMER1_interface.h"
#include "COTS/HAL/SERVO/SERVO_interface.h"
#include "COTS/MCAL/ADC/ADC_interface.h"
#include "COTS/Services/Mapping/Mapping_interface.h"


int main(){

	DIO_voidSetPinDirection(PORTD,PIN5,PIN_OUTPUT);

	ADC_voidInitilize();
	ADC_voidSelectChannel(ADC0);

	u16 ADC_data;
	u8 angle;

	while(1){

		ADC_voidStartConversion();
		ADC_data = ADC_u16ReadData();

		angle = Mapping_u16Map(ADC_data,0,1023,0,180);

		SERVO_voidSetAngle(angle);
	}


	return 0;
}
