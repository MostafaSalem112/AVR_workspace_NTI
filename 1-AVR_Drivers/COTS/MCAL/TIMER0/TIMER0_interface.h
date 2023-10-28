/*
 * TIMER0_interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define COTS_MCAL_TIMER0_TIMER0_INTERFACE_H_


void TIMER0_voidEnable();
void TIMER0_voidDisable();
void TIMER0_voidInitialize();
void TIMER0_voidPreLoad(u8 Copy_u8Value);
void TIMER0_voidSetTimer(u32 Copy_u32TimeMS);
void TIMER0_voidDelayms(u32 Copy_u32TimeMS);
void TIMER0_NORMAL_SetCallBack(void(*ptr)(void));
void TIMER0_CTC_SetCallBack(void(*ptr)(void));


#endif /* COTS_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
