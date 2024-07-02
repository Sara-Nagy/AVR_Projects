/*
 * TIMER0_Programe.c
 *
 * Created: 10/17/2021 8:29:10 PM
 *  Author: Sara Ahmed
 */ 
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../DIO/DIO_Interface.h"
#include "TIMER0_Config.h"
#include "TIMER0_Pravite.h"

void (*TIMER0_COM_Ptr)(void)=0;
void TIMER0_VoidInit_CTC_Interrupt(void)
{
	
	
	//1_select CTC mode : 0b10
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	//2_load a value in OCR0 
	OCR0=78;  
	//3_select timer clock 
	TCCR0=(TCCR0 & 0b11111000)|TIMER0_CLOCK;
	/*
	every interrupt compare match= 10 ms
	*/
	//4_enable interrupt
	SET_BIT(TIMSK,OCIE0);

}

void TIMER0_VoidGenrate_Wave_NonPWM(void)
{
	//1_set OC0 as output pin 
	DIO_VoidSetPinDirection(2,3,1);
	//2_select CTC mode
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	//3_load a value in OCR0 
	OCR0=90;
	//4_select timer clock 
	TCCR0=(TCCR0 & 0b11111000)|TIMER0_CLOCK;
	//5_toggle OC0 on compare match
	TCCR0=(TCCR0 & 0b11001111)|(OC0_COMPARA_MATCH<<4);
	
}
void TIMER0_VoidGenrate_Wave_FastPWM(void)
{
	//1_set OC0 as output pin 
	DIO_VoidSetPinDirection(2,3,1);
	//2_select fast PWM mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	//3_load a value in OCR0 
	OCR0=65;
	//4_select timer clock 
	TCCR0=(TCCR0 & 0b11111000)|TIMER0_CLOCK;
	//5_ Clear OC0 on compare match, set OC0 at TOP,(non inverting mode)*
	TCCR0=(TCCR0 & 0b11001111)|(OC0_FAST_PWM<<4);
}
void TIMER0_VoidGenrate_Wave_PhaseCorrectMode(void)
{
	//1_ set OC0 as output pin 
	DIO_VoidSetPinDirection(2,3,1);
	//2_select phase correct PWM mode ob01
	CLR_BIT(TCCR0,WGM01); 
	SET_BIT(TCCR0,WGM00);
	//3_load a value in OCR0 
	OCR0=64;
	//4_select timer clock 
	TCCR0=(TCCR0 & 0b11111000)|TIMER0_CLOCK;
	//5_ Clear OC0 on compare match when up-counting. Set OC0 on compare  match when downcounting.
	TCCR0=(TCCR0 & 0b11001111)|(OC0_PHASE_CORRECT_PWM <<4);

}	
void TIMER0_Void_CallBack(void(*f_ptr)(void))
{
	TIMER0_COM_Ptr=f_ptr;
}
//ISR of Timer0 of compare match
void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	if(TIMER0_COM_Ptr!=0)
	{
		TIMER0_COM_Ptr();
	}
}
