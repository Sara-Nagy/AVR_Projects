/*
 * simple_game.c
 *
 * Created: 10/24/2021 9:43:57 PM
 *  Author: Sara Ahmed
 */ 


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "TIMER0/TIMER0_Interface.h"
#include "LCD/LCD_Interface.h"
#include "KEYPAD/KEYPAD_Interface.h"
#include "GIE/GIE_Interface.h"
volatile u16 flag_isr;
u8 flag_time_over;
void fun_isr(void)
{
	flag_isr++;
}
int main(void)
{  
	u8 arr_prot[16]={'7','8','9','/','4','5','6','*','1','2','3','-','c','0','=','+'};
		/* 7[0]      8[1]      9[2]        /[3]
		 * 4[4]      5[5]      6[6]        *[7]
		 * 1[8]      2[9]      3[10]       -[11]
		 *           0[12]     =[14]       +[15]
		 * [12] : clear one character  
		 */	
	u8 read;
	GIE_VoidEnable_GlabelInterrupt();
	TIMER0_Void_CallBack(fun_isr);
	LCD_VoidInit();
	KEYPAD_VoidInit();
	TIMER0_VoidInit_CTC_Interrupt();
	LCD_VoidClearScreen();
	LCD_VoidSendString("3+ =8");
	_delay_ms(500);
   
        do 
        {
			if(flag_isr==1000) //if time become 10s (time over)
			{
				flag_time_over=1;
			}
			read=KEYPAD_U8Check_PressedKey();
							
        } while (read==KEYPAD_NOT_PRESSED && flag_time_over==0);
		
		if(read==KEYPAD_NOT_PRESSED)
		{ 
			LCD_VoidClearScreen();
			LCD_VoidSetCursorPosition(2,5);
			LCD_VoidSendString("Time Over");	
		}
		else if(arr_prot[read-1]=='5')
		{
			LCD_VoidClearScreen();
			LCD_VoidSetCursorPosition(2,5);
			LCD_VoidSendString("Well Done");
		}
		else
		{
			LCD_VoidClearScreen();
			LCD_VoidSetCursorPosition(2,4);
			LCD_VoidSendString("Wrong answer");
		}
		
}				