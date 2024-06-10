/*
 * ADC_Pravite.h
 *
 * Created: 10/8/2021 3:16:30 PM
 *  Author: Sara Ahmed
 */ 


#ifndef ADC_PRAVITE_H_
#define ADC_PRAVITE_H_
   
	   /***  ADMUX : ADC Multiplexer Selection Register   ***/
#define ADMUX              *((volatile u8 *)(0x27))   
//Bit 7:6 – REFS1:0: Reference Selection Bits
#define REFS1              7 
#define REFS0              6
/*
REFS1 REFS0                Voltage Reference Selection
0      0                   AREF, Internal Vref turned off
0      1                   AVCC with external capacitor at AREF pin
1      0                   Reserved
1      1                   Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
#define ADLAR              5                            //Bit 5 – ADLAR: ADC Left Adjust Result

     /***  ADCSRA:ADC Control and Status Register   ***/
#define ADCSRA             *((volatile u8 *)(0x26))
#define ADEN                7                           //Bit 7 – ADEN: ADC Enable
#define ADSC                6                           //Bit 6 – ADSC: ADC Start Conversion
#define ADATE               5                          //Bit 5 – ADATE: ADC Auto Trigger Enable
#define ADIF                4                          //Bit 4 – ADIF: ADC Interrupt Flag
#define ADIE                3                          //Bit 3 – ADIE: ADC Interrupt Enable

     /*** The ADC Data Register:ADCL and ADCH   ***/
#define ADCH               *((volatile u8 *)(0x25))
#define ADCL               *((volatile u8 *)(0x24))
#define ADC_DATA           *((volatile u16 *)(0x24))

    /*** SFIOR:Special FunctionIO Register   ***/
#define SFIOR              *((volatile u8 *)(0x50))






#endif /* ADC_PRAVITE_H_ */