/*
 * TIMER1_Pravite.h
 *
 * Created: 2/20/2022 7:12:20 PM
 *  Author: Sara Ahmed
 */ 


#ifndef TIMER1_PRAVITE_H_
#define TIMER1_PRAVITE_H_

#define OUT_OF_RANGE 0xFFFF


#define TCNT1          *((volatile u16*)(0x4C))            //Timer/Counter1 Register
#define TCNT1L         *((volatile u8*)(0x4C))             //Timer/Counter1 Register High
#define TCNT1H         *((volatile u8*)(0x4D))             //Timer/Counter1 Register Low

#define TCCR1B          *((volatile u8*)(0x4E))            //Timer/Counter1 Control Register B
                                                           
#define ICNC1            7                                  //Bit 7 – ICNC1: Input Capture Noise Canceler
#define ICES1            6                                  //Bit 6 – ICES1: Input Capture Edge Select
#define WGM13            4                                  //Waveform Generation Mode
#define WGM12            3                                  //Waveform Generation Mode
#define CS12             2                                  //Clock Select
#define CS11             1                                  //Clock Select
#define CS10             0                                  //Clock Select
/** 
Clock Select Bit Description
CS12 CS11 CS10   Description
0     0    0     No clock source (Timer/Counter stopped).
0     0    1     clkI/O/1 (No prescaling)
0     1    0     clkI/O/8 (From prescaler)
0     1    1     clkI/O/64 (From prescaler)
1     0    0     clkI/O/256 (From prescaler)
1     0    1     clkI/O/1024 (From prescaler)
1     1    0     External clock source on T1 pin. Clock on falling edge.
1     1    1     External clock source on T1 pin. Clock on rising edge.
**/

#define TCCR1A     *((volatile u8*)(0x4F))               //Timer/Counter1 Control Register A

#define COM1A1     7                                     //Compare Output Mode for Channel A 
#define COM1A0     6                                     //Compare Output Mode for Channel A 
#define COM1B1     5                                     //Compare Output Mode for Channel B 
#define COM1B1     4                                     //Compare Output Mode for Channel B
/**
Compare Output Mode, non-PWM 
COM1A1/COM1B1    COM1A0/COM1B0           Description
0                 0                      Normal port operation, OC1A/OC1B disconnected.
0                 1                      Toggle OC1A/OC1B on compare match
1                 0                      Clear OC1A/OC1B on compare match (Set output to low level)
1                 1                      Set OC1A/OC1B on compare match (Set output to high level)
output to high level)
**/
/**
Compare Output Mode, Fast PWM

COM1A1/COM1B1     COM1A0/COM1B0         Description
0                 0                     Normal port operation, OC1A/OC1B disconnected.
0                 1                     WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
                                        For all other WGM13:0 settings, normal port  operation, OC1A/OC1B disconnected.
1                 0                     Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP
1                 1                     Set OC1A/OC1B on compare match, clear OC1A/OC1B at TOP
**/
/**
Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
COM1A1/COM1B1        COM1A0/COM1B0      Description
0                    0                  Normal port operation, OC1A/OC1B disconnected
0                    1                  WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
                                        For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
1                    0                  Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when downcounting.
1                    1                  Set OC1A/OC1B on compare match when upcounting.Clear OC1A/OC1B on compare match when downcounting.
**/
#define FOC1A        3                 //Force Output Compare for Channel A
#define FOC1B        2                 //Force Output Compare for Channel B
#define WGM11        1                 //Waveform Generation Mode
#define WGM10        0                 //Waveform Generation Mode
/**
Waveform Generation Mode Bit Description
Mode WGM13 WGM12 WGM11 WGM10    Timer/Counter Mode of Operation    TOP       Update of OCR1x     TOV1 Flag Set on
0    0     0     0     0        Normal                            0xFFFF     Immediate             MAX
1    0     0     0     1        PWM, Phase Correct, 8-bit         0x00FF      TOP                 BOTTOM
2    0     0     1     0        PWM, Phase Correct, 9-bit         0x01FF      TOP                 BOTTOM
3    0     0     1     1        PWM, Phase Correct, 10-bit        0x03FF      TOP                 BOTTOM
4    0     1     0     0        CTC                               OCR1A     Immediate              MAX
5    0     1     0     1        Fast PWM, 8-bit                   0x00FF     TOP                   TOP
6    0     1     1     0        Fast PWM, 9-bit                   0x01FF     TOP                   TOP
7    0     1     1     1        Fast PWM, 10-bit                  0x03FF     TOP                   TOP
8    1     0     0     0        PWM, Phase and Frequency Correct  ICR1       BOTTOM               BOTTOM
9    1     0     0     1        PWM, Phase and Frequency Correct  OCR1A      BOTTOM               BOTTOM
10   1     0     1     0        PWM, Phase Correct                ICR1       TOP                  BOTTOM
11   1     0     1     1        PWM, Phase Correct                OCR1A      TOP                  BOTTOM
12   1     1     0     0        CTC                               ICR1     Immediate               MAX
13   1     1     0     1        Reserved – – –
14   1     1     1     0        Fast PWM                          ICR1      TOP                     TOP
15   1     1     1     1        Fast PWM                          OCR1A     TOP                     TOP
**/

#define OCR1A             *((volatile u16*)(0x4A))     //Output Compare Register 1 A
#define OCR1AL            *((volatile u8*)(0x4A))      //Output Compare Register 1 A Low      
#define OCR1AH            *((volatile u8*)(0x4B))      //Output Compare Register 1 A Low 

#define OCR1B             *((volatile u16*)(0x48))     //Output Compare Register 1 B
#define OCR1BL            *((volatile u8*)(0x48))      //Output Compare Register 1 B Low
#define OCR1BH            *((volatile u8*)(0x49))      //Output Compare Register 1 B Low    

#define ICR1              *((volatile u16*)(0x46))     //Input Capture Register 1
#define ICR1L             *((volatile u8*)(0x46))     //Input Capture Register 1 Low
#define ICR1H             *((volatile u8*)(0x47))     //Input Capture Register 1 High
 
#define TIMSK             *((volatile u8*)(0x59))     //Timer/Counter Interrupt Mask Register

#define TICIE1             5                          //Bit 5 – TICIE1: Timer/Counter1, Input Capture Interrupt Enable
#define OCIE1A             4                          //Bit 4 – OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable
#define OCIE1B             3                          //Bit 3 – OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable
#define TOIE1              2                          //Bit 2 – TOIE1: Timer/Counter1, Overflow Interrupt Enable

#define TIFR              *((volatile u8*)(0x58))     //Timer/Counter Interrupt Flag Register

#define ICF1              5                           //Bit 5 – ICF1: Timer/Counter1, Input Capture Flag
#define OCF1A             4                           //Bit 4 – OCF1A: Timer/Counter1, Output Compare A Match Flag
#define OCF1B             3                           // Bit 3 – OCF1B: Timer/Counter1, Output Compare B Match Flag
#define TOV1              2                           //Bit 2 – TOV1: Timer/Counter1, Overflow 

#endif /* TIMER1_PRAVITE_H_ */