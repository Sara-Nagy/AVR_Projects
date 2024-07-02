/*
 * SERVO_MOTOR_Program.c
 *
 * Created: 4/2/2022 10:16:33 PM
 *  Author: Sara Ahmed 
 */ 

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../DIO/DIO_Interface.h"
#include "../TIMER1/TIMER1_Interface.h"
#include "SERVO_MOTOR_Config.h"

void Servo_VoidInit(void)
{
	//set SERVO_CONTROL_PIN as output 
	DIO_VoidSetPinDirection(SERVO_POERT,SERVO_CONTROL_PIN,DIO_OUT);
	
}

void Servo_Set_Angle(u8 u8copy_angle)
{
	f32 time=0;
	if(u8copy_angle==0)
	{
		TIMER1_Genrate_Wave_FastPWM(1);
	}
	else 
	{
		time=(((float)u8copy_angle/(1000.00*180))+(1/1000.00))*1000;  //time in m s
		TIMER1_Genrate_Wave_FastPWM(time);	         
	}
	
}