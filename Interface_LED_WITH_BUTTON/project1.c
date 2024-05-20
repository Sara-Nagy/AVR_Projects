/*
 * project1.c
 *
 * Created: 9/8/2021 11:46:27 AM
 *  Author: Sara Nagy 
 */ 


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include "util/delay.h"
#include "BUTTON/BUTTON_Interface.h"
#include "LED/LED_Interface.h"
#include "DIO/DIO_Interface.h"
int main(void)
{   
	///configure PA1 as output pin and connected to led
	LED_VoidInit(DIO_PORTA,DIO_PIN1);
	///configure PA0 as input pin and connected to push button
	BUTTON_VoidInit(DIO_PORTA,DIO_PIN0);
	///enable pull up resistance at PA0
	BUTTON_VoidConnect_Internal_Pullup(DIO_PORTA,DIO_PIN0,BUTTON_SET_INTERNAL_PULLUP);
	
	///variable to get button value in it
	u8 read=0;
    while(1) 
    { 
	read=BUTTON_U8GetValue(DIO_PORTA,DIO_PIN0);
	
			
				if(read==0) //the button is pushed 
				{
					///turn on led
					LED_VoidSet_Led_On(DIO_PORTA,DIO_PIN1);
				}
				else
				{    ///turn off led
					LED_VoidSet_Led_Off(DIO_PORTA,DIO_PIN1);
				}
										
        
    }
}