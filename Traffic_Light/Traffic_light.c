/*
 * Traffic_light.c
 *
 * Created: 2/15/2022 3:06:11 PM
 *  Author: Sara Ahmed 
 */ 


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#define F_CPU 8000000UL 
#include <util/delay.h>
#include "LCD/LCD_Interface.h"
#include "TIMER0/TIMER0_Interface.h"
#include "LED/LED_Interface.h"
#include "GIE/GIE_Interface.h"
volatile u8 counter;
u8 counter_grean;
u8 counter_yollew;
u8 counter_red;
void ISR_COM(void)
{
	counter++;
}
int main(void)
{
	GIE_VoidEnable_GlabelInterrupt();
	TIMER0_Void_CallBack(ISR_COM);
	TIMER0_VoidInit_CTC_Interrupt();
	LCD_VoidInit();
	LED_VoidInit(4,0);
	LED_VoidInit(4,1);
	LED_VoidInit(4,2);
	
    while(1)
    {
		counter_grean=10;
		counter_yollew=5;
		counter_red=7;
		LCD_VoidClearScreen();
		LCD_VoidSendString("remaining 10 sec");
		///turn on green led
		LED_VoidSet_Led_On(4,0);
		while(counter_grean>0)
		{
			if(counter>=100)
			{
				counter=0;
				counter_grean--;
				LCD_VoidSetCursorPosition(1,11);
				LCD_VoidSendChar(' ');
				///display the remaining time for green led
				LCD_VoidSetCursorPosition(1,11);
				LCD_VoidSendNumber(counter_grean);
			}				
        
        }
		_delay_ms(500);
		///turn off green led
		LED_VoidSet_Led_Off(4,0);
		///turn on yollew led
		LED_VoidSet_Led_On(4,1);
		LCD_VoidClearScreen();
		LCD_VoidSendString("remaining 5 sec");
		while(counter_yollew>0)
		{
			if(counter>=100)
			{
				counter=0;
				counter_yollew--;
				LCD_VoidSetCursorPosition(1,11);
				LCD_VoidSendChar(' ');
				LCD_VoidSetCursorPosition(1,11);
				LCD_VoidSendNumber(counter_yollew);
			}
			
		}
		_delay_ms(500);
		///turn off yellow led
		LED_VoidSet_Led_Off(4,1);
		///turn on red led
		LED_VoidSet_Led_On(4,2);
		LCD_VoidClearScreen();
		LCD_VoidSendString("remaining 7 sec");
		while(counter_red>0)
		{
			if(counter>=100)
			{
				counter=0;
				counter_red--;
				LCD_VoidSetCursorPosition(1,11);
				LCD_VoidSendChar(' ');
				LCD_VoidSetCursorPosition(1,11);								
				LCD_VoidSendNumber(counter_red);
			}
			
		}
		_delay_ms(500);
		LED_VoidSet_Led_Off(4,2);
		}		
}