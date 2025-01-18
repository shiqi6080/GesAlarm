#include "config.h"                  // Device header
#include "MyRTC.h"
#include "Serial.h"

extern char Is_Alarm_On; // 响铃状态，0 表示未响铃，1 表示响铃
// MyRTC_Time当前日期和时间已经在MyRTC中定义
extern uint16_t Next_Alarm_Time[]; // 下一个闹钟时间（小时、分钟）
extern uint16_t MyRTC_Time[];

void Serial_Cmd_Init();
void Order_Receive();