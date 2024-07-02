/*
 * CFile1.c
 *
 * Created: 9/13/2021 5:06:06 PM
 *  Author:Sara Ahmed
 */ 
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO/DIO_Interface.h"
#include "SSD_Pravite.h"
#include "SSD_Config.h"

void SSD_VoidInit(u8 u8cpy_portindex)
{
  DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN0,DIO_OUT);
  DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN1,DIO_OUT);
  DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN2,DIO_OUT);
  DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN3,DIO_OUT);
  DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN4,DIO_OUT);
  DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN5,DIO_OUT);
  DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN6,DIO_OUT); 
}


void SSD_VoidBCDInit(u8 u8cpy_portindex)
{   
	#if defined LOW_NIBLLE
	 DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN0,DIO_OUT);
	 DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN1,DIO_OUT);
	 DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN2,DIO_OUT);
	 DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN3,DIO_OUT);
	#elif defined HIGH_NIBLLE
	 DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN4,DIO_OUT);
	 DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN5,DIO_OUT);
	 DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN6,DIO_OUT);
	 DIO_VoidSetPinDirection(u8cpy_portindex,DIO_PIN7,DIO_OUT);
	#endif
}

void SSD_VoidWrite(u8 u8cpy_portindex,u8 u8cpy_number)
{
	static u8 arr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x47,0x7F,0x6F};
	u8cpy_number=0x0F & u8cpy_number;   //number form 0 to 9 
	
	#if defined COMMON_CATHODE 
	DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN0,GET_BIT(arr[u8cpy_number],0));	
	DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN1,GET_BIT(arr[u8cpy_number],1));	
	DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN2,GET_BIT(arr[u8cpy_number],2));	
	DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN3,GET_BIT(arr[u8cpy_number],3));	
	DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN4,GET_BIT(arr[u8cpy_number],4));	
	DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN5,GET_BIT(arr[u8cpy_number],5));	
	DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN6,GET_BIT(arr[u8cpy_number],6));	
	
   #elif defined COMMON_ANODE 
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN0,~GET_BIT(arr[u8cpy_number],0));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN1,~GET_BIT(arr[u8cpy_number],1));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN2,~GET_BIT(arr[u8cpy_number],2));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN3,~GET_BIT(arr[u8cpy_number],3));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN4,~GET_BIT(arr[u8cpy_number],4));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN5,~GET_BIT(arr[u8cpy_number],5));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN6,~GET_BIT(arr[u8cpy_number],6));	
   
  #elif defined BCD_MODE && defined LOW_NIBLLE
  DIO_VoidSetLowNibbleValue(u8cpy_portindex,u8cpy_number);
  /*  anther way to write on low nibble
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN0,GET_BIT(u8cpy_number,0));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN1,GET_BIT(u8cpy_number,1));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN2,GET_BIT(u8cpy_number,2));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN3,GET_BIT(u8cpy_number,3));
   */
  
   #elif defined BCD_MODE && defined HIGH_NIBLLE
   DIO_VoidSetHighNibbleValue(u8cpy_portindex,u8cpy_number);
   /* anther way to write on high nibble
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN4,GET_BIT(u8cpy_number,0));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN5,GET_BIT(u8cpy_number,1));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN6,GET_BIT(u8cpy_number,2));
   DIO_VoidSetPinValue(u8cpy_portindex,DIO_PIN7,GET_BIT(u8cpy_number,3))
   */
  #endif 		
}

