#include "timer_lib.h"
#include "hx711_lib.h"
#include "uart_lib.h"
#include "gpio_lib.h"
#include "button_lib.h"
#include "lcd_lib.h"
#include "i2c_lib.h"
#include "message.h"
#include "fsm_array_receive.h"

static uint16_t		get_autocalib_ticks;
static uint32_t		get_print_ticks;
static float			get_new_load_value = 0.0;
static float			get_old_load_value = 0.1;

void Average_Calculation(void);
void Automatic_Calibration(void);
void Main_Print_Weight(void);
void Main_Print_Weight_Lcd(void);
void Main_Print_Weight_Qt(void);

int main(void){
	Gpio_Init();
	Timer4_Base_Init(0x0000,999,71,0,0,ENABLE);
	USART1_Init(9600);
	I2c_Init();
	LCD_Init();

	LCD_Print_On();
	get_autocalib_ticks = Timer4_Millis() +2200;
	get_print_ticks		= Timer4_Millis() + 2300;
	
	while(1){
		Automatic_Calibration();
		if(Fsm_Get_DataReady_Flag()){
			SEC_Process_Message();
			Fsm_Clear_DataReady_Flag();
		}
		if(Timer4_Millis() >= get_print_ticks){
//			get_print_ticks = Timer4_Millis() + 250;
			Main_Print_Weight();
		}
	}
}

void Automatic_Calibration(void){
	/* Auto calib at the startup time, used 1 time only */
	if( (Timer4_Millis() >= get_autocalib_ticks) && (HX711_Get_AutoCalib_Flag() == 1) ){
		HX711_Automatic_Calibration();
		get_old_load_value = 0.1;
		LCD_Clear();
	}
}

/* Print Load Value per 500 ms */
void Main_Print_Weight(void){
	HX711_RangeConvert();
	get_new_load_value = HX711_Get_LoadValue();
	switch(mes_print_state_flag){
		case WEIGTH_CALIB_ANWSER:
			LCD_Weight_Print(get_new_load_value);
			SEC_Message_Create_StructIn(& mes_frame_struct, WEIGTH_CALIB_ANWSER, get_new_load_value, CALIB_ANWSER_TEXT);
			mes_print_state_flag = WEIGTH_ANWSER;
			break;
		case WEIGTH_HOLD_ANWSER:
			LCD_Weight_Print(get_new_load_value);
			SEC_Message_Create_StructIn(& mes_frame_struct, WEIGTH_HOLD_ANWSER, get_new_load_value, HOLD_ANWSER_TEXT);
			mes_print_state_flag = WEIGTH_ANWSER;
			break;
		case WEIGTH_UNHOLD_ANWSER:
			LCD_Weight_Print(get_new_load_value);
			SEC_Message_Create_StructIn(& mes_frame_struct, WEIGTH_UNHOLD_ANWSER, get_new_load_value, UNHOLD_ANWSER_TEXT);
			mes_print_state_flag = WEIGTH_ANWSER;
			break;
		case WEIGTH_ANWSER:
			if((get_new_load_value - get_old_load_value >= 0.001) ||  (get_new_load_value - get_old_load_value <= -0.001) ){
				get_old_load_value = get_new_load_value;
				LCD_Weight_Print(get_new_load_value);
			}
			SEC_Message_Create_StructIn(& mes_frame_struct, WEIGTH_ANWSER, get_new_load_value, WEIGHT_ANWSER_TEXT);
			break;
	}
	uint8_t mes_frame_arrayout_length = SEC_Message_Create_Frame(& mes_frame_struct, mes_frame_arrayout);
	USART1_Send_Series(mes_frame_arrayout, mes_frame_arrayout_length);
}

