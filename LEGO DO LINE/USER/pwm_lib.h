	/*
	**********************************************
	*@file				pwm_lib.h						*
	*@author			Vu Quang Luong					*
	*@date				12/03/2024							*
	**********************************************
*/

#ifndef	__PWM__
#define	__PWM__

#ifdef __cplusplus
	extern "C"{
#endif

#include "stm32f10x.h"     
#include "stm32f10x_rcc.h"  
#include "stm32f10x_gpio.h" 
#include "stm32f10x_tim.h"

//18
//71
#define TIM2_PERIOD			35999
#define TIM2_PRESCALER	1
#define TIM2_REPETITION	0
#define TIM2_PWM_PULSE	(uint16_t) TIM2_PERIOD/2

#define PWM_TIM2_OC1_PIN			GPIO_Pin_0
#define PWM_TIM2_OC2_PIN			GPIO_Pin_1
#define PWM_TIM2_OC3_PIN			GPIO_Pin_2
#define PWM_TIM2_OC4_PIN			GPIO_Pin_3

extern volatile uint32_t timer2_ticks;

void Pwm_Init(void);
void Delay_Ms(uint32_t t);

#ifdef __cplusplus
}
#endif

#endif



/***********************************************/
