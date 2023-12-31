/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/UART/UART_interface.h"
#include "COTS/HAL/KeyPad/KeyPad_interface.h"



int main(){

	DIO_voidSetPinDirection(PORTD,PIN0,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN1,PIN_OUTPUT);

	UART_voidInitialize();

	KeyPad_voidInitialize();

	u8 data;
	u8 string[20];
	u8 index = 0;

	while(1){

		data = KeyPad_u8GetPressedKey();

		if(data!=0xFF){
			if(data == '='){
				string[index]='!';
				string[index+1]='\0';
				UART_voidSendString(string);
				index = 0;
			}else{
				string[index++] = data;
			}
		}

	}

	return 0;
}
