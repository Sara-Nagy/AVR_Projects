/*
 * TIMER1_Programe.c
 *
 * Created: 2/20/2022 10:34:53 PM
 *  Author: Sara Ahmed
 */ 

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../DIO/DIO_Interface.h"
#include "TIMER1_Config.h"
#include "TIMER1_Pravite.h"

void (*TIMER1_OVF_Ptr)(void)=0;    //interrupt for timer over flow mode 
void (*TIMER1_CTC_Ptr)(void)=0;    //interrupt for timer clear match mode

void TIMER1_Void_TimerOverFlow_Interrupt(void)
{
	//1_select timer over flow  mode : 0b0000
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	
	//2_select timer prescaler
	TCCR1B=(TCCR1B & 0b11111000)|TIMER1_CLOCK;
	
	//3_enable interrupt
	SET_BIT(TIMSK,TOIE1);
	
}
void TIMER1_Void_CTC_Interrupt(void)
{
	//1_select clear on compare match (OCR1A) mode : 0b0100
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	
	//2_load a value in OCR1A
	OCR1A=7813;
	
	//2_select timer prescaler
	TCCR1B=(TCCR1B & 0b11111000)|TIMER1_CLOCK;
	
	/*
	every interrupt compare match= 1s
	*/
	//4_enable interrupt
	SET_BIT(TIMSK,OCIE1A);
	
}


void TIMER1_Frequency_Duty_Measure_PWM(u32 * u32_copy_ptr_freq,u32 * u32_copy_ptr_duty,u32 * u32_copy_ptr_on_time)
{
	/*u32 a,b,c;
	u32 frequency,period,duty,on_time;
	
	//1_select timer over flow  mode : 0b0000
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	
	//2_set Input Capture Noise Canceler
	SET_BIT(TCCR1B,ICNC1);
	
	//3_clear input capture flag 
	SET_BIT(TIMSK,ICF1);
	
	//4_select no prescaler
	TCCR1B=(TCCR1B & 0b11111000)|TIMER1_CLOCK;
	
	//5_Set Input Capture Edge Select (rising (positive)edge)
	SET_BIT(TCCR1B,ICES1);
	
	
	//6_polling on Input Capture Flag
	while ((TIFR&(1<<ICF1)) == 0);
	
	//7_clear Input Capture Flag
     SET_BIT(TIFR,ICF1);
	 
	 //8_Take value of capture register
	  a=ICR1;
	  
	 //9_clear Input Capture Edge Select (falling (negative )edge)
	 CLR_BIT(TCCR1B,ICES1);
	 
     //10_polling on Input Capture Flag
     while ((TIFR&(1<<ICF1)) == 0);
     
     //11_clear Input Capture Flag
     SET_BIT(TIFR,ICF1);
	
	//12_Take value of capture register
	b=ICR1;
	
	//13_Set Input Capture Edge Select (rising (positive)edge)
	SET_BIT(TCCR1B,ICES1);
	
	//14_polling on Input Capture Flag
	while ((TIFR&(1<<ICF1)) == 0);
	
	//15_clear Input Capture Flag
	SET_BIT(TIFR,ICF1);
	
	//16_Take value of capture register
	c=ICR1;
	
	//17_stpo the timer1 (no clock source)
	TCCR1B=(TCCR1B & 0b11111000);
	//18_measure the frequecy 
	if(a<b && b<c)
	{ 
		on_time=b-a;
		period=c-a;
		duty=((f32)on_time/period)*100;
		
		frequency=F_CPU/period;
	}
	else
	{
		duty=OUT_OF_RANGE;
		frequency=OUT_OF_RANGE;
	}
	*u32_copy_ptr_freq=frequency;
	*u32_copy_ptr_duty=duty;
	*u32_copy_ptr_on_time=on_time;*/
	 u32 a,b,c,high,period,duty_cycle,frequency;
	TCCR1A = 0;
	TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */

	TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
	TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
	TCCR1B = 0xc1;  	/* Rising edge, no prescaler ,noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	c = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */

	TCCR1B = 0;  		/* Stop the timer */
		
		if(a<b && b<c)  	/* Check for valid condition, 
					          to avoid timer overflow reading */
		{
			high=b-a;
			period=c-a;
			duty_cycle=((float)high/period)*100;
			frequency=F_CPU/(period);
		}	
		
		*u32_copy_ptr_freq=frequency;
		*u32_copy_ptr_duty=duty_cycle;
		*u32_copy_ptr_on_time=high;
}

void TIMER1_Void_TOF_CallBack(void(*f_ptr)(void))
{
	TIMER1_OVF_Ptr=f_ptr;
}
void TIMER1_Void_CTC_CallBack(void(*f_ptr)(void))
{
	TIMER1_CTC_Ptr=f_ptr;
}

//ISR of Timer1 of timer over flow
void __vector_9(void) __attribute__((signal,used));
void __vector_9(void)
{
	if(TIMER1_OVF_Ptr!=0)
	{
		TIMER1_OVF_Ptr();
	}
}
//ISR of Timer1 of clear match mode 
void __vector_7(void) __attribute__((signal,used));
void __vector_7(void)
{
	if(TIMER1_CTC_Ptr!=0)
	{
		TIMER1_CTC_Ptr();
	}
}