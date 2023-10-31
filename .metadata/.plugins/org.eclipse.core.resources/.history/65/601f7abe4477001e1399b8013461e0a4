/******************************************************/
/************ Author : Mostafa Mahmoud Salem **********/
/************ Date : 21/10/2023              **********/
/************ Description : binary search program *****/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"

s8 binary_search(u8 *arr,u8 size,u8 key){

    u8 l=0;
    u8 u=size-1;
    u8 m;
    s8 index=-1;

    while(l<=u){
        m=(u+l)/2;
        if(arr[m]==key){
            index=m;
            break;
        }else if(arr[m]>key){
            u=m-1;
        }else if(arr[m]<key){
            l=m+1;
        }
    }

    return index;
}