#include "led_scan_module_lib.h"

void Delay(uint32_t t){
	uint32_t i, j;
	for(i=0 ; i<t ; i++){
		for(j=0 ; j<7999 ; j++);
	}
}

uint8_t state_all = 0;
uint8_t state_out1 = 0;
uint8_t state_out2 = 0;
uint8_t state_out3 = 0;
uint8_t state_out4 = 0;
uint8_t state_out5 = 0;

int main(void){
	
	LedScanModule_Init();

	while(1){
		LedScanModule_Read();
		state_all = LedScanModule_GetState(LEDSCAN_OUT_ALL);
		state_out1 = LedScanModule_GetState(LEDSCAN_OUT1);
		state_out2 = LedScanModule_GetState(LEDSCAN_OUT2);
		state_out3 = LedScanModule_GetState(LEDSCAN_OUT3);
		state_out4 = LedScanModule_GetState(LEDSCAN_OUT4);
		state_out5 = LedScanModule_GetState(LEDSCAN_OUT5);
		Delay(1);
		
	}
}

