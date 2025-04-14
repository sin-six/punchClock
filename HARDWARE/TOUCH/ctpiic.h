//////////////////////////////////////////////////////////////////////////////////
// 本程序只供学习使用，未经作者许可，不得用于其它任何用途
// 测试硬件：单片机STM32F103C8T6,F103C8T6核心开发板,主频72MHZ，晶振8MHZ
// QDtech-TFT液晶驱动 for STM32 IO模拟
// xiao冯@ShenZhen QDtech co.,LTD
// 公司网站:www.qdtft.com
// 淘宝网站：http://qdtech.taobao.com
// wiki技术网站：http://www.lcdwiki.com
// 我司提供技术支持，任何技术问题欢迎随时交流学习
// 固话(传真) :+86 0755-23594567
// 手机:15989313508（冯工）
// 邮箱:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
// 技术支持QQ:3002773612  3002778157
// 技术交流QQ群:324828016
// 创建日期:2018/08/09
// 版本：V1.0
// 版权所有，盗版必究。
// Copyright(C) 深圳市全动电子技术有限公司 2018-2028
// All rights reserved
/****************************************************************************************************
//=========================================电源接线================================================//
//     LCD模块                STM32单片机
//      VCC          接        DC5V/3.3V      //电源
//      GND          接          GND          //电源地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为SPI总线
//     LCD模块                STM32单片机
//    SDI(MOSI)      接          PF9          //液晶屏SPI总线数据写信号
//    SDO(MISO)      接          PF8          //液晶屏SPI总线数据读信号，如果不需要读，可以不接线
//=======================================液晶屏控制线接线==========================================//
//     LCD模块 					      STM32单片机
//       LED         接          PD6          //液晶屏背光控制信号，如果不需要控制，接5V或3.3V
//       SCK         接          PF7          //液晶屏SPI总线时钟信号
//     LCD_RS        接          PD5          //液晶屏数据/命令控制信号
//     LCD_RST       接          PD12         //液晶屏复位控制信号
//     LCD_CS        接          PD11         //液晶屏片选控制信号
//=========================================触摸屏触接线=========================================//
//如果模块不带触摸功能或者带有触摸功能，但是不需要触摸功能，则不需要进行触摸屏接线
//	   LCD模块                STM32单片机
//     CTP_INT       接          PH11         //电容触摸屏中断信号
//     CTP_SDA       接          PI3          //电容触摸屏IIC数据信号
//     CTP_RST       接          PI8          //电容触摸屏复位信号
//     CTP_SCL       接          PH6          //电容触摸屏IIC时钟信号
**************************************************************************************************/
/* @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 **************************************************************************************************/
#ifndef __CTPIIC_H
#define __CTPIIC_H
#include "sys.h"
#include "main.h"

#define SOFTWARE_IIC

#ifdef SOFTWARE_IIC

#define CTP_SCL_PORT I2C1_SCL_GPIO_Port
#define CTP_SCL_PIN_NUM 6
#define CTP_SCL_PIN I2C1_SCL_Pin
#define CTP_SDA_PORT I2C1_SDA_GPIO_Port
#define CTP_SDA_PIN_NUM 7
#define CTP_SDA_PIN I2C1_SDA_Pin

// IIC IO方向设置
#define CTP_SDA_IN()                                                              \
    {                                                                             \
        I2C1_SDA_GPIO_Port->MODER &= ~(CTP_SDA_PIN_NUM << (CTP_SDA_PIN_NUM * 2)); \
        I2C1_SDA_GPIO_Port->MODER |= 0 << CTP_SDA_PIN_NUM * 2;                    \
    }
#define CTP_SDA_OUT()                                                             \
    {                                                                             \
        I2C1_SDA_GPIO_Port->MODER &= ~(CTP_SDA_PIN_NUM << (CTP_SDA_PIN_NUM * 2)); \
        I2C1_SDA_GPIO_Port->MODER |= 1 << CTP_SDA_PIN_NUM * 2;                    \
    }

// IO操作函数
#define CTP_IIC_SCL(n) (n ? HAL_GPIO_WritePin(I2C1_SCL_GPIO_Port, CTP_SCL_PIN, GPIO_PIN_SET) : \
                            HAL_GPIO_WritePin(I2C1_SCL_GPIO_Port, CTP_SCL_PIN, GPIO_PIN_RESET)) // SCL
#define CTP_IIC_SDA(n) (n ? HAL_GPIO_WritePin(CTP_SDA_PORT, CTP_SDA_PIN, GPIO_PIN_SET) : \
                            HAL_GPIO_WritePin(CTP_SDA_PORT, CTP_SDA_PIN, GPIO_PIN_RESET)) // SDA
#define CTP_READ_SDA HAL_GPIO_ReadPin(CTP_SDA_PORT, CTP_SDA_PIN)                          // 输入SDA
#endif

// IIC所有操作函数
void CTP_IIC_Init(void);                 // 初始化IIC的IO口
void CTP_IIC_Start(void);                // 发送IIC开始信号
void CTP_IIC_Stop(void);                 // 发送IIC停止信号
void CTP_IIC_Send_Byte(u8 txd);          // IIC发送一个字节
u8 CTP_IIC_Read_Byte(unsigned char ack); // IIC读取一个字节
u8 CTP_IIC_Wait_Ack(void);               // IIC等待ACK信号
void CTP_IIC_Ack(void);                  // IIC发送ACK信号
void CTP_IIC_NAck(void);                 // IIC不发送ACK信号

#endif
