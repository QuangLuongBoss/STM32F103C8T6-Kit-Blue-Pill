#include "led_scan_module_lib.h"

const uint8_t shift = 4;
const uint16_t outstate_mask = 0x001F;
static uint16_t out_state = 0;
static uint8_t  outx_sate;

void LedScanModule_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef ledscan_gpio;
	ledscan_gpio.GPIO_Mode = GPIO_Mode_IPU;
	ledscan_gpio.GPIO_Speed = GPIO_Speed_50MHz;
	ledscan_gpio.GPIO_Pin = LEDSCAN_PIN_OUT1 | LEDSCAN_PIN_OUT2 | LEDSCAN_PIN_OUT3 | LEDSCAN_PIN_OUT4 | LEDSCAN_PIN_OUT5;
	GPIO_Init(LEDSCAN_PORT, &ledscan_gpio);
}

void LedScanModule_Read(void){
	out_state = ((GPIO_ReadInputData(LEDSCAN_PORT) >> shift) & outstate_mask);
}


uint8_t LedScanModule_GetState(uint8_t led_outx){
	
	switch(led_outx){
		case LEDSCAN_OUT1:
			outx_sate = (uint8_t)(out_state & LEDSCAN_OUT1)>>3;
			break;
		case LEDSCAN_OUT2:
			outx_sate = (uint8_t)(out_state & LEDSCAN_OUT2)>>2;
			break;
		case LEDSCAN_OUT3:
			outx_sate = (uint8_t)(out_state & LEDSCAN_OUT3)>>1;
			break;
		case LEDSCAN_OUT4:
			outx_sate = (uint8_t)(out_state & LEDSCAN_OUT4);
			break;
		case LEDSCAN_OUT5:
			outx_sate = (uint8_t)(out_state & LEDSCAN_OUT5)>>4;
			break;
		case LEDSCAN_OUT_ALL:
			outx_sate = out_state;
			break;
	}
	return outx_sate;
}





