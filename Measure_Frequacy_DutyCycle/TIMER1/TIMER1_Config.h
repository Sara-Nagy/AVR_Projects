/*
 * TIMER1_Config.h
 *
 * Created: 2/20/2022 7:08:46 PM
 *  Author: Sara Ahmed 
 */ 


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#define  F_CPU 8000000UL


#define TIMER1_CLOCK    0b001
/*
                       Description
0     0    0           No clock source (Timer/Counter stopped).
0     0    1           clkI/O/(No prescaling)
0     1    0           clkI/O/8 (From prescaler)
0     1    1           clkI/O/64 (From prescaler)
1     0    0           clkI/O/256 (From prescaler)
1     0    1           clkI/O/1024 (From prescaler)
1     1    0           External clock source on T1 pin. Clock on falling edge.
1     1    1           External clock source on T1 pin. Clock on rising edge
*/





#endif /* TIMER1_CONFIG_H_ */