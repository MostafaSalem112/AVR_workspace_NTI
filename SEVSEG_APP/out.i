# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.c"







# 1 "COTS/LIB/Bit_Math.h" 1
# 9 "main.c" 2
# 1 "COTS/LIB/STD_Types.h" 1
# 11 "COTS/LIB/STD_Types.h"
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;
# 10 "main.c" 2
# 1 "COTS/MCAL/DIO/DIO_interface.h" 1
# 45 "COTS/MCAL/DIO/DIO_interface.h"
void DIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortDir);
void DIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue);
void DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir);
void DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
u8 DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);
void DIO_voidTogglePinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);
# 11 "main.c" 2
# 1 "COTS/HAL/SevenSegment/SEVSEG_interface.h" 1
# 15 "COTS/HAL/SevenSegment/SEVSEG_interface.h"
void SEVSEG_voidInitialize();
void SEVSEG_voidEnableSegment(u8 Copy_u8SegmentNum);
void SEVSEG_voidDisableSegment(u8 Copy_u8SegmentNum);
void SEVSEG_voidWriteNumber(u8 Copy_u8Number);
# 12 "main.c" 2

void delay(void){

 u64 wait;
 for(u32 i=0;i<10000;i++){
  wait=0;
  while(wait++);
 }
}

int main(){

 SEVSEG_voidInitialize();
 SEVSEG_voidEnableSegment(4);

 while(1){
  for(u8 i=0;i<10;i++){
   SEVSEG_voidWriteNumber(i);
   delay();
  }
 }

 return 0;
}
