/**********************************************************************/
/*                    Author: Mostafa Salem                           */
/*                    Date: 20/10/2023                                */
/*                    Description: Bit Math                           */
/**********************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define GET_BIT(reg,bitNum) (reg>>bitNum)&1
#define SET_BIT(reg,bitNum) reg|=(1<<bitNum)
#define CLR_BIT(reg,bitNum) reg&=(~(1<<bitNum))
#define TOG_BIT(reg,bitNum) reg^=(1<<bitNum)

#define SET_BYTE(reg,val)	reg=val
#define CONC_BYTE(b7,b6,b5,b,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif //BIT_MATH_H
