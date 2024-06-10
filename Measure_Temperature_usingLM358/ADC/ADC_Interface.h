/*
 * ADC_Interface.h
 *
 * Created: 10/8/2021 3:15:25 PM
 *  Author: IT Shop
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_VoidInit(void);
/*
 * FUNCTION NAME:       ADC_VoidInit 
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:switch on the ADC.
*/
u16 ADC_U16GetData(void);
/*
 * FUNCTION NAME:       ADC_U16GetData 
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned short integer (data).
 * FUNCTION DESCRIPTION:get(read)the data that converted from the ADC.
*/
void ADC_VoidStarConversion(void);
/*
 * FUNCTION NAME:       ADC_VoidStarConversion 
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:star converting data(a sample of an analog signal)form analog to digital.
*/

#endif /* ADC_INTERFACE_H_ */