/*
 * SERVO_progrm.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Mostafa_Salem
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../Services/Mapping/Mapping_interface.h"
#include "SERVO_interface.h"

void SERVO_voidSetAngle(u8 Copy_u8Channel,u8 Copy_u8Angle){

	u32 period = 20000;
	u32 top = 2000;
	u32 bottom = 1000;

	u32 lower_dutyCycle = (bottom*100)/period;
	u32 UPPER_dutyCycle = (top*100)/period;

	f32 dutyCycle = Mapping_u16Map(Copy_u8Angle,0,180,lower_dutyCycle,UPPER_dutyCycle);

	switch(Copy_u8Channel){
		case CHANNEL_A:
			TIMER1_voidGeneratePWMChannelA(period,dutyCycle);
			break;
		case CHANNEL_B:
			TIMER1_voidGeneratePWMChannelB(period,dutyCycle);
			break;
	}

}
