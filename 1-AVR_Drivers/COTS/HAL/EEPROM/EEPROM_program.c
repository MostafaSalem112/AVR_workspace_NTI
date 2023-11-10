/*
 * EEPROM_program.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Mostafa_Salem
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/I2C/I2C_interface.h"

void EEPROM_voidInitialze(){

	I2C_voidInitialize();
}

u8 EEPROM_u8ReadData(u16 Copt_u16Address){

	u8 data;

	u8 hardWare_address = 0b01010000;
	u8 data_address = (u8)Copt_u16Address;

	hardWare_address |= (Copt_u16Address>>8);

	I2C_voidStartCondition();
	I2C_voidSendSlaveAddressWrite(hardWare_address);

	I2C_voidSendData(data_address);

	I2C_voidStartCondition();
	I2C_voidSendSlaveAddressRead(hardWare_address);

	data = I2C_u8ReceiveData();

	I2C_voidStopCondition();

	return data;
}

void EEPROM_voidWriteData(u16 Copt_u16Address,u8 Copy_u8Data){

	u8 hardWare_address = 0b01010000;
	u8 data_address = (u8)Copt_u16Address;

	hardWare_address |= (Copt_u16Address>>8);

	I2C_voidStartCondition();
	I2C_voidSendSlaveAddressWrite(hardWare_address);

	I2C_voidSendData(data_address);
	I2C_voidSendData(Copy_u8Data);

	I2C_voidStopCondition();

}
