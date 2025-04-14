//////////////////////////////////////////////////////////////////////////////////
// 本程序只供学习使用，未经作者许可，不得用于其它任何用途
// 测试硬件：单片机STM32F429IGT6,正点原子Apollo STM32F4/F7开发板,主频180MHZ，晶振12MHZ
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
#ifndef __GUI_H__
#define __GUI_H__

#include <stdint.h>                                                                                             //下面注释由ai生成
void GUI_DrawPoint(uint16_t x, uint16_t y, uint16_t color);                                                     // 在指定坐标绘制一个点
void LCD_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color);                              // 填充指定区域为指定颜色
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);                                          // 绘制一条线
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);                                     // 绘制一个矩形
void Draw_Circle(uint16_t x0, uint16_t y0, uint16_t fc, uint8_t r);                                             // 在指定坐标绘制一个圆
void Draw_Triangel(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);               // 绘制一个三角形
void Fill_Triangel(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);               // 填充一个三角形
void LCD_ShowChar(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t num, uint8_t size, uint8_t mode);   // 在指定位置显示一个字符
void LCD_ShowNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size);                              // 在指定位置显示一个数字
void LCD_Show2Num(uint16_t x, uint16_t y, uint16_t num, uint8_t len, uint8_t size, uint8_t mode);               // 在指定位置显示两个数字
void LCD_ShowString(uint16_t x, uint16_t y, uint8_t size, uint8_t *p, uint8_t mode);                            // 在指定位置显示一个字符串
void GUI_DrawFont16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s, uint8_t mode);                // 使用16x16字体在指定位置绘制字符串
void GUI_DrawFont24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s, uint8_t mode);                // 使用24x24字体在指定位置绘制字符串
void GUI_DrawFont32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s, uint8_t mode);                // 使用32x32字体在指定位置绘制字符串
void Show_Str(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str, uint8_t size, uint8_t mode);      // 在指定位置显示字符串
void Gui_Drawbmp16(uint16_t x, uint16_t y, const unsigned char *p);                                             // 显示40*40 QQ图片
void Gui_Drawbmp(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const unsigned char *p);              // 显示任意大小图片
void gui_circle(int xc, int yc, uint16_t c, int r, int fill);                                                   // 绘制一个圆，可选填充
void Gui_StrCenter(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str, uint8_t size, uint8_t mode); // 在指定位置居中显示字符串
void LCD_DrawFillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);                                 // 绘制并填充一个矩形
void LCD_DrawLine2(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t size, uint16_t color);          // 绘制指定宽度和颜色的线
void LCD_DrawRoundRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t c);                    // 绘制一个圆角矩形
void LCD_FillRoundRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t c);                    // 填充一个圆角矩形

void LCD_BufferPresent(uint16_t *buffer);                                                                                             // 推送缓冲区
void LCD_BufferFill(uint16_t *buffer, uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color);                            // 填充缓冲区
void LCD_BufferDrawPoint(uint16_t *buffer, uint16_t x, uint16_t y);                                                                   // 在缓冲区绘制一个点
void LCD_BufferDrawLine(uint16_t *buffer, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);                                        // 在缓冲区绘制一条线
void LCD_BufferDrawRectangle(uint16_t *buffer, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);                                   // 绘制一个矩形
void Draw_BufferCircle(uint16_t *buffer, uint16_t x0, uint16_t y0, uint16_t fc, uint8_t r);                                           // 在指定坐标绘制一个圆
void Draw_BufferTriangel(uint16_t *buffer, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);             // 绘制一个三角形
void Fill_BufferTriangel(uint16_t *buffer, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);             // 填充一个三角形
void LCD_BufferShowChar(uint16_t *buffer, uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t num, uint8_t size, uint8_t mode); // 在指定位置显示一个字符
void LCD_BufferShowNum(uint16_t *buffer, uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size);                            // 在指定位置显示一个数字

void LCD_BufferShowString(uint16_t *buffer, uint16_t x, uint16_t y, uint8_t size, uint8_t *p, uint8_t mode);             // 在指定位置显示一个字符串
void GUI_BufferDrawFont16(uint16_t *buffer, uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s, uint8_t mode); // 使用16x16字体在指定位置绘制字符串
#endif
