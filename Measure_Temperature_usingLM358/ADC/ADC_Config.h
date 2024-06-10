/*
 * ADC_Config.h
 *
 * Created: 10/8/2021 3:15:56 PM
 *  Author: Sara Ahmed
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_PRESCALER         64
/*
values of Prescaler :
2
4
16
32
64
128
*/ 
#define ADC_REFERANCE_VOLT     3
/*
value            Voltage Reference Selection
0                AREF, Internal Vref turned off
1                AVCC with external capacitor at AREF pin
3                Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
#define ADC_CHANNEL_AND_GAIN   0b00000
/*
values   Single Ended Input        Positive Differential Input     Positive Differential Input       Gain

00000         ADC0
00001         ADC1
00010         ADC2
00011         ADC3 
00100         ADC4
00101         ADC5
00110         ADC6
00111         ADC7
01000                                            ADC0                         ADC0                     10x
01001                                            ADC1                         ADC0                     10x
01010                                            ADC0                         ADC0                     200x
01011                                            ADC1                         ADC0                     200x
01100                                            ADC2                         ADC2                     10x
01101                                            ADC3                         ADC2                     10x
01110                                            ADC2                         ADC2                     200x
01111                                            ADC3                         ADC2                     200x
10000                                            ADC0                         ADC1                     1x
10001                                            ADC1                         ADC1                     1x
10010                                            ADC2                         ADC1                     1x
10011                                            ADC3                         ADC1                     1x
10100                                            ADC4                         ADC1                     1x
10101                                            ADC5                         ADC1                     1x
10110                                            ADC6                         ADC1                     1x
10111                                            ADC7                         ADC1                     1x
11000                                            ADC0                         ADC2                     1x
11001                                            ADC1                         ADC2                     1x
11010                                            ADC2                         ADC2                     1x
11011                                            ADC3                         ADC2                     1x
11100                                            ADC4                         ADC2                     1x   
11101                                            ADC5                         ADC2                     1
*/
#endif /* ADC_CONFIG_H_ */