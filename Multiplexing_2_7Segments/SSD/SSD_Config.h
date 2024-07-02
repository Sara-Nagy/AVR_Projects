/*
 * SSD_Config.h
 *
 * Created: 9/13/2021 5:05:59 PM
 *  Author: Sara Ahmed
 */ 


#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

                  /*mode of seven segment*/
				  /****BCD MODE ****/
                                              
//#define  BCD_MODE                              //if we use BCD decoder mode 
#define LOW_NIBLLE                             //if we use low_nibble of the port in BCD decoder mode 
#define  HIGH_NIBLLE                         //if we use high_nibble of the port in BCD decoder mode
   
               /***  NORMAL MODE ***/
   
#define COMMON_CATHODE                         //if we use common cathode seven segment 
//#define COMMON_ANODE                         //if we use common anode seven segment


#endif /* SSD_CONFIG_H_ */