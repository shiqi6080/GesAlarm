#ifndef __MYRTC_H
#define __MYRTC_H

extern uint16_t MyRTC_Time[];
extern char Is_Alarm_On; // ����״̬��0 ��ʾδ���壬1 ��ʾ����
extern uint16_t Next_Alarm_Time[]; // ��һ������ʱ�䣨Сʱ�����ӣ�

void MyRTC_Init(void);
void MyRTC_SetTime(void);
void MyRTC_ReadTime(void);

#endif
