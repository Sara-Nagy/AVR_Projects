/*
 * SSD_Interface.h
 *
 * Created: 9/13/2021 5:05:13 PM
 *  Author: Sara Ahmed
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include "../LIB/STD_TYPES.h"

void SSD_VoidInit(u8 u8cpy_portindex);
/*
 * FUNCTION NAME:       SSD_VoidInit
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned char (port number).
 * FUNCTION DESCRIPTION:set the given port as output to switch on the seven segment.
 */
void SSD_VoidBCDInit(u8 u8cpy_portindex);
/*
 * FUNCTION NAME:        SSD_VoidBCDInit
 * FUNCTION RETURN:      nothing(void)
 * FUNCTION ARGUMENTS:   unsigned char (port number).
 * FUNCTION DESCRIPTION: set the high or low nibble as output to switch on seven segment using BCD decoder.
 */
void SSD_VoidWrite(u8 u8cpy_portindex,u8 u8cpy_number);
/*
 * FUNCTION NAME:        SSD_VoidWrite
 * FUNCTION RETURN:      nothing(void)
 * FUNCTION ARGUMENTS:   unsigned char (port number) ,unsigned char (number).
 * FUNCTION DESCRIPTION: write the given number on the seven segment.
 */

 void SSD_VoidBCDWrite(u8 u8cpy_portindex,u8 u8cpy_number);
 /*
 * FUNCTION NAME:        SSD_VoidBCDWrite
 * FUNCTION RETURN:      nothing(void)
 * FUNCTION ARGUMENTS:   unsigned char (port number) ,unsigned char (number).
 * FUNCTION DESCRIPTION: write the given number on the BCD decoder.
 */
 
 
 
#endif /* SSD_INTERFACE_H_ */