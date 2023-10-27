/**********************************************************************/
/*                    Author: Mostafa Mahmoud Salem                   */
/*                    Date: 23/10/2023                                */
/*                    Description: EXTI program                       */
/**********************************************************************/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

void (*EXTI_GPfun[3])(void);

void EXTI_voidEnable(EXTI_t Copy_EXTILine){

	switch(Copy_EXTILine){
		case EXTI_0:
			SET_BIT(GICR,INT0);
			break;
		case EXTI_1:
			SET_BIT(GICR,INT1);
			break;
		case EXTI_2:
			SET_BIT(GICR,INT2);
			break;
	}
}

void EXTI_voidDisable(EXTI_t Copy_EXTILine){

	switch(Copy_EXTILine){
		case EXTI_0:
			CLR_BIT(GICR,INT0);
			break;
		case EXTI_1:
			CLR_BIT(GICR,INT1);
			break;
		case EXTI_2:
			CLR_BIT(GICR,INT2);
			break;
	}
}
void EXTI_voidSetSenseCase(EXTI_t Copy_EXTILine,SENSE_t Copy_SenseCase){

	switch(Copy_EXTILine){
		case EXTI_0:

			switch(Copy_SenseCase){
				case LOW_LEVEL_SENSE:
					CLR_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
					break;
				case LOGICL_CHANGE_SENSE:
					SET_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
					break;
				case FALLING_EDGE_SENSE:
					CLR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
				case RISING_EDGE_SENSE:
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
			}

			break;
		case EXTI_1:

			switch(Copy_SenseCase){
				case LOW_LEVEL_SENSE:
					CLR_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);
					break;
				case LOGICL_CHANGE_SENSE:
					SET_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC01);
					break;
				case FALLING_EDGE_SENSE:
					CLR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					break;
				case RISING_EDGE_SENSE:
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					break;
			}

			break;
		case EXTI_2:

			switch(Copy_SenseCase){
				case FALLING_EDGE_SENSE:
					CLR_BIT(MCUCSR,ISC2);
					break;
				case RISING_EDGE_SENSE:
					SET_BIT(MCUCSR,ISC2);
					break;
			}

			break;
	}

}

u8 EXTI_u8GetInterruptFlag(EXTI_t Copy_EXTILine){

	u8 Local_u8Flag=0;

	switch(Copy_EXTILine){
		case EXTI_0:
			Local_u8Flag = GET_BIT(GIFR,INTF0);
			break;
		case EXTI_1:
			Local_u8Flag = GET_BIT(GIFR,INTF1);
			break;
		case EXTI_2:
			Local_u8Flag = GET_BIT(GIFR,INTF2);
			break;
	}

	return Local_u8Flag;
}

void EXTI_voidClearInterruptFlag(EXTI_t Copy_EXTILine){

	switch(Copy_EXTILine){
		case EXTI_0:
			CLR_BIT(GIFR,INTF0);
			break;
		case EXTI_1:
			CLR_BIT(GIFR,INTF1);
			break;
		case EXTI_2:
			CLR_BIT(GIFR,INTF2);
			break;
	}
}

void EXTI_voidSetInterruptFlag(EXTI_t Copy_EXTILine){

	switch(Copy_EXTILine){
		case EXTI_0:
			SET_BIT(GIFR,INTF0);
			break;
		case EXTI_1:
			SET_BIT(GIFR,INTF1);
			break;
		case EXTI_2:
			SET_BIT(GIFR,INTF2);
			break;
	}
}

void EXTI_SetCallBack(EXTI_t Copy_EXTILine,void(*ptr)(void)){

	switch(Copy_EXTILine){
		case EXTI_0:
			EXTI_GPfun[0]=ptr;
			break;
		case EXTI_1:
			EXTI_GPfun[1]=ptr;
			break;
		case EXTI_2:
			EXTI_GPfun[2]=ptr;
			break;
	}
}

void __vector_1()__attribute__((signal));   // EXTI0
void __vector_1(){

	if(EXTI_GPfun[0]!=NULL){
		EXTI_GPfun[0]();
	}
}

void __vector_2()__attribute__((signal));   // EXTI1
void __vector_2(){

	if(EXTI_GPfun[1]!=NULL){
		EXTI_GPfun[1]();
	}
}

void __vector_3()__attribute__((signal));   // EXTI2
void __vector_3(){

	if(EXTI_GPfun[2]!=NULL){
		EXTI_GPfun[2]();
	}
}
