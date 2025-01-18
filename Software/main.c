#include "GesAlarm.h"
#include "weights.h"
#include "nnom.h"
#include "alarm.h"


extern Ges_Alarm_Status_Typedef Ges_Alarm_Status;
extern float IMU_Data_mAngle[IMU_SEQUENCE_LENGTH_MAX][3];
extern float IMU_Data_mAcc[IMU_SEQUENCE_LENGTH_MAX][3];
int8_t model_output = -1;
uint8_t screenflag = 1;
#define SCALE (pow(2,INPUT_1_OUTPUT_DEC))

#ifdef NNOM_USING_STATIC_MEMORY
	uint8_t static_buf[1024 * 8];
#endif //NNOM_USING_STATIC_MEMORY

void model_feed_data(void)
{
	const double scale = SCALE;
	uint16_t i = 0;
	for(i = 0; i < IMU_SEQUENCE_LENGTH_MAX;i++){
		nnom_input_data[i*3] = (int8_t)round(IMU_Data_mAcc[i][0] * scale);
		nnom_input_data[i*3+1] = (int8_t)round(IMU_Data_mAcc[i][1] * scale);
		nnom_input_data[i*3+2] = (int8_t)round(IMU_Data_mAcc[i][2] * scale);
	}
}

int8_t model_get_output(void)
{
	uint8_t i = 0;
	int8_t max_output = -128;
	int8_t ret = 0;
	for(i = 0; i < 5;i++){
		printf("Output[%d] = %.2f %%\n",i,(nnom_output_data[i] / 127.0)*100);
		if(nnom_output_data[i] >= max_output){
			max_output = nnom_output_data[i] ;
			ret = i;
		}
	}
	if(max_output >= OUPUT_THRESHOLD){
		ret = ret;
	}
	else{
		ret = -1;
	}
	printf("\n");
	return ret;
}




void motion_check(nnom_model_t* model){
	int8_t motion = MyRTC_Time[4]%5;
	Delay_ms(50);
	OLED_Show(motion+2);
	while(Is_Alarm_On==1){
		if(Ges_Alarm_Status.Button_Status == BUTTON_HOLD && Ges_Alarm_Status.IMU_Status == IMU_Idle){
			IMU_Sample_Start();	 
			//printf("HOLD\n");
			GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_SET);
		}
		else if(Ges_Alarm_Status.Button_Status != BUTTON_IDLE){
			Ges_Alarm_Status.Button_Status = BUTTON_IDLE;
		}

		if(Ges_Alarm_Status.IMU_Status == IMU_Sampled){
			#ifdef SYSTEM_MODE_DATA_COLLECT
			Delay_ms(200);
			IMU_Data_Print();
			Ges_Alarm_Status.IMU_Status = IMU_Idle;
			return;
			#endif //SYSTEM_MODE_DATA_COLLECT
			
			#ifndef SYSTEM_MODE_DATA_COLLECT
			model_feed_data();
			model_run(model);
			model_output = model_get_output();
			printf("%d",model_output);
			//Model_LED(model_output);
			#endif //SYSTEM_MODE_DATA_COLLECT
			Ges_Alarm_Status.IMU_Status = IMU_Idle;
			EXTI_Restore();
		}
		if(Ges_Alarm_Status.IMU_Status == IMU_Idle){
			if(model_output == motion){
				Is_Alarm_On = 2;
			}
			else{
				GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_RESET);
			}
		}
	}
	OLED_Clear();
	MyRTC_ReadTime();
	int8_t motion1 = MyRTC_Time[5]%5;
	if (motion == motion1){
		motion = (motion+1)%5;
	}
	else{
		motion = motion1;
	}
	Delay_ms(50);
	OLED_Show(motion+2);
	model_output = -1;
	while(Is_Alarm_On==2){
		if(Ges_Alarm_Status.Button_Status == BUTTON_HOLD && Ges_Alarm_Status.IMU_Status == IMU_Idle){
			IMU_Sample_Start();	 
			printf("HOLD\n");
			GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_SET);
		}
		else if(Ges_Alarm_Status.Button_Status != BUTTON_IDLE){
			Ges_Alarm_Status.Button_Status = BUTTON_IDLE;
		}

		if(Ges_Alarm_Status.IMU_Status == IMU_Sampled){
			#ifdef SYSTEM_MODE_DATA_COLLECT
			Delay_ms(200);
			IMU_Data_Print();
			#endif //SYSTEM_MODE_DATA_COLLECT
			
			#ifndef SYSTEM_MODE_DATA_COLLECT
			model_feed_data();
			model_run(model);
			model_output = model_get_output();
			printf("%d",model_output);
			//Model_LED(model_output);
			#endif //SYSTEM_MODE_DATA_COLLECT
			Ges_Alarm_Status.IMU_Status = IMU_Idle;
			EXTI_Restore();
		}
		if(Ges_Alarm_Status.IMU_Status == IMU_Idle){
			if(model_output == motion){
				Is_Alarm_On = 0;
			}
			else{
				GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_RESET);
			}
		}
	}
	OLED_Clear();
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_SET);
	Delay_ms(50);
	OLED_Show(7);
	Delay_s(2);
	OLED_Clear();
	screenflag = 0;
	model_output = -1;
}

int  main(void)
{       
    System_Init();
	Serial_Cmd_Init();
    printf("Hello!\n");
    GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_SET);
	#ifdef NNOM_USING_STATIC_MEMORY
		nnom_set_static_buf(static_buf, sizeof(static_buf)); 
	#endif //NNOM_USING_STATIC_MEMORY
	nnom_model_t* model;
	model = nnom_model_create(); 
	
	while(1){
		MyRTC_ReadTime();
		if (MyRTC_Time[3] == Next_Alarm_Time[0] && MyRTC_Time[4] == Next_Alarm_Time[1] && MyRTC_Time[5] == 0){
			Is_Alarm_On = 1;
		}
		
		#ifdef SYSTEM_MODE_DATA_COLLECT
		if(Ges_Alarm_Status.Button_Status == BUTTON_HOLD && Ges_Alarm_Status.IMU_Status == IMU_Idle){
			IMU_Sample_Start();
			GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_SET);
		}
		else if(Ges_Alarm_Status.Button_Status != BUTTON_IDLE){
			Ges_Alarm_Status.Button_Status = BUTTON_IDLE;
		}
		if(Ges_Alarm_Status.IMU_Status == IMU_Sampled){
			Delay_ms(200);
			IMU_Data_Print();
			Ges_Alarm_Status.IMU_Status = IMU_Idle;
			EXTI_Restore();
		}
		#endif //SYSTEM_MODE_DATA_COLLECT
		#ifndef SYSTEM_MODE_DATA_COLLECT
		if(Is_Alarm_On == 1){
			OLED_Clear();
			GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_RESET);
			motion_check(model);
		}
		#endif //SYSTEM_MODE_DATA_COLLECT
		
		if(Ges_Alarm_Status.Button_Status == BUTTON_HOLD){
			screenflag = 60;
			Ges_Alarm_Status.Button_Status = BUTTON_IDLE;
		}
		else if(Ges_Alarm_Status.Button_Status != BUTTON_IDLE){
			Ges_Alarm_Status.Button_Status = BUTTON_IDLE;
		}
		if(screenflag){
			OLED_Show(1);
			screenflag--;
		}
		else{
			OLED_Clear();
		}

		Delay_ms(500);
	}
}

