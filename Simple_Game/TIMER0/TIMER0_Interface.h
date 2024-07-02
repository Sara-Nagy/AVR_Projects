/*
 * TIMER0_.h
 *
 * Created: 10/17/2021 8:30:37 PM
 *  Author: Sara Ahmed
 */ 


#ifndef TIMER0__H_
#define TIMER0__H_

void TIMER0_VoidInit_CTC_Interrupt(void);
/*
Function Name        : timer_CTC_init_interrupt
Function Returns     : void
Function Arguments   : void
Function Description : initialize the interrupt of the CTC mode of timer0.
*/
void TIMER0_VoidGenrate_Wave_NonPWM(void);
/*
	Function Name        : TIMER0_VoidGenrate_Wave_NonPWM
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize the generation of a wave on OC0 pin in NonPWM mode.
*/
void TIMER0_VoidGenrate_Wave_FastPWM(void);
/*
Function Name        : TIMER0_VoidGenrate_Wave_FastPWM
Function Returns     : void
Function Arguments   : void
Function Description : initialize the generation of a wave on OC0 pin in fast PWM mode.
*/
void TIMER0_VoidGenrate_Wave_PhaseCorrectMode(void);
/*
	Function Name        : TIMER0_VoidGenrate_Wave_PhaseCorrectMode
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize the generation of a wave on OC0 pin in phase correct PWM mode.
*/

void TIMER0_Void_CallBack(void(*f_ptr)(void));
/*
Function Name        : TIMER0_Void_CallBack
Function Returns     : void
Function Arguments   : pointer to function.
Function Description : take the instruction that wanted to be executed in the ISR of campare match of timer0.
*/

#endif /* TIMER0__H_ */