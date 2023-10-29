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

void SERVO_voidSetAngle(u8 Copy_u8Angle){

	u32 period = 20000;
	u32 top = 2500;
	u32 bottom = 750;

	f32 lower_dutyCycle = (f32)bottom/period;
	f32 UPPER_dutyCycle = (f32)top/period;

	u32 dutyCycle = Mapping_u16Map(Copy_u8Angle,0,180,lower_dutyCycle,UPPER_dutyCycle);

	TIMER1_voidGeneratePWM(period,dutyCycle);
}