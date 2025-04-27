#ifndef __AFUNCTION_H__
#define __AFUNCTION_H__

#include "Status.h"
#include <stdint.h>
#include "dataStruct.h"
#include "i2c.h"
#include "lcd.h"
#include "touch.h"
#include "RC522.h"
#include <stdio.h>
#include <string.h>
#include "delay.h"
#include "DS3231.h"
#include <stdbool.h>
#include "at24cxx.h"
#include "main.h"
#include "adc.h"

extern Status status;

#define CARDEVENT 1
#define TOUCHEVENT 2

#define DEBUG

// 时间格式
typedef struct Time
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} Time;

// 打卡记录
typedef struct signinIndex
{
    uint8_t number[12]; // 学号
    uint32_t startTime; // 开始时间
    uint32_t endTime;   // 结束时间
} signinIndex;

// 触摸事件
typedef struct TouchEvent
{
    uint16_t x;
    uint16_t y;
    uint8_t status;
} TouchEvent;

// 卡事件
typedef struct CardEvent
{
    uint8_t number[12]; // 学号
    uint32_t time;      // 时间
    uint8_t status;     // 状态
} CardEvent;

// 总事件
typedef struct Event
{
    TouchEvent touchEvent;
    CardEvent cardEvent;
    uint8_t type;
} TotalEvent;

// 事件队列
typedef struct EventQueue
{
    TotalEvent event[10]; // 事件数组
    uint8_t head;         // 队列头
    uint8_t tail;         // 队列尾
    uint8_t size;         // 队列大小
} EventQueue;

extern EventQueue eventQueue;

extern uint8_t photostatus;

extern Time nowTime;

void pushEvent(TotalEvent event); // 添加事件
bool popEvent(TotalEvent *event); // 弹出事件

int16_t calculate_weekday(int16_t year, int16_t month, int16_t day); // 计算星期几
void ds3231Init(void);                                               // DS3231上电检查

void RC522Scan(void);                    // RC522读卡
void RC522WriteCard(uint8_t *Card_Data); // RC522写卡

void at24Init(void); // AT24初始化

void LD2410BInit(void); // LD2410B初始化

void setTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute); // 设置ds3231时间
void updateTime(void);                                                                 // 更新系统时间

void handleEvent(void); // 处理事件

void ChangeTime(void); // 时间修改面板

// 导出数据到SD卡
uint8_t exportData(void);

void totalInit(void); // 系统初始化

void loop(void); // 一帧

bool writeUserInfo(UserInfo *userInfo); // 写入用户信息
bool readUserInfo(UserInfo *userInfo);  // 读取用户信息



#endif