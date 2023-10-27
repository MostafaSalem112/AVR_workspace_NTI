/**********************************************************************/
/*                    Author: Mostafa Mahmoud Salem                   */
/*                    Date: 23/10/2023                                */
/*                    Description: EXTI private                       */
/**********************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#define MCUCR		*((volatile u8*)(0x55))
#define MCUCSR		*((volatile u8*)(0x54))
#define GICR		*((volatile u8*)(0x5B))
#define GIFR		*((volatile u8*)(0x5A))

#define INT0		6
#define INT1 		7
#define INT2		5

#define ISC2		6
#define ISC11		3
#define ISC10		2
#define ISC01		1
#define ISC00		0

#define INTF0		6
#define INTF1		7
#define INTF2		5

#endif // EXTI_PRIVATE_H
