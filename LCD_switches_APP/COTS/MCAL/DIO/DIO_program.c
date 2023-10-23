/**********************************************************************/
/*                    Author: Mostafa Salem                           */
/*                    Date: 20/10/2023                                */
/*                    Description: DIO program                        */
/**********************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

void DIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortDir){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: DDRA_REG=Copy_u8PortDir;break;
		case PORTB/*Port B*/: DDRB_REG=Copy_u8PortDir;break;
		case PORTC/*Port C*/: DDRC_REG=Copy_u8PortDir;break;
		case PORTD/*Port D*/: DDRD_REG=Copy_u8PortDir;break;
	}
}

void DIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: PORTA_REG=Copy_u8PortValue;break;
		case PORTB/*Port B*/: PORTB_REG=Copy_u8PortValue;break;
		case PORTC/*Port C*/: PORTC_REG=Copy_u8PortValue;break;
		case PORTD/*Port D*/: PORTD_REG=Copy_u8PortValue;break;
	}
}

void DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir){
	if(Copy_u8PinDir==PIN_OUTPUT){     //output
		switch(Copy_u8PortID){
			case PORTA/*Port A*/: SET_BIT(DDRA_REG,Copy_u8PinID);break;
			case PORTB/*Port B*/: SET_BIT(DDRB_REG,Copy_u8PinID);break;
			case PORTC/*Port C*/: SET_BIT(DDRC_REG,Copy_u8PinID);break;
			case PORTD/*Port D*/: SET_BIT(DDRD_REG,Copy_u8PinID);break;
		}
	}
	else if(Copy_u8PinDir==PIN_INPUT){ //input
		switch(Copy_u8PortID){
			case PORTA/*Port A*/: CLR_BIT(DDRA_REG,Copy_u8PinID);break;
			case PORTB/*Port B*/: CLR_BIT(DDRB_REG,Copy_u8PinID);break;
			case PORTC/*Port C*/: CLR_BIT(DDRC_REG,Copy_u8PinID);break;
			case PORTD/*Port D*/: CLR_BIT(DDRD_REG,Copy_u8PinID);break;
		}
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue){
	if(Copy_u8PinValue==PIN_HIGH){      //high
		switch(Copy_u8PortID){
			case PORTA/*Port A*/: SET_BIT(PORTA_REG,Copy_u8PinID);break;
			case PORTB/*Port B*/: SET_BIT(PORTB_REG,Copy_u8PinID);break;
			case PORTC/*Port C*/: SET_BIT(PORTC_REG,Copy_u8PinID);break;
			case PORTD/*Port D*/: SET_BIT(PORTD_REG,Copy_u8PinID);break;
		}
	}
	else if(Copy_u8PinValue==PIN_LOW){  //low
		switch(Copy_u8PortID){
			case PORTA/*Port A*/: CLR_BIT(PORTA_REG,Copy_u8PinID);break;
			case PORTB/*Port B*/: CLR_BIT(PORTB_REG,Copy_u8PinID);break;
			case PORTC/*Port C*/: CLR_BIT(PORTC_REG,Copy_u8PinID);break;
			case PORTD/*Port D*/: CLR_BIT(PORTD_REG,Copy_u8PinID);break;
		}
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID){
	u8 value=0;
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: value=GET_BIT(PINA_REG,Copy_u8PinID);break;
		case PORTB/*Port B*/: value=GET_BIT(PINB_REG,Copy_u8PinID);break;
		case PORTC/*Port C*/: value=GET_BIT(PINC_REG,Copy_u8PinID);break;
		case PORTD/*Port D*/: value=GET_BIT(PIND_REG,Copy_u8PinID);break;
	}
	return value;
}

void DIO_voidTogglePinValue(u8 Copy_u8PortID,u8 Copy_u8PinID){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: TOG_BIT(PORTA_REG,Copy_u8PinID);break;
		case PORTB/*Port B*/: TOG_BIT(PORTB_REG,Copy_u8PinID);break;
		case PORTC/*Port C*/: TOG_BIT(PORTC_REG,Copy_u8PinID);break;
		case PORTD/*Port D*/: TOG_BIT(PORTD_REG,Copy_u8PinID);break;
	}
}
