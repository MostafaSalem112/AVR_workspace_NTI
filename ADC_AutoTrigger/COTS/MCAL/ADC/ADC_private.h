/*****************************************************************************/
/*********************** Author : Mostafa Mahmoud Salem **********************/
/*********************** Date : 24/10/2023              **********************/
/*********************** Description : ACD private      **********************/
/*****************************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


typedef struct{
	u8 MUX   :5;
	u8 ADLAR :1;
	u8 REFS  :2;
}ADMUX_t;

typedef struct{
	u8 ADPS  :3;
	u8 ADIE  :1;
	u8 ADIF  :1;
	u8 ADATE :1;
	u8 ADSC  :1;
	u8 ADEN  :1;
}ADCSRA_t;

typedef struct{
	u8 :5;
	u8 ADTS :3;
}SFIOR_t;

#define ADMUX		((volatile ADMUX_t*)(0x27))
#define ADCSRA		((volatile ADCSRA_t*)(0x26))
#define ADC_L		*((volatile u8*)(0x24))
#define ADC_H		*((volatile u8*)(0x25))
#define ADC			*((volatile u16*)(0x24))
#define SFIOR		((volatile SFIOR_t*)(0x50))


/********************************************************/
#define DISABLE		0
#define ENABLE		1
/********************************************************/

/********************************************************/
#define RESET		0
#define SET			1
/********************************************************/

/********************************************************/
#define AREF		0
#define AVCC		1
#define Internal	3
/********************************************************/

/********************************************************/
#define RIGHT_ADJAST	0
#define LEFT_ADJAST		1
/********************************************************/

/********************************************************/
#define AUTO_TRIGGER_DISABLE		0
#define AUTO_TRIGGER_ENABLE			1
/********************************************************/

/********************************************************/
#define DIVIDE_2		0b000
#define DIVIDE_4		0b010
#define DIVIDE_8		0b011
#define DIVIDE_16		0b100
#define DIVIDE_32		0b101
#define DIVIDE_64		0b110
#define DIVIDE_128		0b111
/********************************************************/

/********************************************************/
#define ADC_INTERRUPT_DISABLE		0
#define ADC_INTERRUPT_ENABLE		1
/********************************************************/

#endif // ADC_PRIVATE_H
