/**********************************************************************/
/*                    Author: Mostafa Salem                           */
/*                    Date: 20/10/2023                                */
/*                    Description: DIO interface                      */
/**********************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define PORTA (u8)(0x00)
#define PORTB (u8)(0x01)
#define PORTC (u8)(0x02)
#define PORTD (u8)(0x03)

#define PIN0 (u8)(0x00)
#define PIN1 (u8)(0x01)
#define PIN2 (u8)(0x02)
#define PIN3 (u8)(0x03)
#define PIN4 (u8)(0x04)
#define PIN5 (u8)(0x05)
#define PIN6 (u8)(0x06)
#define PIN7 (u8)(0x07)

#define PIN_INPUT (u8)(0x00)
#define PIN_OUTPUT (u8)(0x01)

#define PIN_LOW (u8)(0x00)
#define PIN_HIGH (u8)(0x01)

#define PORT_INPUT (u8)(0x00)
#define PORT_OUTPUT (u8)(0xff)

#define HALF_IN_OUT (u8)(0x0f)
#define HALF_OUT_IN (u8)(0xf0)

#define PORT_LOW (u8)(0x00)
#define PORT_HIGH (u8)(0xff)

#define HALF_LOW_HIGH (u8)(0x0f)
#define HALF_HIGH_LOW (u8)(0xf0)


//============== prototype ======================

void DIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortDir);
void DIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue);
void DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir);
void DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
u8   DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);
void DIO_voidTogglePinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);

#endif // DIO_INTERFACE_H
