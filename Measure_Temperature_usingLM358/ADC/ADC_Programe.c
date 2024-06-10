/*
 * ADC_Programe.c
 *
 * Created: 10/8/2021 3:16:55 PM
 *  Author: Sara Ahmed
 */ 
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../ADC/ADC_Config.h"
#include "../ADC/ADC_Pravite.h"
#include "../DIO/DIO_Interface.h"

void ADC_VoidInit(void)
{
	//1_select vref 01 ADCMAX
   ADMUX=(ADMUX & 0b00111111)|(ADC_REFERANCE_VOLT<<6);

	//2_select adjustment right
	CLR_BIT(ADMUX,ADLAR);

	//3_select prescaler: adjust ADC clock
	ADCSRA=(ADCSRA & 0b11111000)|ADC_PRESCALER;

	//4_disable auto trigger
	CLR_BIT(ADCSRA,ADATE);

	//5_disable interrupt :CLR    OR  5_enable interrupt :SET
	SET_BIT(ADCSRA, ADIE);

	//6_enable ADC peripheral
	SET_BIT(ADCSRA,ADEN);	
}

u16 ADC_U16GetData(void)
{
	u16 result=0;
	
	//1_select channel 
	ADMUX=(ADMUX   &   0b11100000)|(ADC_CHANNEL_AND_GAIN);

	//2_start conversion
	SET_BIT(ADCSRA,ADSC);
 
    //3_polling on ADSC :stay in your position till ADIF become 0
	while(GET_BIT(ADCSRA,ADSC)==1);
	
	/* OR:
	//3_polling on flag :stay in your position till ADIF become 1
	while(GET_BIT(ADCSRA,ADIF)==0);
	SET_BIT(ADCSRA,ADIF);  //clear flag
	*/

	//4_get digital value
	result=ADCL;
	result|=(ADCH<<8);
  
	/*OR:
	result=ADC_DATA;
	*/

	return result;
}
void ADC_VoidStarConversion(void)
{
        //1_select channel
   ADMUX=(ADMUX   &   0b11100000)|(ADC_CHANNEL_AND_GAIN);

     //2_start conversion
   SET_BIT(ADCSRA,ADSC);	
}