/*
	**********************************************
	*@file				L298N_lib.h						*
	*@author			Vu Quang Luong				*
	*@date				23/02/2024								*
	**********************************************
*/

#ifndef	__L298N__
#define	__L298N__

#ifdef __cplusplus
	extern "C"{
#endif

#include "stm32f10x.h"     
#include "stm32f10x_rcc.h"  
#include "stm32f10x_gpio.h" 
#include "timer_lib.h"

#define IN1_PIN		GPIO_Pin_9
#define IN2_PIN 	GPIO_Pin_8
#define IN3_PIN 	GPIO_Pin_7
#define IN4_PIN		GPIO_Pin_6
#define ENA
#define ENB
#define L298N_PORT		GPIOB			
#define MOTOR_A		'A'
#define MOTOR_B		'B'
#define FORWARD		'F'
#define BACKWARD	'B'

void L298N_GpioInit(void);
void L298N_Init(void);
void L298N_SetLevel(char motor, uint8_t level);
void L298N_SetForward(char motor);
void L298N_SetBackward(char motor);

#ifdef __cplusplus
}
#endif

#endif



/***********************************************/
