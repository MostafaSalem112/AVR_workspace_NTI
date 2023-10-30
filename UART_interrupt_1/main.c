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
#include "COTS/MCAL/GIE/GIE_interface.h"
#include "COTS/HAL/KeyPad/KeyPad_interface.h"

u8 string[20];
u8 flag = 0;

void UART_TXC_ISR(){

	DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
	static u8 current_index = 1;

	if(flag == 1){
		if(string[current_index] != '\0'){
			UART_voidSendData(string[current_index++]);
		}else{
			UART_voidSendData(string[current_index]);
			current_index = 1;
			flag = 0;
		}
	}

}

int main(){

	GIE_voidEnable();

	DIO_voidSetPinDirection(PORTD,PIN0,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN1,PIN_OUTPUT);

	DIO_voidSetPinDirection(PORTA,PIN0,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);

	UART_voidInitialize();
	UART_TXC_SetCallBack(UART_TXC_ISR);

	KeyPad_voidInitialize();

	u8 data;
	u8 index = 0;

	while(1){

		data = KeyPad_u8GetPressedKey();

		if(data != 0xFF){
			if(data == '='){
				string[index] = '\0';
				UART_voidSendData(string[0]);
				index = 0;
				flag = 1;
			}else{
				string[index++] = data;
			}
		}
	}

	return 0;
}
