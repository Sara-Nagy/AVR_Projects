/*
 * DIO_Interface.h
 *
 * Created: 9/8/2021 11:49:24 AM
 *  Author: Sara Nagy
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_OUT    1
#define DIO_IN     2

#define DIO_HIGH   1
#define DIO_LOW    0

#define DIO_SET_PULLUP    1
#define DIO_clr_PULLUP    2

#define DIO_PORTA 1
#define DIO_PORTB 2
#define DIO_PORTC 3
#define DIO_PORTD 4

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


void DIO_VoidSetPinDirection(u8 u8cpy_portindex ,u8 u8cpy_pinindex,u8 u8cpy_direction);
/*
 * FUNCTION NAME:DIO_VoidSetPinDirection
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number), unsigned char (pin number) and
 * unsigned char (value of direction ).
 * FUNCTION DESCRIPTION:set the direction value in the given pin in the given port.
 */

void DIO_VoidSetPortDirection(u8 u8cpy_portindex ,u8 u8cpy_direction);
/*
 * FUNCTION NAME:DIO_VoidSetPortDirection
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number)and
 * unsigned char (value of direction ).
 * FUNCTION DESCRIPTION:set the direction value in the given port.
 */
void DIO_VoidSetPinValue(u8 u8cpy_portindex ,u8 u8cpy_pinindex,u8 u8cpy_value);
/*
 * FUNCTION NAME:DIO_VoidSetPinValue
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number), unsigned char (pin number) and
 * unsigned char (value of pin ).
 * FUNCTION DESCRIPTION:set the given pin in the given port by the given value .
 */
void DIO_VoidSetLowNibbleValue(u8 u8cpy_portindex ,u8 u8cpy_value);
/*
 * FUNCTION NAME:DIO_VoidSetLowNiblleValue
 * FUNCTION RETURN:nothing(void)
 * FUNCTION ARGUMENTS:unsigned char (port number) and
 * unsigned char (value of port ).
 * FUNCTION DESCRIPTION:set the low nibble of the given port by the given value .
 */
void DIO_VoidSetHighNibbleValue(u8 u8cpy_portindex ,u8 u8cpy_value);
/*
 * FUNCTION NAME: DIO_VoidSetHighNibbleValue
 * FUNCTION RETURN:nothing(void)
 * FUNCTION ARGUMENTS:unsigned char (port number) and
 * unsigned char (value of port ).
 * FUNCTION DESCRIPTION:set the high nibble of the given port by the given value .
 */
void DIO_VoidSetPortValue(u8 u8cpy_portindex ,u8 u8cpy_value);
/*
 * FUNCTION NAME:DIO_VoidSetPortValue
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number) and
 * unsigned char (value of port ).
 * FUNCTION DESCRIPTION:set the given port by the given value .
 */
void DIO_VoidTogglePin(u8 u8cpy_portindex,u8 u8cpy_pinindex);
/*
 * FUNCTION NAME:DIO_VoidTogglePin
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number) and
 * unsigned char (pin number ).
 * FUNCTION DESCRIPTION:toggle the given pin the given port .
 */
void DIO_VoidTogglePort(u8 u8cpy_portindex);
/*
 * FUNCTION NAME:DIO_VoidTogglePort
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number).
 * FUNCTION DESCRIPTION:toggle the given port .
 */

void DIO_VoidConnectPullUpPin(u8 u8cpy_portindex,u8 u8cpy_pinindex,u8 u8cpy_value);
/*
 * FUNCTION NAME:DIO_VoidConnectPullUpPin
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number), unsigned char (pin number) and
 * unsigned char (the value )
 * FUNCTION DESCRIPTION:set or clear the pull up resistor in the given pin in the given port  .
 */

void DIO_VoidConnectPullUpPort(u8 u8cpy_portindex,u8 u8cpy_value);
/*
 * FUNCTION NAME:DIO_VoidConnectPullUpPort
 * FUNCTION RETURN:nothing
 * FUNCTION ARGUMENTS:unsigned char (port number)and
 * unsigned char (the value )
 * FUNCTION DESCRIPTION:set or clear the pull up resistor in the given port  .
 */
u8 DIO_U8GetPinValue(u8 u8cpy_portindex ,u8 u8cpy_pinindex);
/*
 * FUNCTION NAME:DIO_U8GetPinValue
 * FUNCTION RETURN:unsigned char (value of the given pin in the given port)
 * FUNCTION ARGUMENTS:unsigned char (port number)and unsigned char (pin number).
 * FUNCTION DESCRIPTION:get the value of the given pin in the given port .
 */
u8 DIO_U8GetPortValue(u8 u8cpy_portindex);
/*
 * FUNCTION NAME:DIO_U8GetPinValue
 * FUNCTION RETURN:unsigned char (value of  the given port)
 * FUNCTION ARGUMENTS:unsigned char (port number)and unsigned char (pin number).
 * FUNCTION DESCRIPTION:get the value of the given port .
 */



#endif /* DIO_INTERFACE_H_ */