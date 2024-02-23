/*
	**********************************************
	*@file				lego_motor_43362.h		*
	*@author			Vu Quang Luong				*
	*@date				20/02/2024						*
	**********************************************
*/

#ifndef	__LEGO_MOTOR_43362__
#define	__LEGO_MOTOR_43362__

#ifdef __cplusplus
	extern "C"{
#endif

#include "L298N_lib.h"
#include "timer_lib.h"
#include "stm32f10x_gpio.h"


/* Use L298N Module */



void LegoMotor_Init(void);
void LegoMotor_SetLevel(char motor, uint8_t level);

#ifdef __cplusplus
}
#endif

#endif



/***********************************************/
