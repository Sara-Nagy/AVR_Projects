/*
 * KEYPAD_Programe.c
 *
 * Created: 9/20/2021 9:11:16 PM
 *  Author: Sara Ahmed
 */ 

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include  <util/delay.h>
#include "../DIO/DIO_Interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Pravite.h"

void KEYPAD_VoidInit(void)
{    
	
	DIO_VoidSetPortDirection(KEYPAD_PORT,0x0F);   //low nibble :OUTPUT(columns)    and    high nibble :INPUT(rows) 
	DIO_VoidSetHighNibbleValue(KEYPAD_PORT,0x0F);  // set value of OUTPUT nibble as high value 
	DIO_VoidSetLowNibbleValue(KEYPAD_PORT,0xF0);  // set internal pull up resistor in low nibble
	
	//OR:
	/*
	 //low nibble :OUTPUT
	 DIO_VoidSetPinDirection(KEYPAD_PORT,DIO_PIN0,DIO_OUT);
	 DIO_VoidSetPinDirection(KEYPAD_PORT,DIO_PIN1,DIO_OUT);
	 DIO_VoidSetPinDirection(KEYPAD_PORT,DIO_PIN2,DIO_OUT);
	 DIO_VoidSetPinDirection(KEYPAD_PORT,DIO_PIN3,DIO_OUT);
	 
	 // set value of OUTPUT nibble as high value
	 DIO_VoidSetPinValue(KEYPAD_PORT,DIO_PIN0,DIO_HIGH);
	 DIO_VoidSetPinValue(KEYPAD_PORT,DIO_PIN1,DIO_HIGH);
	 DIO_VoidSetPinValue(KEYPAD_PORT,DIO_PIN2,DIO_HIGH);
	 DIO_VoidSetPinValue(KEYPAD_PORT,DIO_PIN3,DIO_HIGH);
	 
	//high nibble :INPUT
	 DIO_VoidSetPinDirection(KEYPAD_PORT,DIO_PIN4,DIO_IN);
	 DIO_VoidSetPinDirection(KEYPAD_PORT,DIO_PIN5,DIO_IN);
	 DIO_VoidSetPinDirection(KEYPAD_PORT,DIO_PIN6,DIO_IN);
	 DIO_VoidSetPinDirection(KEYPAD_PORT,DIO_PIN7,DIO_IN);
	 
	 // set internal pull up resistor in low nibble
	 DIO_VoidConnectPullUpPin(KEYPAD_PORT,DIO_PIN4,DIO_SET_PULLUP);
	 DIO_VoidConnectPullUpPin(KEYPAD_PORT,DIO_PIN5,DIO_SET_PULLUP);
	 DIO_VoidConnectPullUpPin(KEYPAD_PORT,DIO_PIN6,DIO_SET_PULLUP);
	 DIO_VoidConnectPullUpPin(KEYPAD_PORT,DIO_PIN7,DIO_SET_PULLUP);
	 
	*/
}

u8 KEYPAD_U8Check_PressedKey(void)
{
	u8 pressed=NOT_PRESSED;   
	u8 row,column;
	for(column=0;column<KEYPAD_COLUMNS;column++)
	{
		DIO_VoidSetPinValue(KEYPAD_PORT,column,DIO_LOW); //clear column 
		
		for(row=0;row<KEYPAD_ROWS;row++)
		{ 
			if(DIO_U8GetPinValue(KEYPAD_PORT,row+4)==0)
			_delay_ms(KEYPAD_BOUNCING);  //wait for bouncing 
			if(DIO_U8GetPinValue(KEYPAD_PORT,row+4)==0)
			{
				pressed=(column+(row*4))+1;
                _delay_ms(200); //wait for period of switch on the button	
				break;
			}
			
		}
		DIO_VoidSetPinValue(KEYPAD_PORT,column,DIO_HIGH); //set column
	}
	return pressed;
}