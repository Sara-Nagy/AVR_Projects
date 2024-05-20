/*
 * LED_Interface.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Sara Nagy
 */

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_

#include "../LIB/STD_TYPES.h"

void LED_VoidInit(u8 u8cpy_portindex,u8 u8cpy_pinindex);
/*
 * FUNCTION NAME:LED_VoidInit
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number)and unsigned char (pin number).
 * FUNCTION DESCRIPTION:set the given pin in the given port as output pin.
 */
void LED_VoidSet_Led_On(u8 u8cpy_portindex,u8 u8cpy_pinindex);
/*
 * FUNCTION NAME:LED_VoidSet_Led_On
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number), unsigned char (pin number)
 * FUNCTION DESCRIPTION:set the given pin in the given port at high state.
 */
void LED_VoidSet_Led_Off(u8 u8cpy_portindex,u8 u8cpy_pinindex);
/*
 * FUNCTION NAME:LED_VoidSet_Led_Off
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number), unsigned char (pin number)
 * FUNCTION DESCRIPTION:set the given pin in the given port at low state.
 */
void LED_VoidToggle_Led(u8 u8cpy_portindex,u8 u8cpy_pinindex);
/*
 * FUNCTION NAME:LED_VoidTogglePin
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number), unsigned char (pin number).
 * FUNCTION DESCRIPTION:toggle the given pin in the given port.
 */
u8 LED_U8Read_Led(u8 u8cpy_portindex,u8 u8cpy_pinindex);
/*
 * FUNCTION NAME:LED_VoidReadPin
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number), unsigned char (pin number).
 * FUNCTION DESCRIPTION:read the value of the given port in the given pin.
 */

#endif /* LED_LED_INTERFACE_H_ */
