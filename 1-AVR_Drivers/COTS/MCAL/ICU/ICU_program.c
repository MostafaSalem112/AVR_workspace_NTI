/*
 * ICU_program.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Mostafa_Salem
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "ICU_private.h"
#include "ICU_config.h"
#include "ICU_interface.h"

u8 EXTI_flag = 0;
u32 period,T_ON;

void EXTI_ISR(){

	if(EXTI_flag == 0){
		TIMER1_voidPreLoad(0);
		EXTI_flag = 1;
	}else if(EXTI_flag == 1){
		period = TIMER1_u16GetTimer();
		EXTI_voidSetSenseCase(ICU_CHANNEL,FALLING_EDGE_SENSE);
		TIMER1_voidPreLoad(0);
		EXTI_flag = 2;
	}else if(EXTI_flag == 2){
		T_ON = TIMER1_u16GetTimer();
		EXTI_voidSetSenseCase(ICU_CHANNEL,RISING_EDGE_SENSE);
		EXTI_flag = 0;
	}

}

void ICU_voidInitialize(){

	EXTI_voidEnable(ICU_CHANNEL);
	EXTI_voidSetSenseCase(ICU_CHANNEL,RISING_EDGE_SENSE);
	EXTI_SetCallBack(ICU_CHANNEL,EXTI_ISR);

	TIMER1_voidEnable();
	TIMER1_voidInitialize();

}

u32 ICU_u32GetPeridTime(){

	u32 period_time = period*TIMER1_f64GetTickTime();

	return period_time;
}

u32 ICU_u32GetOnTime(){

	u32 ON_time = T_ON*TIMER1_f64GetTickTime();

	return ON_time;
}

u8 ICU_u8GetDutyCycle(){

	u8 duty_cycle = (T_ON*100)/period;

	return duty_cycle;
}
