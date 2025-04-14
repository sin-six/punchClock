#ifndef ___STATUS__H__
#define ___STATUS__H__

#include "i2c.h"
#include <stdbool.h>
#include <stdint.h>

#define OK 0
#define DS3231RESET 1           // DS3231掉电
#define RC522ERROR (1 << 1)     // RC522错误
#define AT24ERROR (1 << 2)      // AT24错误
#define TOUCHNOUPDATE (1 << 3)  // 触摸屏没有更新
#define TOUCHUPDATED (1 << 4)   // 触摸屏有更新
#define TOUCHERROR (1 << 5)     // 触摸屏错误
#define NORMALMOD (1 << 6)      // 普通模式
#define TIMECHANGEMODE (1 << 7) // 时间修改模式
#define EXPORTMODE (1 << 8)     // 导出模式

typedef struct Status
{
    uint16_t mode;
} Status;

#endif