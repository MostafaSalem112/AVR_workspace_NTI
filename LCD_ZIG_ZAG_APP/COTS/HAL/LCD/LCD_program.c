/********************************************************************/
/******************** Author: Mostafa Mahmoud Salem *****************/
/******************** Date  : 21/10/2023            *****************/
/******************** Description : LCD program     *****************/
/********************************************************************/


#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "avr/delay.h"

void LCD_voidInitialize(){

	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_OUTPUT);

	DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN4,PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN6,PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN7,PIN_OUTPUT);
	_delay_ms(30);

	LCD_voidWriteCommand(INITIALIZE);
	LCD_voidWriteCommand(FUNCTION_SET_2LINES_5x7_DOTS);
	_delay_ms(2);

	LCD_voidWriteCommand(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(2);

	LCD_voidWriteCommand(DISPLAY_CLEAR);
	_delay_ms(2);

	LCD_voidWriteCommand(ENTRY_MODE_SET);
}

void LCD_voidWriteCommand(u8 Copy_u8Command){

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_LOW);

	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4,GET_BIT(Copy_u8Command,4));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN5,GET_BIT(Copy_u8Command,5));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN6,GET_BIT(Copy_u8Command,6));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN7,GET_BIT(Copy_u8Command,7));

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_LOW);

	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4,GET_BIT(Copy_u8Command,0));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN5,GET_BIT(Copy_u8Command,1));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN6,GET_BIT(Copy_u8Command,2));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN7,GET_BIT(Copy_u8Command,3));

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_LOW);
}

void LCD_voidWriteData(u8 Copy_u8Data){

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_HIGH);

	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4,GET_BIT(Copy_u8Data,4));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN5,GET_BIT(Copy_u8Data,5));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN6,GET_BIT(Copy_u8Data,6));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN7,GET_BIT(Copy_u8Data,7));

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_LOW);

	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4,GET_BIT(Copy_u8Data,0));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN5,GET_BIT(Copy_u8Data,1));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN6,GET_BIT(Copy_u8Data,2));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN7,GET_BIT(Copy_u8Data,3));

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_LOW);
}

void LCD_voidClearDisplay(){
	LCD_voidWriteCommand(DISPLAY_CLEAR);
}

void LCD_voidGoToXY(u8 Copy_u8Line,u8 Copy_u8Col){
	switch(Copy_u8Line){
		case LINE0:
			LCD_voidWriteCommand(LINE0_ADDRESS+Copy_u8Col);
			break;
		case LINE1:
			LCD_voidWriteCommand(LINE1_ADDRESS+Copy_u8Col);
			break;
		case LINE2:
			LCD_voidWriteCommand(LINE2_ADDRESS+Copy_u8Col);
			break;
		case LINE3:
			LCD_voidWriteCommand(LINE3_ADDRESS+Copy_u8Col);
			break;
	}
}

void LCD_voidWriteString(u8 *Copy_u8String){
	u8 i=0;
	while(Copy_u8String[i]!='\0'){
		LCD_voidWriteData(Copy_u8String[i]);
		i++;
	}
}

void LCD_voidWriteNumber(u32 Copy_u32Number){
	u8 arr[MAX_INT_DIGITS];
	u8 i=0;
	if(Copy_u32Number==0){
		LCD_voidWriteData(ZERO_ASCII);
	}
	else{
		while(Copy_u32Number>0){
			arr[i]=Copy_u32Number%10;
			Copy_u32Number/=10;
			i++;
		}
		for(u8 j=i;j>0;j--){
			LCD_voidWriteData(arr[j-1]+ZERO_ASCII);
		}
	}
}
