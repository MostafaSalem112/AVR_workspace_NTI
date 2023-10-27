/********************************************************************/
/******************** Author: Mostafa Mahmoud Salem *****************/
/******************** Date  : 25/10/2023            *****************/
/******************** Description : LMC35 interface *****************/
/********************************************************************/

#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

typedef enum{
	LM35_ADC0,
	LM35_ADC1,
	LM35_ADC2,
	LM35_ADC3,
	LM35_ADC4,
	LM35_ADC5,
	LM35_ADC6,
	LM35_ADC7
}LM35_ADC_t;

void LM35_voidInitialize(LM35_ADC_t Copy_ADCChannel);
u16 LM_35_u16GetTemperature();

#endif // LM35_INTERFACE_H
