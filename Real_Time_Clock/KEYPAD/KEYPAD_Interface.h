/*
 * KEYPAD_Interface.h
 *
 * Created: 9/20/2021 9:11:44 PM
 *  Author: Sara Ahmed
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "../LIB/STD_TYPES.h"

#define KEYPAD_NOT_PRESSED   0xFF

void KEYPAD_VoidInit(void);
/*
 * FUNCTION NAME:       KEYPAD_VoidInit
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:switch on the KEYPAD to work.
 */
u8 KEYPAD_U8Check_PressedKey(void);
/*
 * FUNCTION NAME:        KEYPAD_U8Check_PressedKey
 * FUNCTION RETURN:     unsigned character (the number of switch we pressed).
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:return the number of switch we pressed .
 */

#endif /* KEYPAD_INTERFACE_H_ */