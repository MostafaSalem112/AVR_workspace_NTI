/**********************************************************************/
/*                    Author: Mostafa Salem                           */
/*                    Date: 20/10/2023                                */
/*                    Description: switches program                   */
/**********************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SWITCH_private.h"
#include "SWITCH_config.h"
#include "SWITCH_interface.h"

void SWITCH_voidInitialize(switches_t Copy_SwitchNumber){

	u8 Local_u8SwitchRow = (Copy_SwitchNumber+3)/4;
	u8 Local_u8SwitchCol = ((Copy_SwitchNumber-1)%4)+1;

	switch(Local_u8SwitchRow){
	case 1:
		DIO_voidSetPinDirection(ROW_PORT,ROW_1_PIN,PIN_OUTPUT);
		DIO_voidSetPinValue(ROW_PORT,ROW_1_PIN,PIN_LOW);
		break;
	case 2:
		DIO_voidSetPinDirection(ROW_PORT,ROW_2_PIN,PIN_OUTPUT);
		DIO_voidSetPinValue(ROW_PORT,ROW_2_PIN,PIN_LOW);
		break;
	case 3:
		DIO_voidSetPinDirection(ROW_PORT,ROW_3_PIN,PIN_OUTPUT);
		DIO_voidSetPinValue(ROW_PORT,ROW_3_PIN,PIN_LOW);
		break;
	case 4:
		DIO_voidSetPinDirection(ROW_PORT,ROW_4_PIN,PIN_OUTPUT);
		DIO_voidSetPinValue(ROW_PORT,ROW_4_PIN,PIN_LOW);
		break;
	}

	switch(Local_u8SwitchCol){
		case 1:
			DIO_voidSetPinDirection(COL_PORT,COL_1_PIN,PIN_INPUT);
			DIO_voidSetPinValue(COL_PORT,COL_1_PIN,PIN_HIGH);
			break;
		case 2:
			DIO_voidSetPinDirection(COL_PORT,COL_2_PIN,PIN_INPUT);
			DIO_voidSetPinValue(COL_PORT,COL_2_PIN,PIN_HIGH);
			break;
		case 3:
			DIO_voidSetPinDirection(COL_PORT,COL_3_PIN,PIN_INPUT);
			DIO_voidSetPinValue(COL_PORT,COL_3_PIN,PIN_HIGH);
			break;
		case 4:
			DIO_voidSetPinDirection(COL_PORT,COL_4_PIN,PIN_INPUT);
			DIO_voidSetPinValue(COL_PORT,COL_4_PIN,PIN_HIGH);
			break;
	}

}

u8 SWITCH_u8GetSwitchValue(switches_t Copy_SwitchNumber){

	u8 Local_u8SwitchCol = ((Copy_SwitchNumber-1)%4)+1;

	switch(Local_u8SwitchCol){
		case 1:
			return DIO_u8GetPinValue(COL_PORT,COL_1_PIN);
			break;
		case 2:
			return DIO_u8GetPinValue(COL_PORT,COL_2_PIN);
			break;
		case 3:
			return DIO_u8GetPinValue(COL_PORT,COL_3_PIN);
			break;
		case 4:
			return DIO_u8GetPinValue(COL_PORT,COL_4_PIN);
			break;
	}
	return 0;
}
