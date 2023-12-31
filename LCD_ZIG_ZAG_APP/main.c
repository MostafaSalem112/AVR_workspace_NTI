/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "avr/delay.h"

int main(){

	LCD_voidInitialize();

	u8 line=0;
	u8 col=0;
	u8 flag=0;

	while(1){
		LCD_voidGoToXY(line,col);
		LCD_voidWriteData('A');
		_delay_ms(500);
		LCD_voidGoToXY(line,col);
		LCD_voidWriteData(' ');

		if(!flag){
			line++;
			if(line>2){
				flag=1;
			}
		}else{
			line--;
			if(line<1){
				flag=0;
			}
		}

		col++;
		if(col>19){
			col=0;
			line=0;
		}

	}

	return 0;
}
