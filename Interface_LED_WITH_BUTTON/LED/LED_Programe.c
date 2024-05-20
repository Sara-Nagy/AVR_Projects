/*
 * LED_Programe.c

 *
 *  Created on: Sep 5, 2021
 *      Author: Sara Nagy
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO/DIO_Interface.h"
#include "LED_Pravite.h"
#include "LED_Congfig.h"

void LED_VoidInit(u8 u8cpy_portindex,u8 u8cpy_pinindex)
{
	DIO_VoidSetPinDirection(u8cpy_portindex,u8cpy_pinindex,DIO_OUT);
}

void LED_VoidSet_Led_On(u8 u8cpy_portindex,u8 u8cpy_pinindex)
{
	DIO_VoidSetPinValue(u8cpy_portindex,u8cpy_pinindex,DIO_HIGH);

}

void LED_VoidSet_Led_Off(u8 u8cpy_portindex,u8 u8cpy_pinindex)
{
	DIO_VoidSetPinValue(u8cpy_portindex,u8cpy_pinindex,DIO_LOW);
}

void LED_VoidToggle_Led(u8 u8cpy_portindex,u8 u8cpy_pinindex)
{
	DIO_VoidTogglePin(u8cpy_portindex,u8cpy_pinindex);
}

u8 LED_U8Read_Led(u8 u8cpy_portindex,u8 u8cpy_pinindex)
{ 
	u8 val=0;
	val=DIO_U8GetPinValue(u8cpy_portindex,u8cpy_pinindex);
	return val;
}
