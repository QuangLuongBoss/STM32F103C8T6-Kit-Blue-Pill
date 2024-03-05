#include "gpio_lib.h"

void Gpio_Init(void){
	GPIO_InitTypeDef gpio;
	
	/* Enable Peripheral Clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	/* HX711 DOUT */
	gpio.GPIO_Pin   = HX711_DT;								
	gpio.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HX711_PORT,&gpio);
	
	/* HX711 SCK */
	gpio.GPIO_Pin  = HX711_SCK;								
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HX711_PORT,&gpio);
	GPIO_ResetBits(HX711_PORT,HX711_SCK);
	
	/* UART1 TX */
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio.GPIO_Pin = USART1_TX;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART1_PORT,&gpio);
	
	/* UART1 RX */
	gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;									
	gpio.GPIO_Pin = USART1_RX;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART1_PORT,&gpio);
	
	/* Calib Button & Hold Button	*/
	gpio.GPIO_Pin  = CALIB_BUTTON | HOLD_BUTTON;								
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BUTTON_PORT,&gpio);
	
	/* SDA and SCL from I2C2 */ 
	gpio.GPIO_Pin = LCD_DATA | LCD_SCK;			// PB10 - SCL   PB11 - SDA
	gpio.GPIO_Mode = GPIO_Mode_AF_OD;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_PORT, &gpio);
	
	gpio.GPIO_Pin = LED_PC13;							// PC13
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_PORT, &gpio);
	GPIO_ResetBits(LED_PC13_PORT, LED_PC13);
}
