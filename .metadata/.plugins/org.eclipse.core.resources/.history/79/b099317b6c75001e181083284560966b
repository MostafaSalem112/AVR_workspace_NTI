/*
 * TIMER0_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"

void (*TIMER0_NORMAL_GPfun)(void)=NULL;
void (*TIMER0_CTC_GPfun)(void)=NULL;

u32 TIMER,PreLoad,PreScaler;

u8 delayFlag=0;

void TIMER0_voidEnable(){

	TCCR0->CS0 = CLOCK_PRESCALER;
}

void TIMER0_voidDisable(){

	TCCR0->CS0 = Timer_Counter_stopped;
}

void TIMER0_voidInitialize(){

	TCCR0->FOC0 = Force_Output_Compare_STATUS;

	TCCR0->COM0 = Compare_Output_Mode;

	TCCR0->WGM00 = GET_BIT(TIMER_MODE,WGM00_BIT);
	TCCR0->WGM01 = GET_BIT(TIMER_MODE,WGM01_BIT);

	TIMSK->TOIE0 = Overflow_Interrupt_Status;
	TIMSK->OCIE0 = Compare_Match_Interrupt_Status;
}

void TIMER0_voidPreLoad(u8 Copy_u8Value){

	TCNT0 = Copy_u8Value;
}

void TIMER0_voidSetOCR0(u8 Copy_u8Value){

	OCR0=Copy_u8Value;
}

void TIMER0_voidSetTimer(u32 Copy_u32TimeMS){

	u32 MAX_NUM;

#if TIMER_MODE == NORMAL_MODE
		MAX_NUM = MAX_8BIT_REG;
#elif TIMER_MODE == CTC_MODE
		MAX_NUM = OCR0;
#endif

#if CLOCK_PRESCALER == No_prescaling
	PreScaler = 1;
#elif CLOCK_PRESCALER == clkIO_8
	PreScaler = 8;
#elif CLOCK_PRESCALER == clkIO_64
	PreScaler = 64;
#elif CLOCK_PRESCALER == clkIO_256
	PreScaler = 256;
#elif CLOCK_PRESCALER == 1024
	PreScaler = 1024;
#endif

	f32 Tick_Time=((f32)PreScaler*MICROS_IN_SEC)/SYSTEM_CLOCK_FREQUENCY;
	f32 OverFlow_Time=Tick_Time*MAX_NUM;

	TIMER=(Copy_u32TimeMS*MICROS_IN_MILLI)/OverFlow_Time;
	f32 remainder=((Copy_u32TimeMS*MICROS_IN_MILLI)/OverFlow_Time)-TIMER;
	PreLoad=(1-remainder)*MAX_NUM;

	TIMER0_voidPreLoad(PreLoad);
}

void TIMER0_voidDelayms(u32 Copy_u32TimeMS){

	delayFlag = 1;

	TIMER0_voidSetTimer(Copy_u32TimeMS);

	while(delayFlag);
}

void TIMER0_NORMAL_SetCallBack(void(*ptr)(void)){

	TIMER0_NORMAL_GPfun=ptr;
}

void TIMER0_CTC_SetCallBack(void(*ptr)(void)){

	TIMER0_CTC_GPfun=ptr;
}

void __vector_10()__attribute__((signal));   // TIMER0_CTC
void __vector_10(){

	static u32 counter=0;

	if(counter==TIMER+1){
		if(TIMER0_CTC_GPfun!=NULL){
			TIMER0_CTC_GPfun();
		}
		delayFlag = 0;
		counter=0;
		TIMER0_voidPreLoad(PreLoad);
	}
	else{
		counter++;
	}

}

void __vector_11()__attribute__((signal));   // TIMER0_NORMAL
void __vector_11(){

	static u32 counter=0;

	if(counter==TIMER+1){
		if(TIMER0_NORMAL_GPfun!=NULL){
			TIMER0_NORMAL_GPfun();
		}
		delayFlag = 0;
		counter=0;
		TIMER0_voidPreLoad(PreLoad);
	}
	else{
		counter++;
	}

}
