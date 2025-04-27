#ifndef __EVENTHANDLER_H_
#define __EVENTHANDLER_H_

#include "gui_guider.h"
#include "lv_types.h"

// 新增人员面板
void userInfoPanel_ImportFromSDcard_event_handler(lv_event_t *e); // 从SD卡导入
void newUserInfoPanel_ConfirmButton_event_handler(lv_event_t *e); // 确认添加新用户

// 修改时间面板
void changeTimePanel_ConfirmButton_event_handler(lv_event_t *e);  // 确认修改时间
void changeTimePanel_HourUpButton_event_handler(lv_event_t *e);   // 时加
void changeTimePanel_HourDownButton_event_handler(lv_event_t *e); // 时减
void changeTimePanel_MinUpButton_event_handler(lv_event_t *e);    // 分加
void changeTimePanel_MinDownButton_event_handler(lv_event_t *e);  // 分减
void MainMenuScreen_Clock_event_handler(lv_event_t *e);           // 跳转到修改时间面板

// 更新时间
void MainMenuScreen_digital_clock_1_timer(lv_timer_t *timer);

// 打卡记录面板
void CheckInfoPanel_ExportButton_event_handler(lv_event_t *e); // 导出打卡记录

void myEventInit(lv_ui *ui); // 绑定事件

void myLVGL_UIInit(void); // LVGL UI自定义部分初始化

#endif