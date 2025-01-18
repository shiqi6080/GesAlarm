#ifndef __MYRTC_H
#define __MYRTC_H

extern uint16_t MyRTC_Time[];
extern char Is_Alarm_On; // 响铃状态，0 表示未响铃，1 表示响铃
extern uint16_t Next_Alarm_Time[]; // 下一个闹钟时间（小时、分钟）

void MyRTC_Init(void);
void MyRTC_SetTime(void);
void MyRTC_ReadTime(void);

#endif
