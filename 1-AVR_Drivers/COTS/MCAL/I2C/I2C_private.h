/*
 * I2C_private.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_I2C_I2C_PRIVATE_H_
#define COTS_MCAL_I2C_I2C_PRIVATE_H_

/********************************************************************/
#define I2C_DISABLE			0
#define I2C_ENABLE			1
/********************************************************************/

/*********************************************************************/
#define I2C_PERSCALER_1			0b00
#define I2C_PERSCALER_4			0b01
#define I2C_PERSCALER_16		0b10
#define I2C_PERSCALER_64		0b11
/******************************************************************/

typedef struct{
	u8 TWIE		:1;
	u8 res		:1;
	u8 TWEN		:1;
	u8 TWWC		:1;
	u8 TWSTO	:1;
	u8 TWSTA	:1;
	u8 TWEA		:1;
	u8 TWINT	:1;
}TWCR_t;

typedef struct{
	u8 TWPS		:2;
	u8 res		:1;
	u8 TWS		:5;
}TWSR_t;

typedef struct{
	u8 TWGCE	:1;
	u8 TWA		:7;
}TWAR_t;

#define TWBR		(*((volatile u8*)(0x20)))
#define TWCR		((volatile TWCR_t*)(0x56))
#define TWSR		((volatile TWSR_t*)(0x21))
#define TWDR		(*((volatile u8*)(0x23)))
#define TWAR		((volatile TWAR_t*)(0x22))

#endif /* COTS_MCAL_I2C_I2C_PRIVATE_H_ */
