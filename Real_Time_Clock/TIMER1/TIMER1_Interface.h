/*
 * IncFile1.h
 *
 * Created: 2/20/2022 7:09:56 PM
 *  Author: Sara Ahmed 
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "../LIB/STD_TYPES.h"


void TIMER1_Void_TimerOverFlow_Interrupt(void);

/*
Function Name        : TIMER1_Void_TimerOverFlow_Interrupt
Function Returns     : void
Function Arguments   : void
Function Description : initialize the interrupt of time over flow mode of timer1.
*/

void TIMER1_Void_TOF_CallBack(void(*f_ptr)(void));
/*
Function Name        : TIMER1_Void_TOF_CallBack
Function Returns     : void
Function Arguments   : pointer to function.
Function Description : take the instructions that wanted to be executed in the ISR of timer over flow of timer1.
*/
void TIMER1_Void_CTC_Interrupt(void);
/*
Function Name        : TIMER1_Void_CTC_Interrupt
Function Returns     : void
Function Arguments   : void
Function Description : initialize the interrupt of clear on compare match  mode of timer1.
*/
void TIMER1_Void_CTC_CallBack(void(*f_ptr)(void));
/*
Function Name        : TIMER1_Void_CTC_CallBack
Function Returns     : void
Function Arguments   : pointer to function.
Function Description : take the instructions that wanted to be executed in the ISR of clear on compare match of timer1.
*/

void TIMER1_Frequency_Duty_Measure_PWM(u32 * u32_copy_ptr_freq,u32 * u32_copy_ptr_duty,u32 * u32_copy_ptr_on_time);
/*
Function Name        : TIMER1_Frequency_Duty_Measure_PWM.
Function Returns     : void 
Function Arguments   : pointer to unsigned int(frequency),pointer to unsigned int(duty),pointer to unsigned int(on_time). 
Function Description : measure the frequency ,the Duty cycle and on_time of a PWM signal by using ICU(Input Capture Unit) in timer1.
*/



#endif /* INCFILE1_H_ */