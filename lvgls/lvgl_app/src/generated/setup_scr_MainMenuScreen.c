/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int MainMenuScreen_digital_clock_1_min_value = 49;
int MainMenuScreen_digital_clock_1_hour_value = 9;
int MainMenuScreen_digital_clock_1_sec_value = 9;
char MainMenuScreen_digital_clock_1_meridiem[] = "AM";
void setup_scr_MainMenuScreen(lv_ui *ui)
{
    //Write codes MainMenuScreen
    ui->MainMenuScreen = lv_obj_create(NULL);
    lv_obj_set_size(ui->MainMenuScreen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->MainMenuScreen, LV_SCROLLBAR_MODE_OFF);

    //Write style for MainMenuScreen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->MainMenuScreen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_Menu
    ui->MainMenuScreen_Menu = lv_obj_create(ui->MainMenuScreen);
    lv_obj_set_pos(ui->MainMenuScreen_Menu, 0, 0);
    lv_obj_set_size(ui->MainMenuScreen_Menu, 480, 320);
    lv_obj_set_scrollbar_mode(ui->MainMenuScreen_Menu, LV_SCROLLBAR_MODE_OFF);

    //Write style for MainMenuScreen_Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->MainMenuScreen_Menu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->MainMenuScreen_Menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->MainMenuScreen_Menu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->MainMenuScreen_Menu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_Menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_Menu, lv_color_hex(0x79BEE7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_Menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->MainMenuScreen_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->MainMenuScreen_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->MainMenuScreen_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->MainMenuScreen_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_label_1
    ui->MainMenuScreen_label_1 = lv_label_create(ui->MainMenuScreen_Menu);
    lv_obj_set_pos(ui->MainMenuScreen_label_1, 89, 129);
    lv_obj_set_size(ui->MainMenuScreen_label_1, 322, 32);
    lv_label_set_text(ui->MainMenuScreen_label_1, "欢迎使用打卡系统(*´∀`)~♥\n");
    lv_label_set_long_mode(ui->MainMenuScreen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for MainMenuScreen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->MainMenuScreen_label_1, lv_color_hex(0x06f7ed), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->MainMenuScreen_label_1, &lv_font_SourceHanSerifSC_Regular_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->MainMenuScreen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->MainMenuScreen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_userInfoButton
    ui->MainMenuScreen_userInfoButton = lv_button_create(ui->MainMenuScreen_Menu);
    lv_obj_set_pos(ui->MainMenuScreen_userInfoButton, 68, 200);
    lv_obj_set_size(ui->MainMenuScreen_userInfoButton, 100, 50);
    ui->MainMenuScreen_userInfoButton_label = lv_label_create(ui->MainMenuScreen_userInfoButton);
    lv_label_set_text(ui->MainMenuScreen_userInfoButton_label, "人员信息");
    lv_label_set_long_mode(ui->MainMenuScreen_userInfoButton_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->MainMenuScreen_userInfoButton_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->MainMenuScreen_userInfoButton, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->MainMenuScreen_userInfoButton_label, LV_PCT(100));

    //Write style for MainMenuScreen_userInfoButton, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_userInfoButton, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_userInfoButton, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_userInfoButton, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->MainMenuScreen_userInfoButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_userInfoButton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_userInfoButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->MainMenuScreen_userInfoButton, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->MainMenuScreen_userInfoButton, &lv_font_youyuan_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->MainMenuScreen_userInfoButton, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->MainMenuScreen_userInfoButton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_btn_3
    ui->MainMenuScreen_btn_3 = lv_button_create(ui->MainMenuScreen_Menu);
    lv_obj_set_pos(ui->MainMenuScreen_btn_3, 197, 200);
    lv_obj_set_size(ui->MainMenuScreen_btn_3, 100, 50);
    ui->MainMenuScreen_btn_3_label = lv_label_create(ui->MainMenuScreen_btn_3);
    lv_label_set_text(ui->MainMenuScreen_btn_3_label, "打卡记录");
    lv_label_set_long_mode(ui->MainMenuScreen_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->MainMenuScreen_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->MainMenuScreen_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->MainMenuScreen_btn_3_label, LV_PCT(100));

    //Write style for MainMenuScreen_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->MainMenuScreen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->MainMenuScreen_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->MainMenuScreen_btn_3, &lv_font_youyuan_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->MainMenuScreen_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->MainMenuScreen_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_btn_4
    ui->MainMenuScreen_btn_4 = lv_button_create(ui->MainMenuScreen_Menu);
    lv_obj_set_pos(ui->MainMenuScreen_btn_4, 330, 200);
    lv_obj_set_size(ui->MainMenuScreen_btn_4, 100, 50);
    ui->MainMenuScreen_btn_4_label = lv_label_create(ui->MainMenuScreen_btn_4);
    lv_label_set_text(ui->MainMenuScreen_btn_4_label, "关于");
    lv_label_set_long_mode(ui->MainMenuScreen_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->MainMenuScreen_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->MainMenuScreen_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->MainMenuScreen_btn_4_label, LV_PCT(100));

    //Write style for MainMenuScreen_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_btn_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->MainMenuScreen_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->MainMenuScreen_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->MainMenuScreen_btn_4, &lv_font_youyuan_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->MainMenuScreen_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->MainMenuScreen_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_btn_5
    ui->MainMenuScreen_btn_5 = lv_button_create(ui->MainMenuScreen_Menu);
    lv_obj_set_pos(ui->MainMenuScreen_btn_5, 402, 4);
    lv_obj_set_size(ui->MainMenuScreen_btn_5, 74, 31);
    ui->MainMenuScreen_btn_5_label = lv_label_create(ui->MainMenuScreen_btn_5);
    lv_label_set_text(ui->MainMenuScreen_btn_5_label, "随机图片");
    lv_label_set_long_mode(ui->MainMenuScreen_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->MainMenuScreen_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->MainMenuScreen_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->MainMenuScreen_btn_5_label, LV_PCT(100));

    //Write style for MainMenuScreen_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_btn_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->MainMenuScreen_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->MainMenuScreen_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->MainMenuScreen_btn_5, &lv_font_youyuan_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->MainMenuScreen_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->MainMenuScreen_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_userInfo
    ui->MainMenuScreen_userInfo = lv_obj_create(ui->MainMenuScreen);
    lv_obj_set_pos(ui->MainMenuScreen_userInfo, 0, 0);
    lv_obj_set_size(ui->MainMenuScreen_userInfo, 480, 320);
    lv_obj_set_scrollbar_mode(ui->MainMenuScreen_userInfo, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->MainMenuScreen_userInfo, LV_OBJ_FLAG_HIDDEN);

    //Write style for MainMenuScreen_userInfo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->MainMenuScreen_userInfo, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->MainMenuScreen_userInfo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->MainMenuScreen_userInfo, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->MainMenuScreen_userInfo, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_userInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_userInfo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_userInfo, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_userInfo, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->MainMenuScreen_userInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->MainMenuScreen_userInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->MainMenuScreen_userInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->MainMenuScreen_userInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_userInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_tileview_1
    ui->MainMenuScreen_tileview_1 = lv_tileview_create(ui->MainMenuScreen_userInfo);
    lv_obj_set_pos(ui->MainMenuScreen_tileview_1, 3, 49);
    lv_obj_set_size(ui->MainMenuScreen_tileview_1, 472, 259);
    lv_obj_set_scrollbar_mode(ui->MainMenuScreen_tileview_1, LV_SCROLLBAR_MODE_OFF);
    ui->MainMenuScreen_tileview_1_tile = lv_tileview_add_tile(ui->MainMenuScreen_tileview_1, 0, 0, LV_DIR_RIGHT);

    //Write style for MainMenuScreen_tileview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_tileview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_tileview_1, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_tileview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for MainMenuScreen_tileview_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_tileview_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_tileview_1, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_tileview_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_tileview_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



    //Write codes MainMenuScreen_table_1
    ui->MainMenuScreen_table_1 = lv_table_create(ui->MainMenuScreen_tileview_1_tile);
    lv_obj_set_pos(ui->MainMenuScreen_table_1, 103, 2);
    lv_obj_set_scrollbar_mode(ui->MainMenuScreen_table_1, LV_SCROLLBAR_MODE_OFF);
    lv_table_set_column_count(ui->MainMenuScreen_table_1,2);
    lv_table_set_row_count(ui->MainMenuScreen_table_1,13);
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,0,0,"姓名");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,1,0,"张三");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,2,0,"李四");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,3,0,"Citron");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,4,0,"Name");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,5,0,"Name");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,6,0,"Name");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,7,0,"Name");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,8,0,"Name");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,9,0,"Name");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,10,0,"Name");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,11,0,"Name");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,12,0,"Name");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,0,1,"学号");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,1,1,"$1");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,2,1,"$2");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,3,1,"$3");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,4,1,"Price");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,5,1,"Price");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,6,1,"Price");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,7,1,"Price");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,8,1,"Price");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,9,1,"Price");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,10,1,"Price");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,11,1,"Price");
    lv_table_set_cell_value(ui->MainMenuScreen_table_1,12,1,"Price");

    //Write style for MainMenuScreen_table_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->MainMenuScreen_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->MainMenuScreen_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->MainMenuScreen_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->MainMenuScreen_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_table_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_table_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_table_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->MainMenuScreen_table_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->MainMenuScreen_table_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->MainMenuScreen_table_1, lv_color_hex(0xd5dee6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->MainMenuScreen_table_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for MainMenuScreen_table_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->MainMenuScreen_table_1, lv_color_hex(0x393c41), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->MainMenuScreen_table_1, &lv_font_youyuan_12, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->MainMenuScreen_table_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->MainMenuScreen_table_1, LV_TEXT_ALIGN_CENTER, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_table_1, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->MainMenuScreen_table_1, 3, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->MainMenuScreen_table_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->MainMenuScreen_table_1, lv_color_hex(0xd5dee6), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->MainMenuScreen_table_1, LV_BORDER_SIDE_FULL, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->MainMenuScreen_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->MainMenuScreen_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->MainMenuScreen_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->MainMenuScreen_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_btn_6
    ui->MainMenuScreen_btn_6 = lv_button_create(ui->MainMenuScreen_userInfo);
    lv_obj_set_pos(ui->MainMenuScreen_btn_6, 376, -1);
    lv_obj_set_size(ui->MainMenuScreen_btn_6, 100, 50);
    ui->MainMenuScreen_btn_6_label = lv_label_create(ui->MainMenuScreen_btn_6);
    lv_label_set_text(ui->MainMenuScreen_btn_6_label, "返回");
    lv_label_set_long_mode(ui->MainMenuScreen_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->MainMenuScreen_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->MainMenuScreen_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->MainMenuScreen_btn_6_label, LV_PCT(100));

    //Write style for MainMenuScreen_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_btn_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->MainMenuScreen_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_btn_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->MainMenuScreen_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->MainMenuScreen_btn_6, &lv_font_youyuan_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->MainMenuScreen_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->MainMenuScreen_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_digital_clock_1
    static bool MainMenuScreen_digital_clock_1_timer_enabled = false;
    ui->MainMenuScreen_digital_clock_1 = lv_label_create(ui->MainMenuScreen);
    lv_obj_set_pos(ui->MainMenuScreen_digital_clock_1, 130, 0);
    lv_obj_set_size(ui->MainMenuScreen_digital_clock_1, 114, 36);
    lv_label_set_text(ui->MainMenuScreen_digital_clock_1, "9:49:09 AM");
    if (!MainMenuScreen_digital_clock_1_timer_enabled) {
        lv_timer_create(MainMenuScreen_digital_clock_1_timer, 1000, NULL);
        MainMenuScreen_digital_clock_1_timer_enabled = true;
    }

    //Write style for MainMenuScreen_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->MainMenuScreen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->MainMenuScreen_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->MainMenuScreen_digital_clock_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->MainMenuScreen_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->MainMenuScreen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->MainMenuScreen_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_digital_clock_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_digital_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->MainMenuScreen_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->MainMenuScreen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->MainMenuScreen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->MainMenuScreen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes MainMenuScreen_datetext_1
    ui->MainMenuScreen_datetext_1 = lv_label_create(ui->MainMenuScreen);
    lv_obj_set_pos(ui->MainMenuScreen_datetext_1, 0, 0);
    lv_obj_set_size(ui->MainMenuScreen_datetext_1, 130, 36);
    lv_label_set_text(ui->MainMenuScreen_datetext_1, "2024/04/22");
    lv_obj_set_style_text_align(ui->MainMenuScreen_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->MainMenuScreen_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->MainMenuScreen_datetext_1, MainMenuScreen_datetext_1_event_handler, LV_EVENT_ALL, NULL);

    //Write style for MainMenuScreen_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->MainMenuScreen_datetext_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->MainMenuScreen_datetext_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->MainMenuScreen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->MainMenuScreen_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->MainMenuScreen_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->MainMenuScreen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->MainMenuScreen_datetext_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->MainMenuScreen_datetext_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->MainMenuScreen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->MainMenuScreen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->MainMenuScreen_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->MainMenuScreen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->MainMenuScreen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->MainMenuScreen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of MainMenuScreen.


    //Update current screen layout.
    lv_obj_update_layout(ui->MainMenuScreen);

    //Init events for screen.
    events_init_MainMenuScreen(ui);
}
