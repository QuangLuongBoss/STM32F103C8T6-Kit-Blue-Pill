#include "MX1508_lib.h"

void MX1508_Init(void){
	Pwm_Init();			// 1 kHz 50%
	MX1508_SetForward(MOTOR_1,0);
	MX1508_SetForward(MOTOR_2,0);
}

/* INAx = PWM, INBx = LOW */
void MX1508_SetForward(uint8_t motor, uint8_t level){
	switch(motor){
		case MOTOR_1:
			TIM2->CCR2 = TIM2_PERIOD*level/100;
			TIM2->CCR1 = 0;
			break;
		case MOTOR_2:
			TIM2->CCR3 = TIM2_PERIOD*level/100;
		  TIM2->CCR4 = 0;
			break;
	}								
}

/* INAx = LOW, INBx = PWM */
void MX1508_SetBackward(uint8_t motor, uint8_t level){
	switch(motor){
		case MOTOR_1:
			TIM2->CCR2 = 0;
			TIM2->CCR1 = TIM2_PERIOD*level/100;
			break;
		case MOTOR_2:
			TIM2->CCR3 = 0;
		  TIM2->CCR4 = TIM2_PERIOD*level/100;
			break;
	}	
}

/* INAx = HIGH, INBx = HIGH */
void MX1508_SetStopping(uint8_t motor){
	switch(motor){
		case MOTOR_1:
			TIM2->CCR2 = TIM2_PERIOD;
			TIM2->CCR1 = TIM2_PERIOD;
			break;
		case MOTOR_2:
			TIM2->CCR3 = TIM2_PERIOD;
		  TIM2->CCR4 = TIM2_PERIOD;
			break;
	}	
}

