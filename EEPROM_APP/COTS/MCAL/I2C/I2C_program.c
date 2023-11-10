/*
 * I2C_program.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Mostafa_Salem
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"

u8 power(u8 x,u8 y){
	u8 res = 1;
	for(u8 i=0;i<y;i++){
		res *= x;
	}
	return res;
}

void I2C_voidInitialize(){

	TWSR->TWPS = I2C_PRESCALER;

	TWBR = ((STSTEM_CLOCK/I2C_CLOCK_FREQUENCY)-16)/(2*(power(4,I2C_PRESCALER)));

	TWCR->TWEN = I2C_ENABLE;

	TWCR->TWEA = I2C_ENABLE;

	TWCR->TWIE = I2C_INTERRUPT_STATUS;

	TWAR->TWGCE = I2C_General_Call_Recognition_STATUS;

	TWAR->TWA = SLAVE_ADDRESS;
}

void I2C_voidStartCondition(){

	TWCR->TWSTO = I2C_DISABLE;
	TWCR->TWSTA = I2C_ENABLE;

	TWCR->TWINT = I2C_ENABLE;

	while(TWCR->TWINT == I2C_DISABLE);

}

void I2C_voidStopCondition(){

	TWCR->TWSTA = I2C_DISABLE;
	TWCR->TWSTO = I2C_ENABLE;

	TWCR->TWINT = I2C_ENABLE;


}

void I2C_voidSendSlaveAddressWrite(u8 Copy_u8SlaveAddress){

	TWDR = (Copy_u8SlaveAddress << 1);

	TWCR->TWINT = I2C_ENABLE;

	while(TWCR->TWINT == I2C_DISABLE);
}

void I2C_voidSendSlaveAddressRead(u8 Copy_u8SlaveAddress){

	TWDR = (Copy_u8SlaveAddress << 1) | (1);

	TWCR->TWINT = I2C_ENABLE;

	while(TWCR->TWINT == I2C_DISABLE);
}

void I2C_voidSendData(u8 Copy_u8Data){

	TWDR = Copy_u8Data;

	TWCR->TWINT = I2C_ENABLE;

	while(TWCR->TWINT == I2C_DISABLE);
}

u8 I2C_u8ReceiveData(){

	u8 data = 0;

	TWCR->TWINT = I2C_ENABLE;

	while(TWCR->TWINT == I2C_DISABLE);

	if(TWSR->TWS == (0x50>>3)){
		data = TWDR;
	}

	return data;
}


