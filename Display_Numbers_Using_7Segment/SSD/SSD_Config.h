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
                                              
#define  LOW_NIBLLE     0                           //if we use low_nibble of the port in BCD decoder mode 
#define  HIGH_NIBLLE    1                        //if we use high_nibble of the port in BCD decoder mode
#define  BCD_MODE    LOW_NIBLLE                           //if we use BCD decoder mode 
   
               /***  NORMAL MODE ***/
   
#define COMMON_CATHODE   0                        //if we use common cathode seven segment 
#define COMMON_ANODE     1                         //if we use common anode seven segment

#define SSD_MODE    COMMON_CATHODE


#endif /* SSD_CONFIG_H_ */