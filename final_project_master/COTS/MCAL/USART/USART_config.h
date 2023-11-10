/*
 * USART_config.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_USART_USART_CONFIG_H_
#define COTS_MCAL_USART_USART_CONFIG_H_

/*********************************************************************/
#define CLOCK_FREQUENCY		8000000
#define BAUD_RATE			9600
/*********************************************************************/

/*********************************************************************/
/*
 * USART_DISABLE
 * USART_ENABLE
 */
#define Double_Transmission_Speed_STATUS			USART_DISABLE
/*********************************************************************/

/*********************************************************************/
/*
 * USART_DISABLE
 * USART_ENABLE
 */
#define RX_Complete_Interrupt_STATUS				USART_ENABLE
#define TX_Complete_Interrupt_STATUS				USART_DISABLE
#define Data_Register_Empty_Interrupt_STATUS		USART_DISABLE
/*********************************************************************/

/*********************************************************************/
/*
 * Asynchronous_Operation
 * Synchronous_Operation
 */
#define OPERATION_MODE			Asynchronous_Operation
/**********************************************************************/

/***********************************************************************/
/*
 * DISABLE_POLARITY
 * EVEN_POLARITY
 * ODD_POLARITY
 */
#define POLARITY_CHECK_MODE				DISABLE_POLARITY
/*************************************************************************/

/************************************************************************/
/*
 * STOP_1_BIT
 * STOP_2_BITS
 */
#define STOP_BIT_MODE		STOP_1_BIT
/************************************************************************/

/**************************************************************************/
/*
 * BITS_5
 * BITS_6
 * BITS_7
 * BITS_8
 * BITS_9
 */
#define CHAR_SIZE			BITS_8
/*****************************************************************************/

/*******************************************************************/
/*
 * Transmitte_At_Rising_Edge
 * Transmitte_At_Falling_Edge
 */
#define CLOCK_POLARITY		Transmitte_At_Rising_Edge
/***************************************************************************/

#endif /* COTS_MCAL_USART_USART_CONFIG_H_ */
