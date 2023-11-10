/*
 * I2C_interface.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Mostafa_Salem
 */

#ifndef COTS_MCAL_I2C_I2C_INTERFACE_H_
#define COTS_MCAL_I2C_I2C_INTERFACE_H_

void I2C_voidInitialize();
void I2C_voidStartCondition();
void I2C_voidStopCondition();
void I2C_voidSendSlaveAddressWrite(u8 Copy_u8SlaveAddress);
void I2C_voidSendSlaveAddressRead(u8 Copy_u8SlaveAddress);
void I2C_voidSendData(u8 Copy_u8Data);
u8 I2C_u8ReceiveData();

#endif /* COTS_MCAL_I2C_I2C_INTERFACE_H_ */
