/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void MainMenuScreen_userInfoButton_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.MainMenuScreen_userInfoPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.MainMenuScreen_MainMenu, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.MainMenuScreen_CheckInfoPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.MainMenuScreen_MainMenu, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.MainMenuScreen_About, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.MainMenuScreen_MainMenu, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_7_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.MainMenuScreen_newUserInfo, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.MainMenuScreen_userInfoPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.MainMenuScreen_MainMenu, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_10_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.MainMenuScreen_CheckInfoPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.MainMenuScreen_MainMenu, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_9_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_aboutReturnButton_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.MainMenuScreen_About, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.MainMenuScreen_MainMenu, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_11_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.MainMenuScreen_newUserInfo, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_hourUpButton_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_minuteUpButton_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_hourDownButton_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_minuteDownButton_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_14_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.MainMenuScreen_changeTime, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_15_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_btn_13_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.MainMenuScreen_eventPopUp, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void MainMenuScreen_clock_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.MainMenuScreen_changeTime, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

void events_init_MainMenuScreen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->MainMenuScreen_userInfoButton, MainMenuScreen_userInfoButton_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_3, MainMenuScreen_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_4, MainMenuScreen_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_7, MainMenuScreen_btn_7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_8, MainMenuScreen_btn_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_6, MainMenuScreen_btn_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_10, MainMenuScreen_btn_10_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_9, MainMenuScreen_btn_9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_aboutReturnButton, MainMenuScreen_aboutReturnButton_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_11, MainMenuScreen_btn_11_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_hourUpButton, MainMenuScreen_hourUpButton_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_minuteUpButton, MainMenuScreen_minuteUpButton_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_hourDownButton, MainMenuScreen_hourDownButton_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_minuteDownButton, MainMenuScreen_minuteDownButton_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_14, MainMenuScreen_btn_14_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_15, MainMenuScreen_btn_15_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_btn_13, MainMenuScreen_btn_13_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MainMenuScreen_clock, MainMenuScreen_clock_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
