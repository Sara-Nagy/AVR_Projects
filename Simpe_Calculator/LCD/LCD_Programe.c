/*
 * LCD_Programe.c
 *
 * Created: 9/19/2021 10:49:33 PM
 *  Author: Sara Ahmed 
 */ 

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../DIO/DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Pravite.h"


void LCD_VoidSendChar(u8 u8cpy_data)
{ 
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_Rs,DIO_HIGH);      //RS 1
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_RW,DIO_LOW);       //RW 0
	#if defined _8_MODE
	DIO_VoidSetPortValue(LCD_PORT_data_commond,u8cpy_data);          //send data to data port
    // set enable 
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_HIGH);           //EN 1
	_delay_ms(2);                                                     
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_LOW);            // EN 0
	_delay_ms(2);
	
	#elif defined _4_MODE
	//send data to data port
	DIO_VoidSetHighNibbleValue(LCD_PORT_data_commond,u8cpy_data>>4);    //send high nibble form data 
	// set enable
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_HIGH);           //EN 1
	_delay_ms(2);
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_LOW);            // EN 0
	_delay_ms(2);    
	
	DIO_VoidSetHighNibbleValue(LCD_PORT_data_commond,u8cpy_data);       //send low nibble form data      
	// set enable
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_HIGH);           //EN 1
	_delay_ms(2);
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_LOW);            // EN 0
	_delay_ms(2);
    #endif
	
}

void LCD_VoidSendCommand(u8 u8cpy_command)
{
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_Rs,DIO_LOW);      //RS 0
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_RW,DIO_LOW);       //RW 0
	#if defined _8_MODE
	DIO_VoidSetPortValue(LCD_PORT_data_commond,u8cpy_command);     //send command to data port                             
	// set enable
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_HIGH);           //EN 1
	_delay_ms(2);
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_LOW);            // EN 0
	_delay_ms(2);
	
	#elif defined _4_MODE
	//send data to command port
	DIO_VoidSetHighNibbleValue(LCD_PORT_data_commond,u8cpy_command>>4);    //send high nibble form command
	// set enable
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_HIGH);           //EN 1
	_delay_ms(2);
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_LOW);            // EN 0
	_delay_ms(2);
	
	DIO_VoidSetHighNibbleValue(LCD_PORT_data_commond,u8cpy_command);       //send low nibble form command
	// set enable
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_HIGH);           //EN 1
	_delay_ms(2);
	DIO_VoidSetPinValue(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_LOW);            // EN 0
	_delay_ms(2);
	#endif
	
}
void LCD_VoidInit(void)
{
	#if defined _8_MODE
	DIO_VoidSetPortDirection(LCD_PORT_data_commond,0xFF);                //set port of data and commands as output
	DIO_VoidSetPinDirection(LCD_PORT_RS_RW_EN,LCD_PIN_Rs,DIO_OUT);       //set pin of RS as output
	DIO_VoidSetPinDirection(LCD_PORT_RS_RW_EN,LCD_PIN_RW,DIO_OUT);      //set pin of RW as output
	DIO_VoidSetPinDirection(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_OUT);      //set pin of EN as output
	
	_delay_ms(50);                                                      //wait for VDD to be 4,5v more than 30
	LCD_VoidSendCommand(_8_BIT_MODE);                 //function set as 8 bit mode 
	_delay_ms(1);                                     //wait for execution time for command  (39 us)
	LCD_VoidSendCommand(DISPLAY_ON_CURSOR_ON);       //display on cursor on 
	_delay_ms(1);                                     //wait for execution time for command  (39 us)
	LCD_VoidSendCommand(CLEAR_SCREEN);                //clear screen
	_delay_ms(10);                                    //wait for execution time for command  (1,53 ms)
	LCD_VoidSendCommand(ENTRY_MODE);                  //entry mode : display cursor to right 
	_delay_ms(1);                                    //wait for execution time for command  (39 us)
	
	#elif defined _4_MODE 
	 //set high nibble of the port of data and commands as output
	DIO_VoidSetPinDirection(LCD_PORT_data_commond,DIO_PIN4,DIO_HIGH);
	DIO_VoidSetPinDirection(LCD_PORT_data_commond,DIO_PIN5,DIO_HIGH);
	DIO_VoidSetPinDirection(LCD_PORT_data_commond,DIO_PIN6,DIO_HIGH);
	DIO_VoidSetPinDirection(LCD_PORT_data_commond,DIO_PIN7,DIO_HIGH);  
	             
	DIO_VoidSetPinDirection(LCD_PORT_RS_RW_EN,LCD_PIN_Rs,DIO_OUT);       //set pin of RS as output
	DIO_VoidSetPinDirection(LCD_PORT_RS_RW_EN,LCD_PIN_RW,DIO_OUT);      //set pin of RW as output
	DIO_VoidSetPinDirection(LCD_PORT_RS_RW_EN,LCD_PIN_EN,DIO_OUT);      //set pin of EN as output
	
	_delay_ms(50);                                                      //wait for VDD to be 4,5v more than 30
	LCD_VoidSendCommand(_4_BIT_MODE_COM1);             //function set as 4 bit mode command 1
	_delay_ms(10);                                     //wait for execution time for command  (1,53 ms)
	LCD_VoidSendCommand(_4_BIT_MODE_COM2);             //function set as 4 bit mode command 2
	_delay_ms(1);                                     //wait for execution time for command  (39 us)
	LCD_VoidSendCommand(DISPLAY_ON_CURSOR_ON);        //display on cursor on
	_delay_ms(1);                                     //wait for execution time for command  (39 us)
	LCD_VoidSendCommand(CLEAR_SCREEN);                //clear screen
	_delay_ms(10);                                    //wait for execution time for command  (1,53 ms)
	LCD_VoidSendCommand(ENTRY_MODE);                  //entry mode : display cursor to right
	_delay_ms(1);                                     //wait for execution time for command  (39 us)
	#endif	 
}

void LCD_VoidSendString(u8* u8cpy_poniter_string)
{
	u8 i=0;
	while(u8cpy_poniter_string[i]!='\0')   //OR: *u8cpy_poniter_string
	{
		LCD_VoidSendChar(u8cpy_poniter_string[i]);     //OR: *u8cpy_poniter_string
		i++;                               //OR: u8cpy_poniter_string+++
	}

}

void LCD_VoidSendNumber(s32 s32cpy_number)
{
	if(s32cpy_number==0)
	{
		LCD_VoidSendChar('0'+0);
	}
	else
	{ 
		s8 type=0;
		if(s32cpy_number<0)
		{  type=-1;
			s32cpy_number*=-1;
		}

		s32 res=0;
		s32 val=s32cpy_number;
		s32 count=1;
		if(val%10==0)
		{
			do
			{
				count*=10;
				val/=10;
			}
			while(val%10==0);
		}

		while(s32cpy_number>0)
		{
			res=res*10+(s32cpy_number%10);
			s32cpy_number/=10;
		}
		if(type==-1)
		{
			LCD_VoidSendChar('-');
		}
		while(res>0)
		{
			LCD_VoidSendChar('0'+(res%10));
			res/=10;
		}
		while(count!=1)
		{
			LCD_VoidSendChar('0'+(count%10));
			count/=10;
		}
	}



}

void LCD_VoidSaveCustomChar(const u8 u8cpy_arr[],u8 u8cpy_num)
{
	u8 i=0;
	if(u8cpy_num>=0 && u8cpy_num<=7)
	{
		LCD_VoidSendCommand(0x40+(u8cpy_num*8)); //set CGRAM
		for(i=0;i<8;i++)
		{
			LCD_VoidSendChar(u8cpy_arr[i]); //set byte in CGRAM
		}
		LCD_VoidSendCommand(0x80);//set DDRAM and close CGRAM
	}
}

void LCD_VoidSetCursorPosition(u8 u8cpy_row,u8 u8cpy_column)
{
	if(u8cpy_column>=1&&u8cpy_column<=16)
	{

		if(u8cpy_row==1)
		{
			LCD_VoidSendCommand(0x80+u8cpy_column-1);   //control first row
		}
		else if(u8cpy_row==2)
		{
			LCD_VoidSendCommand(0xC0+u8cpy_column-1);   //control second row
		}
	}

}

void LCD_VoidClearScreen(void)
{
	LCD_VoidSendCommand(CLEAR_SCREEN);
	_delay_ms(10);                //wait for execution time for command  (1,53 ms)
}

