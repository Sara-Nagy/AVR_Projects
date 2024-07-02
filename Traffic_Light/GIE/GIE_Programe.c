/*
 * GIE_Programe.c
 *
 * Created: 9/27/2021 6:22:51 PM
 *  Author: Sara Ahmed
 */ 

#include  "../LIB/BIT_MATH.h"
#include  "../LIB/STD_TYPES.h"
#include  "GIE_Config.h"
#include  "GIE_Pravite.h"

void GIE_VoidEnable_GlabelInterrupt(void)
{
	SET_BIT(SREG,I_BIT);
}
void GIE_VoidDisable_GlabelInterrupt(void)
{
	CLR_BIT(SREG,I_BIT);
}
