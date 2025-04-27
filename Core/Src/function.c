#include "function.h"
#include "lcd.h"
#include "RC522/RC522.h"
#include "Status.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>

#define MAX_CHECK_RECORDS 10

Status status       = {0};
Time nowTime        = {0};
uint8_t photostatus = 0;

void pushEvent(TotalEvent event)
{
    if (eventQueue.size >= 10) {
        popEvent(NULL); // 队列满，弹出最早的事件
    }
    eventQueue.event[eventQueue.tail] = event;
    eventQueue.tail                   = (eventQueue.tail + 1) % 10;
    eventQueue.size++;
}

bool popEvent(TotalEvent *event)
{
    if (eventQueue.size > 0) {
        if (event != NULL) {
            *event          = eventQueue.event[eventQueue.head];
            eventQueue.head = (eventQueue.head + 1) % 10;
        } else {
            eventQueue.head = (eventQueue.head + 1) % 10;
        }
        eventQueue.size--;
        return true;
    } else {
        return false; // 队列为空
    }
}

// 计算星期
int16_t calculate_weekday(int16_t year, int16_t month, int16_t day)
{
    // 调整月份和年份（1月和2月视为上一年的13月和14月）
    if (month < 3) {
        month += 12;
        year--;
    }
    int16_t q = day;
    int16_t m = month;
    int16_t K = year % 100; // 年份后两位
    int16_t J = year / 100; // 世纪部分

    // 蔡勒公式计算星期几（0=星期六, 1=星期日, ..., 6=星期五）
    int16_t h = (q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    // 转换为0=星期日到6=星期六
    h = (h + 6) % 7;
    return h;
}

// DS3231上电检查
void ds3231Init(void)
{
    DS3231_Init(&hi2c2);
    uint16_t year  = DS3231_GetYear();
    uint8_t month  = DS3231_GetMonth();
    uint8_t day    = DS3231_GetDate();
    uint8_t hour   = DS3231_GetHour();
    uint8_t minute = DS3231_GetMinute();
    uint8_t second = DS3231_GetSecond();
    if (year == 2000 && month == 1 && day == 1 && hour == 0 && minute == 0 && second == 0) {
        status.mode = DS3231RESET; // 掉电重启
    } else                         // 正常启动
    {
        status.mode    = OK;
        nowTime.year   = year;
        nowTime.month  = month;
        nowTime.day    = day;
        nowTime.hour   = hour;
        nowTime.minute = minute;
        nowTime.second = second;
    }
}




//rc
extern CheckInfo checkRecords[MAX_CHECK_RECORDS] = {0}; // 全局打卡记录数组
extern int checkRecordCount = 0;                        // 记录计数器


// 根据学号查找打卡记录索引（-1表示未找到）
int find_student_record(uint64_t studentID) {
    for (int i = 0; i < checkRecordCount; i++) {
        if (checkRecords[i].ID == studentID && checkRecords[i].endTime == 0) {
            return i; // 找到未结束的打卡记录
        }
    }
    return -1; // 未找到或记录已结束
}



//


// RC522扫描卡
void RC522Scan(void)
{
    uint8_t Card_Type1[2];
    uint8_t Card_ID[4];
    uint8_t Card_KEY[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; //{0x11,0x11,0x11,0x11,0x11,0x11};   //密码
    uint8_t Card_Data[16];
    uint8_t status;


    uint64_t currentTime = get_current_time(); // 获取当前时间
    uint64_t studentID = 0; // 存储解析后的学号（假设为4字节卡号或从卡片读取的学号）

    if (PcdRequest(0x26, Card_Type1) == MI_OK) // 寻卡
    {
        status = PcdAnticoll(Card_ID); // 防冲撞

        if (status == MI_OK) {
#ifdef DEBUG
            printf("Serial Number:%02X%02X%02X%02X\r\n", Card_ID[0], Card_ID[1], Card_ID[2], Card_ID[3]); // 打印卡号
#endif
        } else {
#ifdef DEBUG
            printf("Anticoll Error\r\n");
#endif
            return;
        }

        status = PcdSelect(Card_ID); // 选卡

        if (status != MI_OK) {
#ifdef DEBUG
            printf("Select Card Error\r\n");
#endif
            return;
        }

        status = PcdAuthState(PICC_AUTHENT1A, 5, Card_KEY, Card_ID); // 验证密码
        if (status != MI_OK) {
#ifdef DEBUG
            printf("Auth Error\r\n");
#endif
            return;
        }
        status = PcdRead(6, Card_Data); // 读数据
        if (status != MI_OK) {
#ifdef DEBUG
            printf("Read Error\r\n");
#endif
            return;
        } else {
            // TODO:处理学号以及校验码

            // 解析学号（这里假设学号为前4字节数据）
            studentID = ((uint64_t)Card_Data[0] << 24) |
                ((uint64_t)Card_Data[1] << 16) |
                ((uint64_t)Card_Data[2] << 8) |
                Card_Data[3];

                int recordIndex = find_student_record(studentID);
                if (recordIndex != -1) {
                    // 存在未结束的打卡记录，标记为结束时间
                    checkRecords[recordIndex].endTime = currentTime;

                    //数据存储进EEPROM里
                    


                    

        #ifdef DEBUG
                    printf("Student %llu End Time: %llu\r\n", (unsigned long long)studentID, currentTime);
        #endif
                } else {
                    // 无未结束记录，创建新的开始记录
                    if (checkRecordCount < MAX_CHECK_RECORDS) {
                        checkRecords[checkRecordCount].ID = studentID;
                        checkRecords[checkRecordCount].startTime = currentTime;
                        checkRecords[checkRecordCount].endTime = 0;
                        checkRecordCount++;

                        //数据存储进EEPROM里





        #ifdef DEBUG
                        printf("Student %llu Start Time: %llu\r\n", (unsigned long long)studentID, currentTime);
        #endif
                    } else {
        #ifdef DEBUG
                        printf("Max Record Reached!\r\n");
        #endif
                    }
                }


        }
        status = PcdHalt(); // 停止卡片
        return;
    } else {
#ifdef DEBUG
        printf("No Card\r\n");
#endif
        return;
    }
}

// RC522写卡
void RC522WriteCard(uint8_t *Card_Data)
{
    uint8_t Card_Type1[2];
    uint8_t Card_ID[4];
    uint8_t Card_KEY[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; //{0x11,0x11,0x11,0x11,0x11,0x11};   //密码
    uint8_t status;
    if (PcdRequest(0x26, Card_Type1) == MI_OK) // 寻卡
    {
        status = PcdAnticoll(Card_ID); // 防冲撞

        if (status == MI_OK) {
#ifdef DEBUG
            printf("Serial Number:%02X%02X%02X%02X\r\n", Card_ID[0], Card_ID[1], Card_ID[2], Card_ID[3]); // 打印卡号
#endif
        } else {
#ifdef DEBUG
            printf("Anticoll Error\r\n");
#endif
            return;
        }

        status = PcdSelect(Card_ID); // 选卡

        if (status != MI_OK) {
#ifdef DEBUG
            printf("Select Card Error\r\n");
#endif
            return;
        }

        status = PcdAuthState(PICC_AUTHENT1A, 5, Card_KEY, Card_ID); // 验证密码
        if (status != MI_OK) {
#ifdef DEBUG
            printf("Auth Error\r\n");
#endif
            return;
        }
        status = PcdWrite(6, Card_Data); // 写数据
        if (status != MI_OK) {
#ifdef DEBUG
            printf("Write Error\r\n");
#endif
            return;
        } else {
#ifdef DEBUG
            printf("Write Success\r\n");
#endif
        }
        status = PcdHalt(); // 停止卡片
        return;
    } else {
#ifdef DEBUG
        printf("No Card\r\n");
#endif
        return;
    }
}





// AT24初始化
void at24Init(void)
{
    if (at24_isConnected()) {
        // TODO:读取人员信息以及打卡信息
    } else {
        status.mode = AT24ERROR;
    }
    return;
}

void LD2410BInit(void)
{
    // TODO:LD2410初始化
}

// 更新系统时间
void updateTime(void)
{
    nowTime.second = DS3231_GetSecond();
    nowTime.minute = DS3231_GetMinute();
    nowTime.hour   = DS3231_GetHour();
    nowTime.day    = DS3231_GetDate();
    nowTime.month  = DS3231_GetMonth();
    nowTime.year   = DS3231_GetYear();
}

// 设置DS3231时间
void setTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute)
{
    int16_t weekday = calculate_weekday(year, month, day);
    DS3231_SetFullDate(day, month, weekday, year);

    DS3231_SetFullTime(hour, minute, 0);
}

void Float2Str(char *str, float value)
{
    int Head  = (int)value;
    int Point = (int)((value - Head) * 10.0);
    sprintf(str, "voltage:%d.%dv", Head, Point);
}


void handleEvent(void)
{
    TotalEvent event;
    if (popEvent(&event)) {
        if (event.type == TOUCHEVENT) // 触摸事件
        {
            if (status.mode == NORMALMOD) // 主界面
            {
                if (event.touchEvent.x >= 330 && event.touchEvent.y >= 20 && event.touchEvent.x <= 387 && event.touchEvent.y <= 60) {
                    status.mode = EXPORTMODE; // 进入导出界面
                    // exportData();
                } else if (event.touchEvent.x >= 0 && event.touchEvent.y >= 0 && event.touchEvent.x <= 50 && event.touchEvent.y <= 60) {
                    status.mode = TIMECHANGEMODE; // 进入修改时间界面
                    // 按下时间部分进入到修改时间的界面
                    ChangeTime();
                }
            } else if (status.mode == TIMECHANGEMODE) // 修改时间界面
            {
                // TODO:处理修改时间事件
            } else if (status.mode == EXPORTMODE) // 导出界面
            {
                // TODO:处理导出事件
            }
#ifdef DEBUG
            printf("touch: %d %d\r\n", event.touchEvent.x, event.touchEvent.y);
#endif
        } else {
            // TODO:处理刷卡事件
        }
    }
}

// RC522测试函数
void RC522Test()
{
    uint8_t Card_Type1[2];
    uint8_t Card_ID[4];
    uint8_t Card_KEY[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; //{0x11,0x11,0x11,0x11,0x11,0x11};   //密码
    uint8_t Card_Data[16];
    uint8_t status;
    uint8_t i;
    Card_Type1[0] = 0x04;
    Card_Type1[1] = 0x00;
    RC522_Init();
    printf("---------------------------------------\r\n");
    HAL_Delay(10);
    if (MI_OK == PcdRequest(0x26, Card_Type1)) // 寻卡函数，如果成功返回MI_OK   打印1次卡�???
    {
        uint16_t cardType = (Card_Type1[0] << 8) | Card_Type1[1]; // 读不同卡的类�???
        printf("卡类型：(0x%04X)\r\n", cardType);                 //"Card Type(0x%04X):"
        switch (cardType) {
            case 0x4400:
                printf("Mifare UltraLight\r\n");
                break;
            case 0x0400:
                printf("Mifare One(S50)\r\n");
                break;
            case 0x0200:
                printf("Mifare One(S70)\r\n");
                break;
            case 0x0800:
                printf("Mifare Pro(X)\r\n");
                break;
            case 0x4403:
                printf("Mifare DESFire\r\n");
                break;
            default:
                printf("Unknown Card\r\n");
                break;
        }

        status = PcdAnticoll(Card_ID); // 防冲�??? 如果成功返回MI_OK
        if (status != MI_OK) {
            printf("Anticoll Error\r\n");
        } else {
            printf("Serial Number:%02X%02X%02X%02X\r\n", Card_ID[0], Card_ID[1], Card_ID[2], Card_ID[3]);
        }

        status = PcdSelect(Card_ID); // 选卡 如果成功返回MI_OK
        if (status != MI_OK) {
            printf("Select Card Error\r\n");
        } else
            printf("Select Card OK\r\n");

        status = PcdAuthState(PICC_AUTHENT1A, 5, Card_KEY, Card_ID); //
        if (status != MI_OK) {
            printf("Auth State Error\r\n");
            return;
        }

        memset(Card_ID, 1, 4);
        memset(Card_Data, 1, 16);
        Card_Data[0] = 0xaa;
        status       = PcdWrite(6, Card_Data); // 写入数据
        if (status != MI_OK) {
            printf("Card Write Error\r\n");
            return;
        }
        memset(Card_Data, 0, 16); // 清零
        delay_us(8);

        status = PcdRead(6, Card_Data); // 读取我们写入的数据
        if (status != MI_OK) {
            printf("Card Read Error\r\n");
            return;
        } else {
            for (i = 0; i < 16; i++) {
                printf("%02X ", Card_Data[i]);
            }
            printf("\r\n");
        }

        memset(Card_Data, 0, 16);
        PcdHalt(); // 卡片进入休眠

        status = PcdHalt(); // 卡片进入休眠状�??
        if (status != MI_OK) {
            printf("PcdHalt Error\r\n");
        } else {
            printf("PcdHalt OK\r\n");
        }
    }
}

// 总初始化函数
void totalInit(void)
{
    delay_init(100);
    LCD_Init();         // 初始化LCD
    if (TP_Init() == 1) // 初始化触摸屏
    {
        status.mode = TOUCHERROR;
    }
    LCD_direction(1); // 设置LCD方向
    LCD_Clear(BLACK);
    POINT_COLOR = WHITE;
    BACK_COLOR  = BLACK;
    ds3231Init(); // 初始化DS3231
    at24Init();   // 初始化AT24C512
    // 初始化sdio

    // 初始化ld2410b

    status.mode = NORMALMOD;
}
/*
 */
void loop(void)
{
    // TODO:主循环 一帧
    // 更新时间
    updateTime();
    // 显示时间
    renderTime();
    // 显示电量（电压）
    renderBattery();
    // 显示导出按键
    renderButton();
    // 处理触摸事件
    handleEvent();

    HAL_Delay(10);
}
