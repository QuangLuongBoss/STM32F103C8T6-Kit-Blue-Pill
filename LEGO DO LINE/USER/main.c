#include "MX1508_lib.h"
#include "led_scan_module_lib.h"

uint8_t state1 = 0;
uint8_t state2 = 0;
uint8_t state3 = 0;
uint8_t state4 = 0;
uint8_t state5 = 0;

int main(void){
	LedScanModule_Init();
	MX1508_Init();
	MX1508_SetForward(MOTOR_1,50);
	MX1508_SetForward(MOTOR_2,50);
	while(1){
		state1 = LedScanModule_GetState(LEDSCAN_OUT1);
		state2 = LedScanModule_GetState(LEDSCAN_OUT2);
		state3 = LedScanModule_GetState(LEDSCAN_OUT3);
		state4 = LedScanModule_GetState(LEDSCAN_OUT4);
		state5 = LedScanModule_GetState(LEDSCAN_OUT5);
		Delay_Ms(500);
	}
}


