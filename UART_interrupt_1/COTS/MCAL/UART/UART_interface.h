#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

#define ZERO_ASCII 48
#define MAX_INT_DIGITS 10

#define CLOCK_FREQUENCY			8000000
#define BAUD_RATE				9600//115200

//################# prototypes ########################
void UART_voidInitialize();
void UART_voidSendData(u8 Copy_u8Data);
u8 UART_u8ReciveData();
void UART_voidSendString(u8 *Copy_u8String);
u8 *UART_u8_ReciveString();
void UART_voidSendNumber(u32 Copy_u32Number);
void UART_RXC_SetCallBack(void(*ptr)(void));
void UART_TXC_SetCallBack(void(*ptr)(void));

#endif
