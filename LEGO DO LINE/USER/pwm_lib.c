#include "pwm_lib.h"
#include "led_scan_module_lib.h"

volatile uint32_t timer2_ticks = 0;

void Pwm_Init(void){	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_TypeDefStructure;
	NVIC_InitTypeDef nvic_init_tydef;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		
	
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST, ENABLE);
//	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);
	
	GPIO_TypeDefStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_TypeDefStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_TypeDefStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_TypeDefStructure);		
	
	/* Basic Timer Init */
	// Period + 1 = T.F_sys / [(PSC+1)(RCR+1)]
	// 1/T = F_sys / [(PSC+1)(RCR+1)(Period+1)]
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_TimeBaseInitStructure.TIM_Prescaler = TIM2_PRESCALER;
	TIM_TimeBaseInitStructure.TIM_Period = TIM2_PERIOD;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = TIM2_REPETITION;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	nvic_init_tydef.NVIC_IRQChannel = TIM2_IRQn;
	nvic_init_tydef.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_init_tydef.NVIC_IRQChannelSubPriority = 0;
	nvic_init_tydef.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init_tydef);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
//	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
	TIM_OCInitStructure.TIM_Pulse = TIM2_PWM_PULSE;
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	TIM_Cmd(TIM2, ENABLE);
	
	TIM_CtrlPWMOutputs(TIM2, ENABLE);	
}

void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)	!= RESET){
		timer2_ticks++;
		LedScanModule_Read();
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
}

void Delay_Ms(uint32_t t){
	uint32_t start = timer2_ticks;
  uint32_t end = start +  t;
	if (start < end){ 
  	while((timer2_ticks >= start) && (timer2_ticks < end));
  }
	else{ 
    while((timer2_ticks >= start) || (timer2_ticks < end));
  }
}

