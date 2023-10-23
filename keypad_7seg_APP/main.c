/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Mostafa_Salem
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/KeyPad/KeyPad_interface.h"
#include "COTS/HAL/SevenSegment/SEVSEG_interface.h"

int main(){

	KeyPad_voidInitialize();
	SEVSEG_voidInitialize();
	SEVSEG_voidEnableSegment(SEVSEG_1);

	u8 key;

	while(1){

		key = KeyPad_u8GetPressedKey();

		if(key!=0xFF){
			SEVSEG_voidWriteNumber(key);
		}
	}

	return 0;
}
