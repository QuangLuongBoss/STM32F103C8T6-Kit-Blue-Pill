#include "uart_lib.h"
#include "lego_motor_43362.h"
#include "L298N_lib.h"

void Delay(uint32_t t){
	uint32_t i, j;
	for(i=0 ; i<t ; i++){
		for(j=0 ; j<7999 ; j++);
	}
}

int main(void){
	L298N_Init();
	Delay(1000);
	
	L298N_SetLevel(MOTOR_A,20);
	Delay(2000);
	L298N_SetLevel(MOTOR_A,0);
	L298N_SetBackward(MOTOR_A);
	L298N_SetLevel(MOTOR_A,20);
	L298N_SetLevel(MOTOR_B,60);
	while(1){

	}
}



