/*
 * Frequency_Duty_Measure.c
 *
 * Created: 2/24/2022 4:39:11 PM
 *  Author: Sara Ahmed
 */ 


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#define F_CPU 8000000UL 
#include <util/delay.h>
#include "DIO/DIO_Interface.h"
#include "LCD/LCD_Interface.h"
#include "TIMER1/TIMER1_Interface.h"
u32 duty,freq,on_time;
int main(void)
{
	
		LCD_VoidInit();
		LCD_VoidClearScreen();
		TIMER1_Frequency_Duty_Measure_PWM(&freq,&duty,&on_time);
		if(duty!=0xFFFF && freq!=0xFFFF)
		{
			LCD_VoidSendString("Duty=");
			LCD_VoidSendNumber(duty);
			LCD_VoidSendChar('%');
			LCD_VoidSetCursorPosition(2,1);
			LCD_VoidSendString("Freq=");
			LCD_VoidSendNumber(freq);
			LCD_VoidSendString("HZ"); 
		
		}
		else
		{
	 	LCD_VoidSendString("Out Of Range");
		}

	while(1)
    {

			
	}       
    
}