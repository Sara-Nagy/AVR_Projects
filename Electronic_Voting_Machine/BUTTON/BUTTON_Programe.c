/*
 * BUTTON_Programe.c
 *
 *  Created on: Sep 6, 2021
 *		   Author: Sara Nagy
 */

#include"../LIB/BIT_MATH.h"
#include"../LIB/STD_TYPES.h"
#include"../DIO/DIO_Interface.h"
#include"BUTTON_Config.h"
#include"BUTTON_Pravite.h"

void BUTTON_VoidInit(u8 u8cpy_portindex,u8 u8cpy_pinindex)
{
	DIO_VoidSetPinDirection(u8cpy_portindex,u8cpy_pinindex,DIO_IN);

}

void BUTTON_VoidConnect_Internal_Pullup(u8 u8cpy_portindex,u8 u8cpy_pinindex,u8 u8cpy_typeofconnect)
{
	if(u8cpy_typeofconnect==1)
	{
		DIO_VoidConnectPullUpPin(u8cpy_portindex,u8cpy_pinindex,DIO_SET_PULLUP);
	}   
	else if(u8cpy_typeofconnect==2) 
	{
		DIO_VoidConnectPullUpPin(u8cpy_portindex,u8cpy_pinindex,DIO_clr_PULLUP);
	
	}
}

u8 BUTTON_U8GetValue(u8 u8cpy_portindex,u8 u8cpy_pinindex)
{
	 u8 status=0;
	 status=DIO_U8GetPinValue(u8cpy_portindex,u8cpy_pinindex);

	return status;
}
