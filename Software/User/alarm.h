#include "config.h"                  // Device header
#include "MyRTC.h"
#include "Serial.h"

extern char Is_Alarm_On; // ����״̬��0 ��ʾδ���壬1 ��ʾ����
// MyRTC_Time��ǰ���ں�ʱ���Ѿ���MyRTC�ж���
extern uint16_t Next_Alarm_Time[]; // ��һ������ʱ�䣨Сʱ�����ӣ�
extern uint16_t MyRTC_Time[];

void Serial_Cmd_Init();
void Order_Receive();