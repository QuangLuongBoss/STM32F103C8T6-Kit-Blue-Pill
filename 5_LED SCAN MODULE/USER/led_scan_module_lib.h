/*
	**********************************************
	*@file				led_scan_module_lib.h	*
	*@author			Vu Quang Luong				*
	*@date				24/02/2024						*
	**********************************************
*/

#ifndef	__LED_SCAN_MODULE__
#define	__LED_SCAN_MODULE__

#ifdef __cplusplus
	extern "C"{
#endif

#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_gpio.h"

#define LEDSCAN_PORT				GPIOA
#define LEDSCAN_PIN_OUT1		GPIO_Pin_1
#define LEDSCAN_PIN_OUT2		GPIO_Pin_2
#define LEDSCAN_PIN_OUT3		GPIO_Pin_3
#define LEDSCAN_PIN_OUT4		GPIO_Pin_4
#define LEDSCAN_PIN_OUT5		GPIO_Pin_5
#define LEDSCAN_OUT1				0x01
#define LEDSCAN_OUT2				0x02
#define LEDSCAN_OUT3				0x04
#define LEDSCAN_OUT4				0x08
#define LEDSCAN_OUT5				0x10
#define LEDSCAN_OUT_ALL			0x001F

void LedScanModule_Init(void);
void LedScanModule_Read(void);
uint8_t LedScanModule_GetState(uint8_t led_outx);

#ifdef __cplusplus
}
#endif

#endif



/***********************************************/
