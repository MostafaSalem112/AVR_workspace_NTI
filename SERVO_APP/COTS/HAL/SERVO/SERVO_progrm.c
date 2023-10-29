#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "SERVO_interface.h"

void SERVO_voidSetAngle(u8 Copy_u8Angle){
	u32 timer;
	f32 slop;
	TIMER1_voidInitialize();
	TIMER1_voidSetICR1(Set_Freq_50Hz);

	slop=50.0/9;
	timer=slop*Copy_u8Angle+999;

	TIMER1_voidSetOCR1(timer);
}
