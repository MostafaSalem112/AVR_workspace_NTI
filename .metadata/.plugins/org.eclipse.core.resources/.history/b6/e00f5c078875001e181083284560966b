/*
 * TIMER0_private.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define COTS_MCAL_TIMER0_TIMER0_PRIVATE_H_

#define WGM00_BIT	0
#define WGM01_BIT	1

#define MICROS_IN_SEC	1000000
#define MICROS_IN_MILLI	1000

#define MAX_8BIT_REG	256

typedef struct{
	u8 CS0		:3;
	u8 WGM01	:1;
	u8 COM0		:2;
	u8 WGM00	:1;
	u8 FOC0		:1;
}TCCR0_T;

typedef struct{
	u8 TOIE0	:1;
	u8 OCIE0	:1;
	u8 RESV		:6;
}TIMSK_t;

typedef struct{
	u8 TOV0		:1;
	u8 OCF0		:1;
	u8 RESV		:6;
}TIFR_t;

#define TCCR0  	((volatile TCCR0_T*)(0x53))
#define TCNT0	*((volatile u8*)(0x52))
#define OCR0	*((volatile u8*)(0x5C))
#define TIMSK	((volatile TIMSK_t*)(0x59))
#define TIFR	((volatile TIFR_t*)(0x58))

/*****************************************************************/
#define RESET			0
#define SET				1
/*****************************************************************/

/*****************************************************************/
#define Force_Output_Compare_DISABLE		0
#define Force_Output_Compare_ENABLE			1
/*****************************************************************/

/*****************************************************************/
// Waveform Generation Mode Bit Description
#define NORMAL_MODE					0
#define PWM_Phase_Correct_MODE		1
#define CTC_MODE					2
#define Fast_PWM_mode				3
/*****************************************************************/

/*****************************************************************/
// Compare Output Mode, non-PWM Mode
#define OC0_disconnected				0
#define Toggle_OC0_on_compare_match		1
#define Clear_OC0_on_compare_match		2
#define Set_OC0_on_compare_match		3
/*****************************************************************/

/*****************************************************************/
// Compare Output Mode, Fast PWM Mode
#define OC0_disconnected		    0
#define Clear_Match_Set_TOP			2
#define Set_Match_Clear_TOP			3
/****************************************************************/

/****************************************************************/
// Compare Output Mode, Phase Correct PWM Mode
#define OC0_disconnected			0
#define Clear_Up_Set_Down			2
#define Set_Up_Clear_Down			3
/****************************************************************/

/****************************************************************/
// Clock Select Bit Description
#define Timer_Counter_stopped			0
#define No_prescaling					1
#define clkIO_8							2
#define clkIO_64						3
#define clkIO_256						4
#define clkIO_1024						5
#define Externa_falling_edge			6
#define Externa_rising_edge				7
/***************************************************************/

/****************************************************************/
// Compare Match Interrupt
#define Compare_Match_Interrupt_Disable		0
#define Compare_Match_Interrupt_Enable		1
/****************************************************************/

/***************************************************************/
// overflow Interrupt
#define Overflow_Interrupt_Disable			0
#define Overflow_Interrupt_Enable			1
/******************************************************************/

#endif /* COTS_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
