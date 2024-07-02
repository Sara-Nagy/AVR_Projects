/*
 * TIMER0_Config.h
 *
 * Created: 10/17/2021 8:30:00 PM
 *  Author: Sara Ahmed
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#define TIMER0_CLOCK    0b101
/*
                       Description
0     0    0           No clock source (Timer/Counter stopped).
0     0    1           clkI/O/(No prescaling)
0     1    0           clkI/O/8 (From prescaler)
0     1    1           clkI/O/64 (From prescaler)
1     0    0           clkI/O/256 (From prescaler)
1     0    1           clkI/O/1024 (From prescaler)
1     1    0           External clock source on T0 pin. Clock on falling edge.
1     1    1           External clock source on T0 pin. Clock on rising edge
*/
#define OC0_COMPARA_MATCH     0b01
/*
                           Description
0      0                   Normal port operation, OC0 disconnected.
0      1                   Toggle OC0 on compare match
1      0                   Clear OC0 on compare match
1      1                   Set OC0 on compare match
*/
#define OC0_FAST_PWM     0b10
/*
                 Description
0      0         Normal port operation, OC0 disconnected.
0      1         Reserved
1      0         Clear OC0 on compare match, set OC0 at TOP
1      1         Set OC0 on compare match, clear OC0 at TOP
*/
#define OC0_PHASE_CORRECT_PWM     0b10
/*
                      Description
0      0              Normal port operation, OC0 disconnected.
0      1              Reserved
1      0              Clear OC0 on compare match when up-counting. Set OC0 on compare
                      match when downcounting.
1      1              Set OC0 on compare match when up-counting. Clear OC0 on compare
                       match when downcountin.
*/
#endif /* TIMER0_CONFIG_H_ */