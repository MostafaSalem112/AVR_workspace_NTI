/*****************************************************************************/
/*********************** Author : Mostafa Mahmoud Salem **********************/
/*********************** Date : 24/10/2023              **********************/
/*********************** Description : ACD program      **********************/
/*****************************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"

void (*ADC_GPfun)(void)=NULL;

void ADC_voidInitilize(){

	ADMUX->REFS = Voltage_source;
	ADMUX->ADLAR = ADC_Adjust_Result;

	ADCSRA->ADPS = PRE_SCALER;

	ADCSRA->ADIE = ADC_INTERRUPT_STATUS;

	ADCSRA->ADEN = ENABLE;
}

void ADC_voidEnableAutoTriggerMode(AutoTrigger_t Copy_AutoTriggerSource){

	ADCSRA->ADATE = AUTO_TRIGGER_ENABLE;

	SFIOR->ADTS = Copy_AutoTriggerSource;
}

void ADC_voidSelectChannel(ADC_t Copy_ADCChannel){

	ADMUX->MUX = Copy_ADCChannel;
}

void ADC_voidStartConversion(){

	ADCSRA->ADSC = ENABLE;

	while(ADCSRA->ADIF == 0);
	ADCSRA->ADIF = SET;
}

u16 ADC_u16ReadData(){

	return ADC;
}



void ADC_SetCallBack(void(*ptr)(void)){

	ADC_GPfun=ptr;
}

void __vector_16()__attribute__((signal));   // ADC
void __vector_16(){
	if(ADC_GPfun != NULL){
		ADC_GPfun();
	}
}
