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

typedef enum{
	Free_Running_mode,
	Analog_Comparator,
	External_Interrupt_Request_0,
	Timer_Counter0_Compare_Match,
	Timer_Counter0_Overflow,
	Timer_Counter_Compare_Match_B,
	Timer_Counter1_Overflow,
	Timer_Counter1_Capture_Event,
}AutoTrigger_t;


/***************** prototypes **********************************************/

void ADC_voidInitilize();
void ADC_voidEnableAutoTriggerMode(AutoTrigger_t Copy_AutoTriggerSource);
void ADC_voidSelectChannel(ADC_t Copy_ADCChannel);
void ADC_voidStartConversion();
u16 ADC_u16ReadData();
void ADC_SetCallBack(void(*ptr)(void));

#endif // ADC_INTERFACE_H
