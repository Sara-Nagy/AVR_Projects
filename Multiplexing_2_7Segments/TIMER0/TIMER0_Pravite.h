/*
 * TIMER0_Pravite.h
 *
 * Created: 10/17/2021 8:31:35 PM
 *  Author: Sara Ahmed
 */ 


#ifndef TIMER0_PRAVITE_H_
#define TIMER0_PRAVITE_H_

#define TCNT0                *((volatile u8*)(0x52))      //Timer/Counter0 Register

#define TCCR0                *((volatile u8*)(0x53))      //Timer/Counter0 Control Register
#define FOC0                 7                            //Bit 7 – FOC0: Force Output Compare
//Bit 6, 3 – WGM01:0: Waveform Generation Mode
#define WGM00                6
#define WGM01                3
/*

Mode  WGM01(CTC0)   WGM00(PWM0)   Timer/Counter Mode    TOP       Update of       TOV0 Flag Set-on
                                  of Operation                    OCR0       
								  
0      0               0          Normal                 0xFF      Immediate       MAX
1      0               1          PWM, Phase Correct     0xFF      TOP             BOTTOM
2      1               0          CTC                    OCR0      Immediate       MAX
3      1               1          Fast PWM               0xFF      TOP             MAX
*/
//Bit 5:4 – COM01:0: Compare Match Output Mode
#define COM00                4
#define COM01                5
/**** Compare Output Mode, non-PWM Mode ****/
/*
COM01 COM00                Description
0      0                   Normal port operation, OC0 disconnected.
0      1                   Toggle OC0 on compare match
1      0                   Clear OC0 on compare match
1      1                   Set OC0 on compare match
*/
/**** Compare Output Mode, Fast PWM Mode ****/
/*
COM01 COM00      Description
0      0         Normal port operation, OC0 disconnected.
0      1         Reserved
1      0         Clear OC0 on compare match, set OC0 at TOP
1      1         Set OC0 on compare match, clear OC0 at TOP
*/
/**** Compare Output Mode, Phase Correct PWM Mode ****/
/*
COM01 COM00           Description
0      0              Normal port operation, OC0 disconnected.
0      1              Reserved
1      0              Clear OC0 on compare match when up-counting. Set OC0 on compare
                      match when downcounting.
1      1              Set OC0 on compare match when up-counting. Clear OC0 on compare
                      match when downcountin
*/

//Bit 2:0 – CS02:0: Clock Select
#define CS00                  0
#define CS01                  1
#define CS02                  2
/*
CS02 CS01 CS00         Description
0     0    0           No clock source (Timer/Counter stopped).
0     0    1           clkI/O/(No prescaling)
0     1    0           clkI/O/8 (From prescaler)
0     1    1           clkI/O/64 (From prescaler)
1     0    0           clkI/O/256 (From prescaler)
1     0    1           clkI/O/1024 (From prescaler)
1     1    0           External clock source on T0 pin. Clock on falling edge.
1     1    1           External clock source on T0 pin. Clock on rising edge
*/

#define OCR0                 *((volatile u8*)(0x5C))      //Output Compare Register

#define TIMSK                *((volatile u8*)(0x59))      //Timer/Counter Interrupt Mask Register
#define TOIE0                0                             //Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
#define OCIE0                1                            //Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable

#define TIFR                 *((volatile u8*)(0x58))      //Timer/Counter Interrupt Flag Register
#define TOV0                 0                            //Bit 0 – TOV0: Timer/Counter0 Overflow Flag
#define OCF0                 1                            //Bit 1 – OCF0: Output Compare Flag 0

#endif /* TIMER0_PRAVITE_H_ */