/*
 * TIMER1_interface.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define COTS_MCAL_TIMER1_TIMER1_INTERFACE_H_


#define Input_Capture_Falling_Edge		0
#define Input_Capture_rising_Edge		1

void TIMER1_voidEnable();
void TIMER1_voidDisable();
void TIMER1_voidInitialize();
void TIMER1_voidPreLoad(u16 Copy_u8Value);
u16 TIMER1_u16GetTimer();
void TIMER1_voidSetOCR1A(u16 Copy_u16Value);
void TIMER1_voidSetOCR1B(u16 Copy_u16Value);
void TIMER1_voidSetICR1(u16 Copy_u16Value);
u16 TIMER1_u16GetICR1();
void TIMER1_voidICUEdge(u8 Copy_Edge);
void TIMER1_voidSetTimer(u32 Copy_u32TimeMS);
f32 TIMER1_f32GetTickTime();
void TIMER1_voidGeneratePWMChannelA(u32 Copy_u32Periodms,f32 Copy_u8DutyCycle);
void TIMER1_voidGeneratePWMChannelB(u32 Copy_u32Periodms,f32 Copy_u8DutyCycle);
void TIMER1_ICU_SetCallBack(void(*ptr)(void));
void TIMER1_CTCA_SetCallBack(void(*ptr)(void));
void TIMER1_CTCB_SetCallBack(void(*ptr)(void));
void TIMER1_NORMAL_SetCallBack(void(*ptr)(void));

#endif /* COTS_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
