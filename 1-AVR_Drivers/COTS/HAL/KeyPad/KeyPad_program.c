/***********************************************************************/
/************************* Author : Mostafa Mahmoud Salem **************/
/************************* Date : 22/10/2023              **************/
/************************* Description : keypad program   **************/
/***********************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KeyPad_private.h"
#include "KeyPad_config.h"
#include "KeyPad_interface.h"
#include "avr/delay.h"

u8 ROWS_PINS[ROWS_NUM] = {ROW_1_PIN,ROW_2_PIN,ROW_3_PIN,ROW_4_PIN};
u8 COLS_PINS[COLS_NUM] = {COL_1_PIN,COL_2_PIN,COL_3_PIN,COL_4_PIN};

void KeyPad_voidInitialize(){
	
	for(u8 row=0;row<ROWS_NUM;row++){
		DIO_voidSetPinDirection(ROWS_PORT,ROWS_PINS[row],PIN_OUTPUT);
		DIO_voidSetPinValue(ROWS_PORT,ROWS_PINS[row],PIN_HIGH);
	}
	
	for(u8 col=0;col<COLS_NUM;col++){
		DIO_voidSetPinDirection(COLS_PORT,COLS_PINS[col],PIN_INPUT);
		DIO_voidSetPinValue(COLS_PORT,COLS_PINS[col],PIN_HIGH);
	}
}
u8 KeyPad_u8GetPressedKey(){
	
	u8 Local_u8PressedKey = 0xFF;

	u8 data[ROWS_NUM][COLS_NUM] = arr_data;
	
	for(u8 i=0;i<ROWS_NUM;i++){
		
		DIO_voidSetPinValue(ROWS_PORT,ROWS_PINS[i],PIN_LOW);
		
		for(u8 j=0;j<COLS_NUM;j++){
			if(DIO_u8GetPinValue(COLS_PORT,COLS_PINS[j]) == PIN_LOW){
				Local_u8PressedKey = data[i][j];
				while(DIO_u8GetPinValue(COLS_PORT,COLS_PINS[j])==PIN_LOW);
				break;
			}
		}
		
		DIO_voidSetPinValue(ROWS_PORT,ROWS_PINS[i],PIN_HIGH);

		if(Local_u8PressedKey != 0xFF){
			break;
		}
	}
	
	return Local_u8PressedKey;
}
