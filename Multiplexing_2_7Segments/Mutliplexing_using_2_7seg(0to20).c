/*
 * Mutliplexing_using_2_7seg_0to20_.c
 *
 * Created: 10/18/2021 3:52:18 PM
 *  Author: Sara Ahmed
 */ 


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "ssd/SSD_Interface.h"
#include "TIMER0/TIMER0_Interface.h"
#include "DIO/DIO_Interface.h"

u8 number;
volatile u8 counter1;
volatile u8 counter2;
void ISR_COMP(void)
{
	counter1=1;
	counter2++;
}
int main(void)
{
	GIE_VoidEnable_GlabelInterrupt();
	SSD_VoidInit(4);
	DIO_VoidSetPinDirection(1,0,1);
	DIO_VoidSetPinDirection(1,1,1);
	TIMER0_Void_CallBack(ISR_COMP);
	TIMER0_VoidInit_CTC_Interrupt();
	DIO_VoidSetPinValue(1,0,0);
	DIO_VoidSetPinValue(1,1,1);
    while(1)
    {
		DIO_VoidSetPinValue(1,0,0);
        DIO_VoidSetPinValue(1,1,1);
		SSD_VoidWrite(4,number%10);
		while(counter1==0);
		counter1=0;
		DIO_VoidSetPinValue(1,0,1);
		DIO_VoidSetPinValue(1,1,0);
		SSD_VoidWrite(4,number/10);
		while(counter1==0);
		counter1=0;
		if(counter2==100)
		{
			number++;
			counter2=0;
			if(number==21)
			{
				number=0;
			}
		}			
    }
}