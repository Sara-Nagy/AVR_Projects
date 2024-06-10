/*
 * Temperature_Sensor_Project.c
 *
 * Created: 10/11/2021 8:24:06 PM
 *  Author: Sara Ahmed
 */ 


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#define  F_CPU 8000000UL
#include "util/delay.h"
#include "ADC/ADC_Interface.h"
#include "LCD/LCD_Interface.h"
int main(void)
{ 
	s16 temp;
	ADC_VoidInit();
	LCD_VoidInit();
	LCD_VoidSendString("Temperature=");
	
    while(1)
    {
		 temp=.25*ADC_U16GetData();
		 /*
		 volt(v)=(2,56*ADC_U16GetData())/1024
		 volt(mv)=((2,56*ADC_U16GetData())/1024)*1000;
		 temp=(((2,56*ADC_U16GetData())/1024)*1000)/10;
		 temp=.25*ADC_U16GetData()
		 */
		 if(temp<10)
		 {
			 LCD_VoidSetCursorPosition(2,1);
			 LCD_VoidSendNumber(temp);
			 LCD_VoidSendChar(0XDF);
			 LCD_VoidSendChar('C');
			 LCD_VoidSendChar(0x20);
			 LCD_VoidSendChar(0x20);
		 }
		 
		 else if(temp<100)
		 {
		   LCD_VoidSetCursorPosition(2,1);
		   LCD_VoidSendNumber(temp);
		   LCD_VoidSendChar(0XDF);
		   LCD_VoidSendChar('C');
		   LCD_VoidSendChar(0x20);
		   
		}
		else
		{
			 LCD_VoidSetCursorPosition(2,1);
			 LCD_VoidSendNumber(temp);
			 LCD_VoidSendChar(0XDF);
			 LCD_VoidSendChar('C');
		}			
			
        
    }
}