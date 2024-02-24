#include "uart_lib.h"
#include "L298N_lib.h"
#include "led_scan_module_lib.h"

void Delay(uint32_t t){
	uint32_t i, j;
	for(i=0 ; i<t ; i++){
		for(j=0 ; j<7999 ; j++);
	}
}

int main(void){
	
	LedScanModule_Init();

	while(1){
		LedScanModule_Read();
	}
}

//	L298N_Init();
//	L298N_SetLevel(MOTOR_A,50);
//	L298N_SetLevel(MOTOR_B,50);

