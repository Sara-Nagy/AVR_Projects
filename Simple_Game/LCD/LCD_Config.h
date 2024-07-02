/*
 * LCD_Config.h
 *
 * Created: 9/19/2021 10:50:32 PM
 *  Author: IT Shop
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

       /**** HardWare ****/
#define LCD_PORT_data_commond  DIO_PORTC
#define LCD_PORT_RS_RW_EN      DIO_PORTD
#define LCD_PIN_Rs             DIO_PIN0
#define LCD_PIN_RW             DIO_PIN1
#define LCD_PIN_EN             DIO_PIN2

      /**** mode ****/
#define _8_MODE 
//#define _4_MODE   //high nibble

     /**** commands of modes****/
#define _8_BIT_MODE               0x38
#define _4_BIT_MODE_COM1          0x02
#define _4_BIT_MODE_COM2          0x28
#define DISPLAY_ON_CURSOR_ON      0x0E
#define CLEAR_SCREEN              0x01
#define ENTRY_MODE                0x06

#endif /* LCD_CONFIG_H_ */