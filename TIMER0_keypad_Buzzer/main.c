/*
 * main.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/MCAL/TIMER0/TIMER0_interface.h"
#include "COTS/HAL/KeyPad/KeyPad_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "avr/delay.h"


int main(){

	LCD_voidInitialize();

	KeyPad_voidInitialize();

	TIMER0_voidInitialize();
	TIMER0_voidEnable();

	DIO_voidSetPinDirection(PORTB,PIN3,PIN_OUTPUT);

	u8 key;

	while(1){

		key = KeyPad_u8GetPressedKey();

		if(key != 0xFF){

			LCD_voidGoToXY(0,0);
			LCD_voidWriteData(key);

			switch(key){
			case '1':
				TIMER0_voidSetPWM(10);
				break;
			case '2':
				TIMER0_voidSetPWM(15);
				break;
			case '3':
				TIMER0_voidSetPWM(20);
				break;
			case '/':
				TIMER0_voidSetPWM(25);
				break;
			case '4':
				TIMER0_voidSetPWM(30);
				break;
			case '5':
				TIMER0_voidSetPWM(35);
				break;
			case '6':
				TIMER0_voidSetPWM(40);
				break;
			case '*':
				TIMER0_voidSetPWM(45);
				break;
			case '7':
				TIMER0_voidSetPWM(50);
				break;
			case '8':
				TIMER0_voidSetPWM(55);
				break;
			case '9':
				TIMER0_voidSetPWM(60);
				break;
			case '+':
				TIMER0_voidSetPWM(65);
				break;
			case '#':
				TIMER0_voidSetPWM(70);
				break;
			case '0':
				TIMER0_voidSetPWM(75);
				break;
			case '=':
				TIMER0_voidSetPWM(80);
				break;
			case '-':
				TIMER0_voidSetPWM(85);
				break;
			}

			_delay_ms(500);

		}else{
			TIMER0_voidSetPWM(0);
		}

	}


	return 0;
}
