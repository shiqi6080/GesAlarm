#include "alarm.h"                  // Device header

char Is_Alarm_On = 0; // ����״̬��0 ��ʾδ���壬1 ��ʾ����
// MyRTC_Time��ǰ���ں�ʱ���Ѿ���MyRTC�ж���
uint16_t Next_Alarm_Time[] = {8, 30}; // ��һ������ʱ�䣨Сʱ�����ӣ�


//�������ܣ�STM32��λ����
 void Stm32_SoftReset(void)
 {
   //__set_FAULTMASK(1);//��ֹ���еĿ������ж�
   NVIC_SystemReset();//�����λ
 }


// �������ڵ�ָ���������ʽΪ��setdateYYYYMMDD
void SetDate(char* cmd) {
    uint16_t year, month, day;
    sscanf(cmd, "%4hu%2hu%2hu", &year, &month, &day);
    MyRTC_Time[0] = year;
    MyRTC_Time[1] = month;
    MyRTC_Time[2] = day;
    Serial_SendString("Date set successfully.\r\n");
}

// ����ʱ���ָ���������ʽΪ��settimeHHMMSS
void SetTime(char* cmd) {
    uint16_t hour, minute, second;
    sscanf(cmd, "%2hu%2hu%2hu", &hour, &minute, &second);
    MyRTC_Time[3] = hour;
    MyRTC_Time[4] = minute;
    MyRTC_Time[5] = second;
    Serial_SendString("Time set successfully.\r\n");
}

// ��������ʱ���ָ���������ʽΪ��setalarmHHMM
void SetAlarm(char* cmd) {
    uint16_t hour, minute;
    sscanf(cmd, "%2hu%2hu", &hour, &minute);
    Next_Alarm_Time[0] = hour;
    Next_Alarm_Time[1] = minute;
    Serial_SendString("Alarm time set successfully.\r\n");
}

// ��ѯ����ʱ���ָ�����
void QueryAlarm(void) {
    char buffer[50];
    sprintf(buffer, "Next alarm time: %02hu:%02hu\r\n", Next_Alarm_Time[0], Next_Alarm_Time[1]);
    Serial_SendString(buffer);
}

// ��������ָ�����
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

// ����ֹͣ����ָ�����
void StopRing(void) {
    Is_Alarm_On = 0;
    Serial_SendString("Alarm stopped.\r\n");
}

void Serial_Cmd_Init(){
	MyRTC_Init();		//RTC��ʼ��
	Serial_Init();		//���ڳ�ʼ��
	
	/*����ʱ��*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);		//����PWR��ʱ��
	printf("cmd done");
	
}

void Order_Receive(){
		if (Serial_RxFlag == 1)		//������յ����ݰ�
		{			
				/*���յ������ݰ���Ԥ���ָ��Աȣ��Դ˾�����Ҫִ�еĲ���*/
				if (strncmp(Serial_RxPacket, "setd", 4) == 0) {  //��������
					SetDate(Serial_RxPacket + 7);
					MyRTC_SetTime();
        } 
				else if (strncmp(Serial_RxPacket, "sett", 4) == 0) {  //����ʱ��
					SetTime(Serial_RxPacket + 7);
					MyRTC_SetTime();
        } 
				else if (strncmp(Serial_RxPacket, "seta", 4) == 0) {  //��������ʱ��
					SetAlarm(Serial_RxPacket + 8);
        } 
				else if (strcmp(Serial_RxPacket, "queryalarm") == 0) {  //��ѯ����ʱ��
					QueryAlarm();
        } 
				else if (strcmp(Serial_RxPacket, "ring") == 0) {  //��������
					RingNow();
        } 
				else if (strcmp(Serial_RxPacket, "stop") == 0) {  //����ֹͣ����
					StopRing();
        } 
				else if (strcmp(Serial_RxPacket, "skip") == 0) {  //������ǰ����
					Skip();
        } 
				else if(strcmp(Serial_RxPacket, "reset") == 0) {
					Stm32_SoftReset();
		}
				else {						//�������������������㣬���յ���δָ֪��
					Serial_SendString("ERROR_COMMAND\r\n");		//���ڻش�һ���ַ���ERROR_COMMAND
        }
			
			Serial_RxFlag = 0;			//������ɺ���Ҫ���������ݰ���־λ���㣬�����޷����պ������ݰ�
		}
}
