#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "COTS/HAL/Switches/SWITCH_interface.h"
#include "avr/delay.h"

int main(){

	SWITCH_voidInitialize(SWITCH_1);
	SWITCH_voidInitialize(SWITCH_2);
	SWITCH_voidInitialize(SWITCH_3);
	SWITCH_voidInitialize(SWITCH_4);

	LCD_voidInitialize();

	while(1){
		if(SWITCH_u8GetSwitchValue(SWITCH_1) == 0){
			while(SWITCH_u8GetSwitchValue(SWITCH_1) == 0);
			LCD_voidGoToXY(0,0);
			LCD_voidWriteString((u8*)"Mostafa     ");
		}else if(SWITCH_u8GetSwitchValue(SWITCH_2) == 0){
			while(SWITCH_u8GetSwitchValue(SWITCH_2) == 0);
			LCD_voidGoToXY(0,0);
			LCD_voidWriteString((u8*)"Mahmoud     ");
		}else if(SWITCH_u8GetSwitchValue(SWITCH_3) == 0){
			while(SWITCH_u8GetSwitchValue(SWITCH_3) == 0);
			LCD_voidGoToXY(0,0);
			LCD_voidWriteString((u8*)"Salem       ");
		}else if(SWITCH_u8GetSwitchValue(SWITCH_4) == 0){
			while(SWITCH_u8GetSwitchValue(SWITCH_4) == 0);
			LCD_voidClearDisplay();
		}
	}

	return 0;
}
