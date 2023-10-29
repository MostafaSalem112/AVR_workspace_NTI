/*
 * TIMER0_config.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_TIMER0_TIMER0_CONFIG_H_
#define COTS_MCAL_TIMER0_TIMER0_CONFIG_H_

/*************************************************************/
#define SYSTEM_CLOCK_FREQUENCY			16000000
/************************************************************/

/***********************************************************/
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
/*************************************************************/

/***************************************************************************/
/*
 * Force_Output_Compare_DISABLE
 * Force_Output_Compare_ENABLE
 */
#define Force_Output_Compare_STATUS			Force_Output_Compare_DISABLE
/****************************************************************************/

/***************************************************************************/
/*
 * NORMAL_MODE
 * PWM_Phase_Correct_MODE
 * CTC_MODE
 * Fast_PWM_mode
 */

#define TIMER_MODE		NORMAL_MODE
/***************************************************************************/

/***************************************************************************/
/*
 * OC0_disconnected
 *
 * @ non-PWM Mode
 * Toggle_OC0_on_compare_match
 * Clear_OC0_on_compare_match
 * Set_OC0_on_compare_match
 *
 * @ Fast PWM Mode
 * Clear_Match_Set_TOP
 * Set_Match_Clear_TOP
 *
 * @ Phase Correct PWM Mode
 * Clear_Up_Set_Down
 * Set_Up_Clear_Down
 */

#define Compare_Output_Mode			OC0_disconnected
/*******************************************************************************/

/********************************************************************************/
/*
 * Overflow_Interrupt_Disable
 * Overflow_Interrupt_Enable
 */
#define Overflow_Interrupt_Status			Overflow_Interrupt_Enable
/*********************************************************************************/

/*******************************************************************************/
/*
 * Compare_Match_Interrupt_Disable
 * Compare_Match_Interrupt_Enable
 */
#define Compare_Match_Interrupt_Status		Compare_Match_Interrupt_Enable
/*********************************************************************************/

#endif /* COTS_MCAL_TIMER0_TIMER0_CONFIG_H_ */
