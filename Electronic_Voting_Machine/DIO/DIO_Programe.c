/*
 * DIO_Programe.c
 *
 * Created: 9/8/2021 11:48:51 AM
 *  Author: Sara Nagy
 */ 
 
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO_Pravite.h"
#include "DIO_Config.h"
void DIO_VoidSetPinDirection(u8 u8cpy_portindex ,u8 u8cpy_pinindex,u8 u8cpy_direction)
{
	if( u8cpy_direction==1)
	{
		switch(u8cpy_portindex)
		{
		case 1:
			SET_BIT(DDRA,u8cpy_pinindex); break;
		case 2:
			SET_BIT(DDRB,u8cpy_pinindex); break;

		case 3:
			SET_BIT(DDRC,u8cpy_pinindex); break;

		case 4:
			SET_BIT(DDRD,u8cpy_pinindex); break;
		}
	}
	else if( u8cpy_direction ==2)
	{
		switch(u8cpy_portindex)
		{
		case 1:
			CLR_BIT(DDRA,u8cpy_pinindex); break;
		case 2:
			CLR_BIT(DDRB,u8cpy_pinindex); break;

		case 3:
			CLR_BIT(DDRC,u8cpy_pinindex); break;

		case 4:
			CLR_BIT(DDRD,u8cpy_pinindex); break;
		}
	}

}

void DIO_VoidSetPortDirection(u8 u8cpy_portindex ,u8 u8cpy_direction)
{

	switch(u8cpy_portindex)
	{
	case 1:
		DDRA=u8cpy_direction; break;
	case 2:
		DDRB=u8cpy_direction; break;

	case 3:
		DDRC=u8cpy_direction; break;

	case 4:
		DDRD=u8cpy_direction; break;
	}
}

void DIO_VoidSetPinValue(u8 u8cpy_portindex ,u8 u8cpy_pinindex,u8 u8cpy_value)
{
	if(u8cpy_value==1)
	{
		switch(u8cpy_portindex)
		{
		case 1:
			SET_BIT(PORTA,u8cpy_pinindex); break;
		case 2:
			SET_BIT(PORTB,u8cpy_pinindex); break;

		case 3:
			SET_BIT(PORTC,u8cpy_pinindex); break;
		case 4:
			SET_BIT(PORTD,u8cpy_pinindex); break;
		}
	}
	else if(u8cpy_value==0)
	{
		switch(u8cpy_portindex)
		{
		case 1:
			CLR_BIT(PORTA,u8cpy_pinindex); break;
		case 2:
			CLR_BIT(PORTB,u8cpy_pinindex); break;

		case 3:
			CLR_BIT(PORTC,u8cpy_pinindex); break;

		case 4:
			CLR_BIT(PORTD,u8cpy_pinindex); break;
		}
	}
}
void DIO_VoidSetLowNibbleValue(u8 u8cpy_portindex ,u8 u8cpy_value)
{
	u8cpy_value&=0x0F;
	switch(u8cpy_portindex)
	{
		case 1:
		PORTA=(PORTA & 0xF0)|(u8cpy_value);
		break;
		case 2:
		PORTB=(PORTB & 0xF0)|(u8cpy_value);
		break;
		case 3:
		PORTC=(PORTC & 0xF0)|(u8cpy_value);
		break;
		case 4:
		PORTD=(PORTD & 0xF0)|(u8cpy_value);
		break;
	}
}
void DIO_VoidSetHighNibbleValue(u8 u8cpy_portindex ,u8 u8cpy_value)
{
	u8cpy_value=u8cpy_value<<4;
	switch(u8cpy_portindex)
	{
		case 1:
		PORTA=(PORTA & 0x0F)|(u8cpy_value);
		break;
		case 2:
		PORTB=(PORTB & 0x0F)|(u8cpy_value);
		break;
		case 3:
		PORTC=(PORTC & 0x0F)|(u8cpy_value);
		break;
		case 4:
		PORTD=(PORTD & 0x0F)|(u8cpy_value);
		break;
	}
	
}
void DIO_VoidSetPortValue(u8 u8cpy_portindex ,u8 u8cpy_value)
{

	switch(u8cpy_portindex)
	{
	case 1:
		PORTA=u8cpy_value; break;
	case 2:
		PORTB=u8cpy_value; break;

	case 3:
		PORTC=u8cpy_value; break;

	case 4:
		PORTD=u8cpy_value; break;
	}

}
u8 DIO_U8GetPinValue(u8 u8cpy_portindex ,u8 u8cpy_pinindex)
{
	u8 u8cpy_val=0;
	switch(u8cpy_portindex)
	{
	case 1:
		u8cpy_val=GET_BIT(PINA,u8cpy_pinindex); break;
	case 2:
		u8cpy_val=GET_BIT(PINB,u8cpy_pinindex); break;
	case 3:
		u8cpy_val=GET_BIT(PINC,u8cpy_pinindex); break;
	case 4:
		u8cpy_val=GET_BIT(PIND,u8cpy_pinindex); break;

	}
	return u8cpy_val;

}
u8 DIO_U8GetPortValue(u8 u8cpy_portindex)
{
	u8 u8cpy_val=0;
	switch(u8cpy_portindex)
	{
	case 1:
		u8cpy_val=PINA; break;
	case 2:
		u8cpy_val=PINB; break;
	case 3:
		u8cpy_val=PINC; break;
	case 4:
		u8cpy_val=PIND; break;

	}
	return u8cpy_val;

}
void DIO_VoidTogglePin(u8 u8cpy_portindex,u8 u8cpy_pinindex)
{
	switch(u8cpy_portindex)
	{
	case 1:
		TGL_BIT(PORTA,u8cpy_pinindex); break;
	case 2:
		TGL_BIT(PORTB,u8cpy_pinindex); break;

	case 3:
		TGL_BIT(PORTC,u8cpy_pinindex); break;

	case 4:
		TGL_BIT(PORTD,u8cpy_pinindex); break;
	}
}
void DIO_VoidTogglePort(u8 u8cpy_portindex)
{
	switch(u8cpy_portindex)
	{
	case 1:
		PORTA=~PORTA; break; //or: PORTA=PORTA^0xff
	case 2:
		PORTB=~PORTB; break;
	case 3:
		PORTC=~PORTC; break;
	case 4:
		PORTD=~PORTD; break;

	}
}
void DIO_VoidConnectPullUpPin(u8 u8cpy_portindex,u8 u8cpy_pinindex,u8 u8cpy_value)
{
	if(u8cpy_value==1)
	{
		switch(u8cpy_portindex)
		{
		case 1:
			SET_BIT(PORTA,u8cpy_pinindex); break;
		case 2:
			SET_BIT(PORTB,u8cpy_pinindex); break;
		case 3:
			SET_BIT(PORTC,u8cpy_pinindex); break;
		case 4:
			SET_BIT(PORTD,u8cpy_pinindex); break;
		}
	}
	else if(u8cpy_value==2)
	{
		switch(u8cpy_portindex)
		{
		case 1:
			CLR_BIT(PORTA,u8cpy_pinindex); break;
		case 2:
			CLR_BIT(PORTB,u8cpy_pinindex); break;
		case 3:
			CLR_BIT(PORTC,u8cpy_pinindex); break;
		case 4:
			CLR_BIT(PORTD,u8cpy_pinindex); break;
		}
	}
}
void DIO_VoidConnectPullUpPort(u8 u8cpy_portindex,u8 u8cpy_value)
{
	if(u8cpy_value==1)
	{
		switch(u8cpy_portindex)
		{
		case 1:
			PORTA=0xff; break;
		case 2:
			PORTB=0xff; break;
		case 3:
			PORTC=0xff; break;
		case 4:
			PORTD=0xff; break;

		}
	}
	else if(u8cpy_value==2)
	{
		switch(u8cpy_portindex)
		{
		case 1:
			PORTA=0x00; break;
		case 2:
			PORTB=0x00; break;
		case 3:
			PORTC=0x00; break;
		case 4:
			PORTD=0x00; break;

		}
	}

}

 