/*
 * SERVO_MOTOR_Interface.h
 *
 * Created: 4/2/2022 10:17:00 PM
 *  Author: IT Shop
 */ 


#ifndef SERVO_MOTOR_INTERFACE_H_
#define SERVO_MOTOR_INTERFACE_H_

#include "../LIB/STD_TYPES.h"

void Servo_VoidInit(void);
/*
Function Name        : Servo_VoidInit
Function Returns     : void(nothing)
Function Arguments   : void(nothing)
Function Description : set the pin connected to the control pin of the servo.
*/
void Servo_Set_Angle(u8 u8copy_angle);
/*
Function Name        : Servo_VoidSet_Angle
Function Returns     : void(nothing)
Function Arguments   : The value of angle (unsigned char).
Function Description : control the value of angle that wanted to be moved by the servo.
*/


#endif /* SERVO_MOTOR_INTERFACE_H_ */