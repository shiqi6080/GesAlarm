#include "alarm.h"                  // Device header

char Is_Alarm_On = 0; // 响铃状态，0 表示未响铃，1 表示响铃
// MyRTC_Time当前日期和时间已经在MyRTC中定义
uint16_t Next_Alarm_Time[] = {8, 30}; // 下一个闹钟时间（小时、分钟）


//函数功能：STM32软复位函数
 void Stm32_SoftReset(void)
 {
   //__set_FAULTMASK(1);//禁止所有的可屏蔽中断
   NVIC_SystemReset();//软件复位
 }


// 设置日期的指令处理函数，格式为：setdateYYYYMMDD
void SetDate(char* cmd) {
    uint16_t year, month, day;
    sscanf(cmd, "%4hu%2hu%2hu", &year, &month, &day);
    MyRTC_Time[0] = year;
    MyRTC_Time[1] = month;
    MyRTC_Time[2] = day;
    Serial_SendString("Date set successfully.\r\n");
}

// 设置时间的指令处理函数，格式为：settimeHHMMSS
void SetTime(char* cmd) {
    uint16_t hour, minute, second;
    sscanf(cmd, "%2hu%2hu%2hu", &hour, &minute, &second);
    MyRTC_Time[3] = hour;
    MyRTC_Time[4] = minute;
    MyRTC_Time[5] = second;
    Serial_SendString("Time set successfully.\r\n");
}

// 设置闹钟时间的指令处理函数，格式为：setalarmHHMM
void SetAlarm(char* cmd) {
    uint16_t hour, minute;
    sscanf(cmd, "%2hu%2hu", &hour, &minute);
    Next_Alarm_Time[0] = hour;
    Next_Alarm_Time[1] = minute;
    Serial_SendString("Alarm time set successfully.\r\n");
}

// 查询闹钟时间的指令处理函数
void QueryAlarm(void) {
    char buffer[50];
    sprintf(buffer, "Next alarm time: %02hu:%02hu\r\n", Next_Alarm_Time[0], Next_Alarm_Time[1]);
    Serial_SendString(buffer);
}

// 立即响铃指令处理函数
void RingNow(void) {
    Next_Alarm_Time[0] = MyRTC_Time[3];
	Next_Alarm_Time[1] = MyRTC_Time[4] + 1;
    Serial_SendString("Alarm is ringing.\r\n");
}

void Skip(void){
	if(Is_Alarm_On==2){
		Is_Alarm_On = 0;
	}
	else{
		Is_Alarm_On = 2;
	}
	Serial_SendString("Motion skipped.\r\n");
}

// 立即停止响铃指令处理函数
void StopRing(void) {
    Is_Alarm_On = 0;
    Serial_SendString("Alarm stopped.\r\n");
}

void Serial_Cmd_Init(){
	MyRTC_Init();		//RTC初始化
	Serial_Init();		//串口初始化
	
	/*开启时钟*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);		//开启PWR的时钟
	printf("cmd done");
	
}

void Order_Receive(){
		if (Serial_RxFlag == 1)		//如果接收到数据包
		{			
				/*将收到的数据包与预设的指令对比，以此决定将要执行的操作*/
				if (strncmp(Serial_RxPacket, "setd", 4) == 0) {  //设置日期
					SetDate(Serial_RxPacket + 7);
					MyRTC_SetTime();
        } 
				else if (strncmp(Serial_RxPacket, "sett", 4) == 0) {  //设置时间
					SetTime(Serial_RxPacket + 7);
					MyRTC_SetTime();
        } 
				else if (strncmp(Serial_RxPacket, "seta", 4) == 0) {  //设置闹钟时间
					SetAlarm(Serial_RxPacket + 8);
        } 
				else if (strcmp(Serial_RxPacket, "queryalarm") == 0) {  //查询闹钟时间
					QueryAlarm();
        } 
				else if (strcmp(Serial_RxPacket, "ring") == 0) {  //立即响铃
					RingNow();
        } 
				else if (strcmp(Serial_RxPacket, "stop") == 0) {  //立即停止响铃
					StopRing();
        } 
				else if (strcmp(Serial_RxPacket, "skip") == 0) {  //跳过当前动作
					Skip();
        } 
				else if(strcmp(Serial_RxPacket, "reset") == 0) {
					Stm32_SoftReset();
		}
				else {						//上述所有条件均不满足，即收到了未知指令
					Serial_SendString("ERROR_COMMAND\r\n");		//串口回传一个字符串ERROR_COMMAND
        }
			
			Serial_RxFlag = 0;			//处理完成后，需要将接收数据包标志位清零，否则将无法接收后续数据包
		}
}
