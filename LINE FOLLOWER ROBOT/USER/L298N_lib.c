#include "L298N_lib.h"

GPIO_InitTypeDef l298n_gpio;

/* Brief
	Mac dinh khoi tao la Set Forward level 0 cho ca 2 motor: IN2 = 0, IN1 = PWM, IN4 = 0, IN3 = PWM.
*/                                        
void L298N_GpioInit(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	/* IN1 & IN3 */
	l298n_gpio.GPIO_Speed = GPIO_Speed_50MHz;
	l298n_gpio.GPIO_Pin = IN1_PIN | IN3_PIN;
	l298n_gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(L298N_PORT,&l298n_gpio);
	
	/* IN2 & IN4 */
	l298n_gpio.GPIO_Pin = IN2_PIN | IN4_PIN;
	l298n_gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(L298N_PORT,&l298n_gpio);
	GPIO_ResetBits(L298N_PORT,IN2_PIN|IN4_PIN);
}

void L298N_Init(void){
	Pwm_Init(PWM_TIM4_ALL,0,TIM4_PERIOD,TIM4_PRESCALE);
	L298N_GpioInit();
}

// IN2 = 0, IN1 = PWM
// IN4 = 0, IN3 = PWM
void L298N_SetForward(char motor){
	switch(motor){
		case 'A':
			l298n_gpio.GPIO_Mode = GPIO_Mode_Out_PP;
			l298n_gpio.GPIO_Pin = IN2_PIN;
			GPIO_Init(L298N_PORT,&l298n_gpio);
			GPIO_ResetBits(L298N_PORT, IN2_PIN);
			l298n_gpio.GPIO_Pin = IN1_PIN;
			l298n_gpio.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_Init(L298N_PORT,&l298n_gpio);
			break;
		case 'B':
			l298n_gpio.GPIO_Mode = GPIO_Mode_Out_PP;
			l298n_gpio.GPIO_Pin = IN4_PIN;
			GPIO_Init(L298N_PORT,&l298n_gpio);
			GPIO_ResetBits(L298N_PORT, IN4_PIN);
			l298n_gpio.GPIO_Pin = IN3_PIN;
			l298n_gpio.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_Init(L298N_PORT,&l298n_gpio);
			break;
	}								
}

// Backward = ! Forward
void L298N_SetBackward(char motor){
	switch(motor){
		case 'A':
			l298n_gpio.GPIO_Mode = GPIO_Mode_Out_PP;
			l298n_gpio.GPIO_Pin = IN1_PIN;
			GPIO_Init(L298N_PORT,&l298n_gpio);
			GPIO_ResetBits(L298N_PORT, IN1_PIN);
			l298n_gpio.GPIO_Pin = IN2_PIN;
			l298n_gpio.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_Init(L298N_PORT,&l298n_gpio);
			break;
		case 'B':
			l298n_gpio.GPIO_Mode = GPIO_Mode_Out_PP;
			l298n_gpio.GPIO_Pin = IN3_PIN;
			GPIO_Init(L298N_PORT,&l298n_gpio);
			GPIO_ResetBits(L298N_PORT, IN3_PIN);
			l298n_gpio.GPIO_Pin = IN4_PIN;
			l298n_gpio.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_Init(L298N_PORT,&l298n_gpio);
			break;
	}	
}

void L298N_SetLevel(char motor, uint8_t level){
	switch(motor){
		case 'A':
			Timer_OCx_SetPulse(TIM4,OC3,(uint16_t)TIM4_PERIOD*level/100);
			Timer_OCx_SetPulse(TIM4,OC4,(uint16_t)TIM4_PERIOD*level/100);
			break;
		case 'B':
			Timer_OCx_SetPulse(TIM4,OC1,(uint16_t)TIM4_PERIOD*level/100);
			Timer_OCx_SetPulse(TIM4,OC2,(uint16_t)TIM4_PERIOD*level/100);
			break;
	}	
}
