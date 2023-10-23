/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/SevenSegment/SEVSEG_interface.h"

void delay(void){

	u64 wait;
	for(u32 i=0;i<10000;i++){
		wait=0;
		while(wait++);
	}
}

int main(){

	SEVSEG_voidInitialize();
	SEVSEG_voidEnableSegment(SEVSEG_4);

	while(1){
		for(u8 i=0;i<10;i++){
			SEVSEG_voidWriteNumber(i);
			delay();
		}
	}

	return 0;
}
