	/*
	**********************************************
	*@file				MX1508_lib.h						*
	*@author			Vu Quang Luong					*
	*@date				05/03/2024							*
	**********************************************
*/

#ifndef	__MX1508__
#define	__MX1508__

#ifdef __cplusplus
	extern "C"{
#endif

#include "stm32f10x.h"     
#include "stm32f10x_rcc.h"  
#include "stm32f10x_gpio.h" 
#include "pwm_lib.h"

/* Motor 1 */
#define MOTOR_1			1
#define INA1_PIN		PWM_TIM2_OC2_PIN
#define INB1_PIN	 	PWM_TIM2_OC1_PIN
/* Motor 2 */
#define MOTOR_2			2
#define INA2_PIN 		PWM_TIM2_OC3_PIN
#define INB2_PIN		PWM_TIM2_OC4_PIN
#define MX1508_PORT	GPIOA			
//#define FORWARD				'F'
//#define BACKWARD			'B'

void MX1508_GpioInit(void);
void MX1508_Init(void);
void MX1508_SetLevel(uint8_t motor, uint8_t level);
void MX1508_SetForward(uint8_t motor, uint8_t level);
void MX1508_SetBackward(uint8_t motor, uint8_t level);
void MX1508_SetStopping(uint8_t motor);

#ifdef __cplusplus
}
#endif

#endif



/***********************************************/
