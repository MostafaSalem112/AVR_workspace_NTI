/********************************************************************/
/******************** Author: Mostafa Mahmoud Salem *****************/
/******************** Date  : 21/10/2023            *****************/
/******************** Description : LCD interface   *****************/
/********************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define INITIALIZE							0b00000010
#define FUNCTION_SET_2LINES_5x7_DOTS		0b00101000
#define DISPLAY_ON_CURSOR_ON_BLINK_ON		0b00001111
#define DISPLAY_ON_CURSOR_OFF				0b00001100
#define DISPLAY_CLEAR						0b00000001
#define ENTRY_MODE_SET						0b00000110

#define LINE0_ADDRESS						0x80
#define LINE1_ADDRESS						0xC0
#define LINE2_ADDRESS						0x94
#define LINE3_ADDRESS						0xD4

#define LINE0	0
#define LINE1	1
#define LINE2	2
#define LINE3	3

#define MAX_INT_DIGITS		10
#define ZERO_ASCII			'0'

void LCD_voidInitialize();
void LCD_voidWriteData(u8 Copy_u8Data);
void LCD_voidWriteCommand(u8 Copy_u8Command);
void LCD_voidClearDisplay();
void LCD_voidGoToXY(u8 Copy_u8Line,u8 Copy_u8Col);
void LCD_voidWriteString(u8 *Copy_u8String);
void LCD_voidWriteNumber(s32 Copy_u32Number);

#endif //LCD_INTERFACE_H
