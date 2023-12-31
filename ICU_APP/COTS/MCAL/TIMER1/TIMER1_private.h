/*
 * TIMER1_private.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define COTS_MCAL_TIMER1_TIMER1_PRIVATE_H_


#define MAX_16BIT_REG		0xFFFF
#define MAX_8BIT_REG		0x00FF
#define MAX_9BIT_REG		0x01FF
#define MAX_10BIT_REG		0x03FF

#define MICROS_IN_SEC		1000000
#define MICROS_IN_MILLI		1000

typedef struct{
	u8 WGM1		:2;
	u8 FOC1B	:1;
	u8 FOC1A	:1;
	u8 COM1B	:2;
	u8 COM1A	:2;
}TCCR1A_t;

typedef struct{
	u8 CS1		:3;
	u8 WGM1		:2;
	u8 RES0		:1;
	u8 ICES1	:1;
	u8 ICNC1	:1;
}TCCR1B_t;

typedef struct{
	u8 RES0		:2;
	u8 TOIE1	:1;
	u8 OCIE1B	:1;
	u8 OCIE1A	:1;
	u8 TICIE1	:1;
	u8 RES1		:2;
}TIMSK1_t;

typedef struct{
	u8 RES0		:2;
	u8 TOV1		:1;
	u8 OCF1B	:1;
	u8 OCF1A	:1;
	u8 ICF1		:1;
	u8 RES1		:2;
}TIFR1_t;


#define TCCR1A		((volatile TCCR1A_t*)(0x4F))
#define TCCR1B		((volatile TCCR1B_t*)(0x4E))
#define TCNT1		(*((volatile u16*)(0x4C)))
#define OCR1A		(*((volatile u16*)(0x4A)))
#define OCR1B		(*((volatile u16*)(0x48)))
#define ICR1		(*((volatile u16*)(0x46)))
#define TIMSK1		((volatile TIMSK1_t*)(0x59))
#define TIFR1		((volatile TIFR1_t*)(0x58))

/****************************************************************************************/
#define RESET			0
#define SET				1
/****************************************************************************************/

/****************************************************************************************/
#define T1_DISABLE			0
#define T1_ENABLE			1
/****************************************************************************************/

/****************************************************************************************/
// Compare Output Mode, non-PWM
#define OC1_disconnected					0b00
#define Toggle_OC1_on_compare_match			0b01
#define Clear_OC1_on_compare_match			0b10
#define Set_OC1_on_compare_match			0b11
/****************************************************************************************/

/****************************************************************************************/
// Compare Output Mode, Fast PWM
//#define OC1_disconnected					0b00
#define Toggle_OC1A_on_CompareMatch			0b01
#define Clear_Match_Set_Top					0b10
#define Set_Match_Clear_Top					0b11
/****************************************************************************************/

/****************************************************************************************/
// Compare Output Mode, Phase Correct and Phase and Frequency Correct
//#define OC1_disconnected					0b00
#define Toggle_OC1A_on_CompareMatch			0b01
#define Clear_Up_Set_Down					0b10
#define Set_Up_Clear_Down					0b11
/****************************************************************************************/

/****************************************************************************************/
// Waveform Generation Mode
#define Normal_MODE							0b0000
#define PWM_Phase_Correct_8bit				0b0001
#define PWM_Phase_Correct_9bit				0b0010
#define PWM_Phase_Correct_10bit				0b0011
#define CTC_OCR1A							0b0100
#define Fast_PWM_8bit						0b0101
#define Fast_PWM_9bit						0b0110
#define Fast_PWM_10bit						0b0111
#define PWM_Phase_Freq_Correct_ICR1			0b1000
#define PWM_Phase_Freq_Correct_OCR1A		0b1001
#define PWM_Phase_Correct_ICR1				0b1010
#define PWM_Phase_Correct_OCR1A				0b1011
#define CTC_ICR1							0b1100
#define Fast_PWM_ICR1						0b1110
#define Fast_PWM_OCR1A						0b1111
/****************************************************************************************/

/****************************************************************************************/
// Clock Select Bit Description
#define Timer_Counter_stopped			0
#define No_prescaling					1
#define clkIO_8							2
#define clkIO_64						3
#define clkIO_256						4
#define clkIO_1024						5
#define Externa_falling_edge			6
#define Externa_rising_edge				7
/****************************************************************************************/

#define Input_Capture_Falling_Edge		0
#define Input_Capture_rising_Edge		1
/****************************************************************************************/

#endif /* COTS_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
