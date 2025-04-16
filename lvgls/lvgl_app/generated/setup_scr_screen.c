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



int screen_digital_clock_1_min_value = 25;
int screen_digital_clock_1_hour_value = 11;
int screen_digital_clock_1_sec_value = 50;
char screen_digital_clock_1_meridiem[] = "AM";
void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_1
    ui->screen_img_1 = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_1, 0, 2);
    lv_obj_set_size(ui->screen_img_1, 480, 320);
    lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_1, &_150_58103072_RGB565A8_480x320);
    lv_image_set_pivot(ui->screen_img_1, 50,50);
    lv_image_set_rotation(ui->screen_img_1, 0);

    //Write style for screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_1
    ui->screen_btn_1 = lv_button_create(ui->screen);
    lv_obj_set_pos(ui->screen_btn_1, 379, 2);
    lv_obj_set_size(ui->screen_btn_1, 100, 50);
    ui->screen_btn_1_label = lv_label_create(ui->screen_btn_1);
    lv_label_set_text(ui->screen_btn_1_label, "导出");
    lv_label_set_long_mode(ui->screen_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_1_label, LV_PCT(100));

    //Write style for screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_1, &lv_font_youyuan_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_digital_clock_1
    static bool screen_digital_clock_1_timer_enabled = false;
    ui->screen_digital_clock_1 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_digital_clock_1, 130, 2);
    lv_obj_set_size(ui->screen_digital_clock_1, 130, 36);
    lv_label_set_text(ui->screen_digital_clock_1, "11:25:50 AM");
    if (!screen_digital_clock_1_timer_enabled) {
        lv_timer_create(screen_digital_clock_1_timer, 1000, NULL);
        screen_digital_clock_1_timer_enabled = true;
    }

    //Write style for screen_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_digital_clock_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_digital_clock_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_digital_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_datetext_1
    ui->screen_datetext_1 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_datetext_1, 0, 2);
    lv_obj_set_size(ui->screen_datetext_1, 130, 36);
    lv_label_set_text(ui->screen_datetext_1, "2024/04/22");
    lv_obj_set_style_text_align(ui->screen_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->screen_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->screen_datetext_1, screen_datetext_1_event_handler, LV_EVENT_ALL, NULL);

    //Write style for screen_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_datetext_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_datetext_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_datetext_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_datetext_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_exportSuccess
    ui->screen_exportSuccess = lv_win_create(ui->screen);
    lv_obj_set_pos(ui->screen_exportSuccess, 142, 117);
    lv_obj_set_size(ui->screen_exportSuccess, 192, 96);
    lv_obj_set_scrollbar_mode(ui->screen_exportSuccess, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_exportSuccess, LV_OBJ_FLAG_HIDDEN);
    lv_obj_t * screen_exportSuccess_title = lv_win_add_title(ui->screen_exportSuccess, "导出成功！");
    lv_obj_t * screen_exportSuccess_header = lv_win_get_header(ui->screen_exportSuccess);
    lv_obj_set_height(screen_exportSuccess_header, 40);
    ui->screen_exportSuccess_item0 = lv_win_add_button(ui->screen_exportSuccess, LV_SYMBOL_CLOSE, 40);
    lv_obj_t *screen_exportSuccess_label = lv_label_create(lv_win_get_content(ui->screen_exportSuccess));
    lv_obj_set_scrollbar_mode(lv_win_get_content(ui->screen_exportSuccess), LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(screen_exportSuccess_label, "打卡记录已导出到SD卡内！");

    //Write style for screen_exportSuccess, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_exportSuccess, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_exportSuccess, lv_color_hex(0xeeeef6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_exportSuccess, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_exportSuccess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_exportSuccess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_exportSuccess_extra_content_main_default
    static lv_style_t style_screen_exportSuccess_extra_content_main_default;
    ui_init_style(&style_screen_exportSuccess_extra_content_main_default);

    lv_style_set_bg_opa(&style_screen_exportSuccess_extra_content_main_default, 255);
    lv_style_set_bg_color(&style_screen_exportSuccess_extra_content_main_default, lv_color_hex(0xeeeef6));
    lv_style_set_bg_grad_dir(&style_screen_exportSuccess_extra_content_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_text_color(&style_screen_exportSuccess_extra_content_main_default, lv_color_hex(0x393c41));
    lv_style_set_text_font(&style_screen_exportSuccess_extra_content_main_default, &lv_font_youyuan_12);
    lv_style_set_text_opa(&style_screen_exportSuccess_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_exportSuccess_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_screen_exportSuccess_extra_content_main_default, 2);
    lv_obj_add_style(lv_win_get_content(ui->screen_exportSuccess), &style_screen_exportSuccess_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_exportSuccess_extra_header_main_default
    static lv_style_t style_screen_exportSuccess_extra_header_main_default;
    ui_init_style(&style_screen_exportSuccess_extra_header_main_default);

    lv_style_set_bg_opa(&style_screen_exportSuccess_extra_header_main_default, 255);
    lv_style_set_bg_color(&style_screen_exportSuccess_extra_header_main_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_screen_exportSuccess_extra_header_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_text_color(&style_screen_exportSuccess_extra_header_main_default, lv_color_hex(0x393c41));
    lv_style_set_text_font(&style_screen_exportSuccess_extra_header_main_default, &lv_font_youyuan_12);
    lv_style_set_text_opa(&style_screen_exportSuccess_extra_header_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_exportSuccess_extra_header_main_default, 0);
    lv_style_set_text_line_space(&style_screen_exportSuccess_extra_header_main_default, 2);
    lv_style_set_pad_top(&style_screen_exportSuccess_extra_header_main_default, 5);
    lv_style_set_pad_right(&style_screen_exportSuccess_extra_header_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_exportSuccess_extra_header_main_default, 5);
    lv_style_set_pad_left(&style_screen_exportSuccess_extra_header_main_default, 5);
    lv_style_set_pad_column(&style_screen_exportSuccess_extra_header_main_default, 5);
    lv_obj_add_style(lv_win_get_header(ui->screen_exportSuccess), &style_screen_exportSuccess_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_exportSuccess_extra_btns_main_default
    static lv_style_t style_screen_exportSuccess_extra_btns_main_default;
    ui_init_style(&style_screen_exportSuccess_extra_btns_main_default);

    lv_style_set_radius(&style_screen_exportSuccess_extra_btns_main_default, 8);
    lv_style_set_border_width(&style_screen_exportSuccess_extra_btns_main_default, 0);
    lv_style_set_bg_opa(&style_screen_exportSuccess_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_exportSuccess_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_exportSuccess_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_shadow_width(&style_screen_exportSuccess_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_exportSuccess_item0, &style_screen_exportSuccess_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spangroup_1
    ui->screen_spangroup_1 = lv_spangroup_create(ui->screen);
    lv_obj_set_pos(ui->screen_spangroup_1, 181, 106);
    lv_obj_set_size(ui->screen_spangroup_1, 205, 120);
    lv_spangroup_set_align(ui->screen_spangroup_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->screen_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->screen_spangroup_1, LV_SPAN_MODE_BREAK);
    //create span
    ui->screen_spangroup_1_span = lv_spangroup_new_span(ui->screen_spangroup_1);
    lv_span_set_text(ui->screen_spangroup_1_span, "文字测试");
    lv_style_set_text_color(lv_span_get_style(ui->screen_spangroup_1_span), lv_color_hex(0xcb1010));
    lv_style_set_text_decor(lv_span_get_style(ui->screen_spangroup_1_span), LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(lv_span_get_style(ui->screen_spangroup_1_span), &lv_font_youyuan_28);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_1_main_main_default
    static lv_style_t style_screen_spangroup_1_main_main_default;
    ui_init_style(&style_screen_spangroup_1_main_main_default);

    lv_style_set_border_width(&style_screen_spangroup_1_main_main_default, 0);
    lv_style_set_radius(&style_screen_spangroup_1_main_main_default, 0);
    lv_style_set_bg_opa(&style_screen_spangroup_1_main_main_default, 0);
    lv_style_set_pad_top(&style_screen_spangroup_1_main_main_default, 0);
    lv_style_set_pad_right(&style_screen_spangroup_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_screen_spangroup_1_main_main_default, 0);
    lv_style_set_pad_left(&style_screen_spangroup_1_main_main_default, 0);
    lv_style_set_shadow_width(&style_screen_spangroup_1_main_main_default, 0);
    lv_obj_add_style(ui->screen_spangroup_1, &style_screen_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->screen_spangroup_1);

    //Write codes screen_slider_1
    ui->screen_slider_1 = lv_slider_create(ui->screen);
    lv_obj_set_pos(ui->screen_slider_1, 176, 56);
    lv_obj_set_size(ui->screen_slider_1, 160, 24);
    lv_slider_set_range(ui->screen_slider_1, 0, 100);
    lv_slider_set_mode(ui->screen_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->screen_slider_1, 50, LV_ANIM_OFF);

    //Write style for screen_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_slider_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_slider_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_slider_1, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_slider_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

    //Init events for screen.
    events_init_screen(ui);
}
