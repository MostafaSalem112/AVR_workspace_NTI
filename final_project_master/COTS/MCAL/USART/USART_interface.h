/*
 * USART_interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_USART_USART_INTERFACE_H_
#define COTS_MCAL_USART_USART_INTERFACE_H_

void USART_voidInitialize();
void USART_voidSendData(u8 Copy_u8Data);
u8 USART_u8ReciveData();
void USART_voidSendString(u8 *Copy_u8String);
u8 *USART_u8_ReciveString();
void USART_voidSendNumber(s32 Copy_u32Number);
void USART_RXC_SetCallBack(void(*ptr)(void));
void USART_TXC_SetCallBack(void(*ptr)(void));
void USART_UDRE_SetCallBack(void(*ptr)(void));

#endif /* COTS_MCAL_USART_USART_INTERFACE_H_ */
