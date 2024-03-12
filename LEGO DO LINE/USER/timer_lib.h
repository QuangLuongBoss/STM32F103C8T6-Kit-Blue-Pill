/*
	********************************************************************************************
	*@file				timer_lib.h																										*
	*@author			Vu Quang Luong																								*
	*@date				24/05/2023																										*
	********************************************************************************************
*/

#ifndef __TIMER__
#define __TIMER__

#ifdef __cplusplus
	extern "C"{
#endif

#include "stm32f10x.h"     
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

#define USE_TIM2
//#define USE_TIM3
//#define USE_TIM4

#define TIMER1	1
#define TIMER2	2
#define TIMER3	3
#define TIMER4	4
#define OC1			1
#define OC2			2
#define OC3			3
#define OC4			4

#define	USE_PWM

#define PWM_TIM2_OC1_PA0	1
#define PWM_TIM2_OC2_PA1	2
#define PWM_TIM2_OC3_PA2	3
#define PWM_TIM2_OC4_PA3	4
#define PWM_TIM2_ALL			5

#define PWM_TIM4_OC1_PB6	6
#define PWM_TIM4_OC2_PB7	7
#define PWM_TIM4_OC3_PB8	8
#define PWM_TIM4_OC4_PB9	9
#define PWM_TIM4_ALL			10

#ifdef USE_TIM2
#define TIM2_PERIOD		7199
#define TIM2_PRESCALE	0
extern volatile uint32_t timer2_ticks;
#endif

#ifdef USE_TIM4
#define TIM4_PERIOD		7199
#define TIM4_PRESCALE	0
extern volatile uint32_t timer4_ticks;
#endif

void Timer_BasicInit(uint8_t TIMERx, uint16_t timer_mode, uint16_t timer_period, uint16_t timer_prescaler, uint16_t clock_division, uint8_t repetition_counter, FunctionalState new_state);

void Timer_OCx_Init(TIM_TypeDef* TIMx, uint8_t OCx, uint16_t timer_oc_mode, uint16_t timer_output_state, uint16_t timer_pulse, uint16_t timer_oc_polarity);
void Timer_OCx_SetPulse(TIM_TypeDef* TIMx, uint8_t OCx, uint16_t timer_pulse);
void Pwm_Init(uint8_t pin_port, uint8_t duty, uint16_t timer_period, uint16_t timer_prescaler);

void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);

uint32_t SysTick_Millis(void);
uint32_t Timer1_Millis(void);
uint32_t Timer2_Millis(void);
uint32_t Timer3_Millis(void);
uint32_t Timer4_Millis(void);

void Reset_Timer2_Ticks(void);
void Reset_Timer3_Ticks(void);
void Reset_Timer4_Ticks(void);

void Timer2_Delay_Ms(uint32_t t);
void Timer3_Delay_Ms(uint32_t t);
void Timer4_Delay_Ms(uint32_t t);


void PWM_Configuration(void);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ***********************************************/
/*********************************************************************************************/

