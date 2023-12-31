/*
 * TIMER1_config.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_TIMER1_TIMER1_CONFIG_H_
#define COTS_MCAL_TIMER1_TIMER1_CONFIG_H_

/****************************************************************************************/
#define SYSTEM_CLOCK_FREQUENCY			8000000
/****************************************************************************************/

/****************************************************************************************/
// Clock Select Bit Description
/*
 * No_prescaling
 * clkIO_8
 * clkIO_64
 * clkIO_256
 * clkIO_1024
 * Externa_falling_edge
 * Externa_rising_edge
 */
#define CLOCK_PRESCALER		clkIO_8
/****************************************************************************************/

/****************************************************************************************/
/*
 * DISABLE
 * ENABLE
 */
#define Force_Output_Compare_A_STATUS		T1_DISABLE
#define Force_Output_Compare_B_STATUS		T1_DISABLE
/****************************************************************************************/

/****************************************************************************************/
// Waveform Generation Mode
/*
 * Normal_MODE
 * PWM_Phase_Correct_8bit
 * PWM_Phase_Correct_9bit
 * PWM_Phase_Correct_10bit
 * CTC_OCR1A
 * Fast_PWM_8bit
 * Fast_PWM_9bit
 * Fast_PWM_10bit
 * PWM_Phase_Freq_Correct_ICR1
 * PWM_Phase_Freq_Correct_OCR1A
 * PWM_Phase_Correct_ICR1
 * PWM_Phase_Correct_OCR1A
 * CTC_ICR1
 * Fast_PWM_ICR1
 * Fast_PWM_OCR1A
 */
#define TIMER_MODE		Fast_PWM_ICR1
/****************************************************************************************/

/****************************************************************************************/
/*
 * OC0_disconnected
 *
 * @ non-PWM Mode
 * Toggle_OC1_on_compare_match
 * Clear_OC1_on_compare_match
 * Set_OC1_on_compare_match
 *
 * @ Fast PWM Mode
 * Toggle_OC1A_on_CompareMatch
 * Clear_Match_Set_Top
 * Set_Match_Clear_Top
 *
 * @ Phase Correct PWM Mode and Frequency Correct
 * Toggle_OC1A_on_CompareMatch
 * Clear_Up_Set_Down
 * Set_Up_Clear_Down
 */
#define Compare_Output_Mode_A			Clear_Match_Set_Top
/****************************************************************************************/

/****************************************************************************************/
/*
 * OC0_disconnected
 *
 * @ non-PWM Mode
 * Toggle_OC1_on_compare_match
 * Clear_OC1_on_compare_match
 * Set_OC1_on_compare_match
 *
 * @ Fast PWM Mode
 * Clear_Match_Set_Top
 * Set_Match_Clear_Top
 *
 * @ Phase Correct PWM Mode and Frequency Correct
 * Clear_Up_Set_Down
 * Set_Up_Clear_Down
 */
#define Compare_Output_Mode_B			Clear_Match_Set_Top
/****************************************************************************************/

/****************************************************************************************/
/*
 * T1_DISABLE
 * T1_ENABLE
 */
#define Input_Capture_Interrupt_STATUS					T1_DISABLE
#define Output_Compare_A_Match_Interrupt_STATUS			T1_DISABLE
#define Output_Compare_B_Match_Interrupt_STATUS			T1_DISABLE
#define Overflow_Interrupt_STATUS						T1_DISABLE
/****************************************************************************************/

/****************************************************************************************/
/*
 * DISABLE
 * ENABLE
 */
#define Input_Capture_Noise_Canceler_STATUS				T1_DISABLE
/****************************************************************************************/

/****************************************************************************************/
// Input Capture Edge Select
/*
 * Input_Capture_Falling_Edge
 * Input_Capture_rising_Edge
 */
#define Input_Capture_Edge			Input_Capture_Falling_Edge

#endif /* COTS_MCAL_TIMER1_TIMER1_CONFIG_H_ */
