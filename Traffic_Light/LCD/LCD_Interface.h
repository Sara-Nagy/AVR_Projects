/*
 * IncFile1.h
 *
 * Created: 9/19/2021 10:49:47 PM
 *  Author: IT Shop
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "../LIB/STD_TYPES.h"

             /**** General Commands ****/
#define RETURN_HOME                         0x02   //OR: 0x03
#define SHIFT_CURSOR_TO_LEFT                0x04
#define SHIFT_DISPLAY_RIGHT                 0x05
#define SHIFT_CURSOR_TO_RIGHT               0x06
#define SHIFT_DISPLAY_LEFT                  0x07
//0X08 blinks off
//0x09 blinks on
#define DISPLAY_OFF_CURSOR_OFF              0x08    //OR: 0x09
//0X0A blinks off
//0x0B blinks on
#define DISPLAY_OFF_CURSOR_ON              0x0A     //OR: 0x0B
//0X0C blinks off
//0x0D blinks on
#define DISPLAY_ON_CURSOR_OFF              0x0C      //OR: 0x0D
#define DISPLAY_ON_CURSOR_ON               0x0E     //without blinking
#define DISPLAY_CURSOR_blinking            0x0F
#define SHIFT_CURSOR_POSITION_TO_LEFT      0x10     //OR: 1)0x11   2)0x12    3)0x13
#define SHIFT_CURSOR_POSITION_TO_RIGHT     0x14     //OR: 1)0x15   2)0x16    3)0x17
#define SHIFT_ENTIRE_DISPLAY_TO_LEFT       0x18     //OR: 1)0x19   2)0x1A    3)0x1B
#define SHIFT_ENTIRE_DISPLAY_TO_RIGHT      0x1C     //OR: 1)0x1D   2)0x1E    3)0x1F


void LCD_VoidInit(void);
/*
 * FUNCTION NAME:       LCD_VoidInit
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:switch on the LCD to work.
 */
void LCD_VoidSendChar(u8 u8cpy_data);
/*
 * FUNCTION NAME:       LCD_VoidSendChar
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned character (data:ASCII Code of given char).
 * FUNCTION DESCRIPTION:display the given character(data)on the LCD.
 */
void LCD_VoidSendCommand(u8 u8cpy_command);
/*
 * FUNCTION NAME:       LCD_VoidSendCOM
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned character (command).
 * FUNCTION DESCRIPTION:perform the given command by LCD.
 */
void LCD_VoidSendString(u8* u8cpy_poniter_string);
/*
 * FUNCTION NAME:       LCD_VoidSendString
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  pointer to unsigned character (string).
 * FUNCTION DESCRIPTION:display the given string(data)on the LCD.
 */
void LCD_VoidSendNumber(s32 s32cpy_number);
/*
 * FUNCTION NAME:       LCD_VoidSendNumber
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  signed integer (number).
 * FUNCTION DESCRIPTION:display the given number(data)on the LCD.
 */
void LCD_VoidSaveCustomChar(const u8 u8cpy_arr,u8 u8cpy_num);
/*
 * FUNCTION NAME:       LCD_VoidSaveCustomChar
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  array of 8 constant character(the custom character) and unsigned character(address of custom character).
 * FUNCTION DESCRIPTION:store the given data in CGRAM so form the custom character.
 */
void LCD_VoidSetCursorPosition(u8 u8cpy_row,u8 u8cpy_column);
/*
 * FUNCTION NAME:       LCD_VoidSetCursorPosition
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned character(number of row)and  unsigned character(number of culomn).
 * FUNCTION DESCRIPTION:set the cursor in the given position.
 */
void LCD_VoidClearScreen(void);
/*
 * FUNCTION NAME:       LCD_VoidClrarScrean
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:clear the screen of the LCD.
 */


#endif /* INCFILE1_H_ */