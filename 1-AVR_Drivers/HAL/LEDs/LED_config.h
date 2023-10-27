/****************************************************************************/
/************************* Author : Mostafa Mahmoud Salem      **************/
/************************* Date : 22/10/2023                   **************/
/************************* Description : LED configurations    **************/
/****************************************************************************/

#ifndef LED_CONFIG_H
#define LED_CONFIG_H

#define RED_LED_PORT		PORTB
#define RED_LED_PIN			PIN7

#define GREEN_LED_PORT		PORTA
#define GREEN_LED_PIN		PIN4

#define BLUE_LED_PORT		PORTA
#define BLUE_LED_PIN		PIN5

#define YELLOW_LED_PORT		PORTA
#define YELLOW_LED_PIN		PIN6

#define PORTS_ARR	{RED_LED_PORT,GREEN_LED_PORT,BLUE_LED_PORT,YELLOW_LED_PORT}
#define PINS_ARR	{RED_LED_PIN,GREEN_LED_PIN,BLUE_LED_PIN,YELLOW_LED_PIN}

#endif // LED_CONFIG_H
