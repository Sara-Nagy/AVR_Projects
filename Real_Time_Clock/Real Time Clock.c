/*
 * Real_Time_Clock.c
 *
 * Created: 10/26/2021 1:10:52 PM
 *  Author: Sara Ahmed
 */ 
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD/LCD_Interface.h"
#include "KEYPAD/KEYPAD_Interface.h"
#include "GIE/GIE_Interface.h"
#include "TIMER1/TIMER1_Interface.h"
#include "DIO/DIO_Interface.h"
volatile u8 counter_seconds;
u8  counter_minutes ,counter_hours;
u8 first_digit,second_digit;

void Fun_ISR_CTC(void)
{
	counter_seconds++;
}

int main(void)
{
	u8 val;
	//hardware 
	u8 arr_hard[16]={'1','2','+','3','4','5','-','6','7','8','*','9','/','0','c','='};
		/* 1[0]      2[1]      3[2]       '+'[3]
		 * 4[4]      5[5]      6[6]       '-'[7]
		 * 7[8]      8[9]     9[10]      '*'[11]
		 * '/'[12]   0[13]   '='[14]
		 * [15] : clear one character  
		 */
	GIE_VoidEnable_GlabelInterrupt();
	LCD_VoidInit();
	KEYPAD_VoidInit();
	SSD_VoidInit(2);
	DIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUT);
	DIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN1,DIO_OUT);
	DIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN2,DIO_OUT);
	DIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN3,DIO_OUT);
	DIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN4,DIO_OUT);
	DIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN5,DIO_OUT);
	LCD_VoidClearScreen();
	
	TIMER1_Void_CTC_CallBack(Fun_ISR_CTC);
	TIMER1_Void_CTC_Interrupt();
    while(1)
    { 
		LCD_VoidSetCursorPosition(1,1);
		if(counter_hours<10)
		{
		LCD_VoidSendNumber(0);
		LCD_VoidSendNumber(counter_hours);
		}
		else
		{
		LCD_VoidSendNumber(counter_hours);	
		}
		LCD_VoidSendChar(" ");		
		
		if(counter_minutes<10)
		{
			LCD_VoidSendNumber(0);
			LCD_VoidSendNumber(counter_minutes);
		}
		else
		{
			LCD_VoidSendNumber(counter_minutes);
		}
		LCD_VoidSendChar(" ");
		
		if(counter_seconds<10)
		{
			LCD_VoidSendNumber(0);
			LCD_VoidSendNumber(counter_seconds);
		}
		else
		{
			LCD_VoidSendNumber(counter_seconds);
		}
		LCD_VoidSendChar(" ");
		LCD_VoidSetCursorPosition(2,1);
		LCD_VoidSendString("press 1 : to set clock");
		
		val=KEYPAD_U8Check_PressedKey();
		if(val!=KEYPAD_NOT_PRESSED)
		{
			if( arr_hard[val-1]=='1')
			{  //Hours
				LCD_VoidClearScreen();
				LCD_VoidSendString("Hours=--");
				LCD_VoidSetCursorPosition(1,7);
				do 
				{
					first_digit=KEYPAD_U8Check_PressedKey();
					
				} while (first_digit==KEYPAD_NOT_PRESSED);
				LCD_VoidSendChar( arr_hard[first_digit-1]);
				
				do
				{
					second_digit=KEYPAD_U8Check_PressedKey();
					
				} while (second_digit==KEYPAD_NOT_PRESSED);
				LCD_VoidSendChar(arr_hard[second_digit-1]);
				counter_hours=( arr_hard[first_digit-1] -48)*10 +(arr_hard[second_digit-1]-48);
				_delay_ms(1000);
				//minutes
				LCD_VoidClearScreen();
				LCD_VoidSendString("Minutes=--");
				LCD_VoidSetCursorPosition(1,9);
				do
				{
					first_digit=KEYPAD_U8Check_PressedKey();
					
				} while (first_digit==KEYPAD_NOT_PRESSED);
				LCD_VoidSendChar(arr_hard[first_digit-1]);
				
				do
				{
					second_digit=KEYPAD_U8Check_PressedKey();
					
				} while (second_digit==KEYPAD_NOT_PRESSED);
				LCD_VoidSendChar(arr_hard[second_digit-1]);
				counter_minutes=(arr_hard[first_digit-1] -48)*10 +(arr_hard[second_digit-1]-48);
				_delay_ms(1000);
				//seconds
				LCD_VoidClearScreen();
				LCD_VoidSendString("seconds=--");
				LCD_VoidSetCursorPosition(1,9);
				do
				{
					first_digit=KEYPAD_U8Check_PressedKey();
					
				} while (first_digit==KEYPAD_NOT_PRESSED);
				LCD_VoidSendChar(arr_hard[first_digit-1]);
				
				do
				{
					second_digit=KEYPAD_U8Check_PressedKey();
					
				} while (second_digit==KEYPAD_NOT_PRESSED);
				LCD_VoidSendChar(arr_hard[second_digit-1]);
				counter_seconds=(arr_hard[first_digit-1] -48)*10 +(arr_hard[second_digit-1]-48);
				_delay_ms(1000);
				LCD_VoidClearScreen();
			
			LCD_VoidSetCursorPosition(1,1);
			if(counter_hours<10)
			{
				LCD_VoidSendNumber(0);
				LCD_VoidSendNumber(counter_hours);
			}
			else
			{
				LCD_VoidSendNumber(counter_hours);
			}
			LCD_VoidSendChar(" ");
			
			if(counter_minutes<10)
			{
				LCD_VoidSendNumber(0);
				LCD_VoidSendNumber(counter_minutes);
			}
			else
			{
				LCD_VoidSendNumber(counter_minutes);
			}
			LCD_VoidSendChar(" ");
			
			if(counter_seconds<10)
			{
				LCD_VoidSendNumber(0);
				LCD_VoidSendNumber(counter_seconds);
			}
			else
			{
				LCD_VoidSendNumber(counter_seconds);
			}
			LCD_VoidSendChar(" ");
			LCD_VoidSetCursorPosition(2,1);
			LCD_VoidSendString("press 1 to :set clock");
			
			}
			else
			{
				LCD_VoidClearScreen();
				LCD_VoidSendString("Wrong Choice");
				_delay_ms(1500);
				LCD_VoidClearScreen();
			
			LCD_VoidSetCursorPosition(1,1);
			if(counter_hours<10)
			{
				LCD_VoidSendNumber(0);
				LCD_VoidSendNumber(counter_hours);
			}
			else
			{
				LCD_VoidSendNumber(counter_hours);
			}
			LCD_VoidSendChar(" ");
			
			if(counter_minutes<10)
			{
				LCD_VoidSendNumber(0);
				LCD_VoidSendNumber(counter_minutes);
			}
			else
			{
				LCD_VoidSendNumber(counter_minutes);
			}
			LCD_VoidSendChar(" ");
			
			if(counter_seconds<10)
			{
				LCD_VoidSendNumber(0);
				LCD_VoidSendNumber(counter_seconds);
			}
			else
			{
				LCD_VoidSendNumber(counter_seconds);
			}
			LCD_VoidSendChar(" ");
			LCD_VoidSetCursorPosition(2,1);
			LCD_VoidSendString("press 1 to: set clock");
			
				
			}				
			
		}
		
		
		if(counter_seconds==60)
		{
			counter_seconds=0;
			counter_minutes++;
		}			
		if(counter_minutes==60)
		{
			counter_minutes=0;
			counter_hours++;
		}
		if(counter_hours==24)
		{
			counter_hours=0;
		}
		
		
		
    }
}