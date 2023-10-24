/*****************************************************************************/
/*********************** Author : Mostafa Mahmoud Salem **********************/
/*********************** Date : 24/10/2023              **********************/
/*********************** Description : ACD interface    **********************/
/*****************************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_t;


/***************** prototypes **********************************************/

void ADC_voidInitilize();
void ADC_voidSelectChannel(ADC_t Copy_ADCChannel);
u16 ADC_voidStartConversion();
void ADC_SetCallBack(void(*ptr)(void));

#endif // ADC_INTERFACE_H
