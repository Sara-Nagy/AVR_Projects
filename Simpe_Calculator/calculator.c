/*
 * calculator.c
 *
 * Created: 9/26/2021 3:19:36 PM
 *  Author: IT Shop
 */ 


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#define F_CPU 8000000UL
#include "util/delay.h"
#include "LCD/LCD_Interface.h"
#include "KEYPAD/KEYPAD_Interface.h"
 
 //Keypad:
u8 arr_hard[16]={'1','2','3','+','4','5','6','-','7','8','9','*','/','0','=','c'};
		/* 1[0]      2[1]      3[2]       '+'[3]
		 * 4[4]      5[5]      6[6]       '-'[7]
		 * 7[8]      8[9]     9[10]      '*'[11]
		 * '/'[12]   0[13]   '='[14]
		 * [15] : clear LCD  OR: clear one character from LCD
		 */

int main(void)
{ 
	LCD_VoidInit();
	KEYPAD_VoidInit();
	s16 res=0;
	s16 number1=1,number2=1;
	s32 result ;
	u8 num1,num2,ch,val;
	s8 i;
	s16 n=1000;
	
    while(1)
    {    
	
			for(i=0;i<10;i++)
		  {
			do 
			{
				val=KEYPAD_U8Check_PressedKey();
			} while (val==KEYPAD_NOT_PRESSED);
			
			//check if we want to clear one character from LCD
			if(arr_hard[val-1]=='c')
			{
				//LCD_VoidSetCursorPosition(1,i);
				LCD_VoidSendCommand(SHIFT_CURSOR_POSITION_TO_LEFT);
				LCD_VoidSendChar(0x20);
				//LCD_VoidSetCursorPosition(1,i);
				LCD_VoidSendCommand(SHIFT_CURSOR_POSITION_TO_LEFT);
				i=i-2;
				continue;
			}
			//number1
			if(i>=0 && i<=3)
			{
			
			num1=arr_hard[val-1];
			if(num1=='-')
			{ 
				LCD_VoidSendChar('-');
				i--;
				number1=-1;;
				continue;
			}
			LCD_VoidSendChar(num1);
			res+=(n*(num1-48));
			n/=10;
			if(i==3)
			    {
					number1*=res;
					res=0;
					n=1000;
			     }				
		    }
	   //character:		
	    else if(i==4)
		 {
			  
		ch=arr_hard[val-1];
		LCD_VoidSendChar(ch);
		 }		
		//number2				
		else if(i>=5 && i<=8)
		{
			num2=arr_hard[val-1];
				if(num2=='-')
				{
					LCD_VoidSendChar('-');
					i--;
					number2*=-1;
					continue;
				}
				LCD_VoidSendChar(num2);
				res+=(n*(num2-48));
				n/=10;
				if(i==8)
				{
					number2*=res;
				}
		}
		else if(i==9)
		{
			LCD_VoidSendChar(arr_hard[val-1]);
			switch(ch)
		{
			case '+':
			result=(s32)number1+number2;
			LCD_VoidSetCursorPosition(2,1);
			LCD_VoidSendNumber(result);
			break;
			case '-':
			result=number1-number2;
			LCD_VoidSetCursorPosition(2,1);
			LCD_VoidSendNumber(result);
			break;
			case '*':
			result=(s32)number1*number2;
			LCD_VoidSetCursorPosition(2,1);
			LCD_VoidSendNumber(result);
			break;
			case '/':
			result=number1/number2;
			LCD_VoidSetCursorPosition(2,1);
			LCD_VoidSendNumber(result);
			LCD_VoidSendChar('.');
			f32 flot=(float)number1/number2;
			f32 res_flot=flot-result;
			LCD_VoidSendNumber(res_flot*10000000);
			break;
		}
		}
		 }				
				
		do
		{
			val=KEYPAD_U8Check_PressedKey();
		} while (val==KEYPAD_NOT_PRESSED);
		
		if(arr_hard[val-1]=='c')
		{
			LCD_VoidClearScreen();
			i=0;
			res=0;
			n=1000;
			number1=1;
			number2=1;
		}
}
		}