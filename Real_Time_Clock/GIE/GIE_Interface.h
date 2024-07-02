/*
 * GIE_Interface.h
 *
 * Created: 9/27/2021 6:22:28 PM
 *  Author: IT Shop
 */ 


#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

void GIE_VoidEnable_GlabelInterrupt(void);
/*
 * FUNCTION NAME:        GIE_VoidEnable_GlabelInterrupt
 * FUNCTION RETURN:      nothing(void)
 * FUNCTION ARGUMENTS:   nothing(void)
 * FUNCTION DESCRIPTION:set I-Bit in SREG (status register): open global interrupt enable.
 */

void GIE_VoidDisable_GlabelInterrupt(void);
/*
 * FUNCTION NAME:         GIE_VoidDisable_GlabelInterrupt
 * FUNCTION RETURN:      nothing(void)
 * FUNCTION ARGUMENTS:   nothing(void)
 * FUNCTION DESCRIPTION:clear I-Bit in SREG (status register): close global interrupt enable.
 */




#endif /* GIE_INTERFACE_H_ */