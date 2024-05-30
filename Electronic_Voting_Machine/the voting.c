/*
 * the_voting.c
 *
 * Created: 9/26/2021 1:44:53 PM
 *  Author: Sara Ahmed
 */ 


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#define	 F_CPU 8000000UL
#include "util/delay.h"
#include "LCD/LCD_Interface.h"
#include "DIO/DIO_Interface.h"
#include "BUTTON/BUTTON_Interface.h"

 u8 counter1;
 u8 counter2;
 u8 counter3;
 u8 counter4;
 
int main(void)
{
	LCD_VoidInit();
	BUTTON_VoidInit(DIO_PORTB,DIO_PIN0);   //BUTTON 1
	BUTTON_VoidInit(DIO_PORTB,DIO_PIN1);   //BUTTON 2
	BUTTON_VoidInit(DIO_PORTB,DIO_PIN2);   //BUTTON 3
	BUTTON_VoidInit(DIO_PORTB,DIO_PIN3);   //BUTTON 4
	BUTTON_VoidInit(DIO_PORTB,DIO_PIN4);   //BUTTON For Reset
    BUTTON_VoidConnect_Internal_Pullup(DIO_PORTB,DIO_PIN0,BUTTON_SET_INTERNAL_PULLUP);
	BUTTON_VoidConnect_Internal_Pullup(DIO_PORTB,DIO_PIN1,BUTTON_SET_INTERNAL_PULLUP);
	BUTTON_VoidConnect_Internal_Pullup(DIO_PORTB,DIO_PIN2,BUTTON_SET_INTERNAL_PULLUP);
	BUTTON_VoidConnect_Internal_Pullup(DIO_PORTB,DIO_PIN3,BUTTON_SET_INTERNAL_PULLUP);
	BUTTON_VoidConnect_Internal_Pullup(DIO_PORTB,DIO_PIN4,BUTTON_SET_INTERNAL_PULLUP);
	
	LCD_VoidSendString("A=0");
	LCD_VoidSetCursorPosition(1,10);
	LCD_VoidSendString("B=0");
	LCD_VoidSetCursorPosition(2,1);
	LCD_VoidSendString("C=0");
	LCD_VoidSetCursorPosition(2,10);
	LCD_VoidSendString("D=0");
	
    while(1)
    {
		if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN0)==DIO_LOW)  //read button 1
		{ 
			_delay_ms(30);   // wait for bouncing
			if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN0)==DIO_LOW)
			{
				counter1++;
			LCD_VoidSetCursorPosition(1,3);
			LCD_VoidSendNumber(counter1);
			}	
			_delay_ms(200);	// wait for period of switch on button 1
		}
		
		else if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN1)==DIO_LOW)  //read button 2
		{
			_delay_ms(30);   // wait for bouncing
			if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN1)==DIO_LOW)
			{
			counter2++;
			LCD_VoidSetCursorPosition(1,12);
			LCD_VoidSendNumber(counter2);
		    }
		_delay_ms(200);	// wait for period of switch on button2
		}	
		
		else if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN2)==DIO_LOW)  //read button 3
		{ 
			_delay_ms(30);   // wait for bouncing
			if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN2)==DIO_LOW)
			{
			counter3++;
			LCD_VoidSetCursorPosition(2,3);
			LCD_VoidSendNumber(counter3);
		    }
		   _delay_ms(200);	// wait for period of switch on button3
		}
		
		else if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN3)==DIO_LOW)  //read button 4
		{
			_delay_ms(30);   // wait for bouncing
			if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN3)==DIO_LOW)
			{
			counter4++;
			LCD_VoidSetCursorPosition(2,12);
			LCD_VoidSendNumber(counter4);
		    }
		 _delay_ms(200);	// wait for period of switch on button4
		}	
    
	
	else if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN4)==DIO_LOW)  //read button 5 (reset button)
	{
		_delay_ms(30);   // wait for bouncing
		if(BUTTON_U8GetValue(DIO_PORTB,DIO_PIN4)==DIO_LOW)
		{
			counter1=counter2=counter3=counter4=0;
			LCD_VoidSetCursorPosition(1,1);
			LCD_VoidSendString("A=0");
			LCD_VoidSetCursorPosition(1,10);
			LCD_VoidSendString("B=0");
			LCD_VoidSetCursorPosition(2,1);
			LCD_VoidSendString("C=0");
			LCD_VoidSetCursorPosition(2,10);
			LCD_VoidSendString("D=0");
		}
		_delay_ms(200);	// wait for period of switch on button 5 (reset button)
	}
}
}
		
