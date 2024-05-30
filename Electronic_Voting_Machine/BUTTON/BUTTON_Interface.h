/*
 * BUTTON_Inerface.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Sara Nagy
 */

#ifndef BUTTON_BUTTON_INERFACE_H_
#define BUTTON_BUTTON_INERFACE_H_

#define BUTTON_SET_INTERNAL_PULLUP   1
#define BUTTON_CLR_INTERNAL_PULLUP 2

void BUTTON_VoidInit(u8 u8cpy_portindex,u8 u8cpy_pinindex);

/*
Function Name        :BUTTON_VoidInit
Function Returns     : void(nothing)
Function Arguments   : unsigned char portname,unsigned char pinnumber
Function Description : define the given pin in the given port as input pin
*/

void BUTTON_VoidConnect_Internal_Pullup(u8 u8cpy_portindex,u8 u8cpy_pinindex,u8 u8cpy_typeofconnects);
/*
Function Name        : BUTTON_VoidConnect_Internal_Pullup
Function Returns     : void(nothing)
Function Arguments   : unsigned char portname,unsigned char pinnumber
Function Description : define the given pin in the given port as internal pull up
*/

u8 BUTTON_U8GetValue(u8 u8cpy_portindex,u8 u8cpy_pinindex);

/*
Function Name        : BUTTON_U8GetValue
Function Returns     : unsigned char
Function Arguments   : unsigned char portname,unsigned char pinnumber
Function Description : Returns 0 or 1 depend on the status of the button(pressed or not)
 and the type of connection (pull up or pull down)
*/



#endif /* BUTTON_BUTTON_INERFACE_H_ */
