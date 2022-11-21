// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: resistor

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_matchScreen;
lv_obj_t * ui_scoreSeparator;
lv_obj_t * ui_scoreHome1;
lv_obj_t * ui_scoreAway1;
lv_obj_t * ui_scoreHome2;
lv_obj_t * ui_scoreAway2;
lv_obj_t * ui_matchStatus;
lv_obj_t * ui_awayTeamLabel;
lv_obj_t * ui_homeTeamLabel;
lv_obj_t * ui_awayFlag;
lv_obj_t * ui_vsLabel;
lv_obj_t * ui_stadiumText;
lv_obj_t * ui_homeFlag;
lv_obj_t * ui_refereeText;
lv_obj_t * ui_matchGroup;
lv_obj_t * ui_stadiumLabel;
lv_obj_t * ui_refereeLabel;
lv_obj_t * ui_matchTime;
lv_obj_t * ui_countdownLabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_matchScreen_screen_init(void)
{
    ui_matchScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_matchScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_matchScreen, &ui_img_2137734435, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_matchScreen, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_scoreSeparator = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_scoreSeparator, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_scoreSeparator, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_scoreSeparator, LV_ALIGN_CENTER);
    lv_label_set_text(ui_scoreSeparator, ":");
    lv_obj_set_style_text_font(ui_scoreSeparator, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_scoreHome1 = lv_img_create(ui_matchScreen);
    lv_img_set_src(ui_scoreHome1, &ui_img_zero_64_png);
    lv_obj_set_width(ui_scoreHome1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_scoreHome1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scoreHome1, -30);
    lv_obj_set_y(ui_scoreHome1, 0);
    lv_obj_set_align(ui_scoreHome1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_scoreHome1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_scoreHome1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_scoreHome1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_scoreHome1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_scoreAway1 = lv_img_create(ui_matchScreen);
    lv_img_set_src(ui_scoreAway1, &ui_img_two_64_png);
    lv_obj_set_width(ui_scoreAway1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_scoreAway1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scoreAway1, 30);
    lv_obj_set_y(ui_scoreAway1, 0);
    lv_obj_set_align(ui_scoreAway1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_scoreAway1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_scoreAway1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_scoreAway1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_scoreAway1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_scoreHome2 = lv_img_create(ui_matchScreen);
    lv_img_set_src(ui_scoreHome2, &ui_img_one_64_png);
    lv_obj_set_width(ui_scoreHome2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_scoreHome2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scoreHome2, -70);
    lv_obj_set_y(ui_scoreHome2, 0);
    lv_obj_set_align(ui_scoreHome2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_scoreHome2, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_scoreHome2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_scoreHome2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_scoreHome2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_scoreAway2 = lv_img_create(ui_matchScreen);
    lv_img_set_src(ui_scoreAway2, &ui_img_five_64_png);
    lv_obj_set_width(ui_scoreAway2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_scoreAway2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scoreAway2, 70);
    lv_obj_set_y(ui_scoreAway2, 0);
    lv_obj_set_align(ui_scoreAway2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_scoreAway2, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_scoreAway2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_scoreAway2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_scoreAway2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_matchStatus = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_matchStatus, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_matchStatus, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_matchStatus, 0);
    lv_obj_set_y(ui_matchStatus, 200);
    lv_obj_set_align(ui_matchStatus, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_matchStatus, "Finished");
    lv_obj_set_style_text_font(ui_matchStatus, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_awayTeamLabel = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_awayTeamLabel, 200);
    lv_obj_set_height(ui_awayTeamLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_awayTeamLabel, 270);
    lv_obj_set_y(ui_awayTeamLabel, 50);
    lv_label_set_long_mode(ui_awayTeamLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_awayTeamLabel, "Ecuador");
    lv_obj_set_style_text_align(ui_awayTeamLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_awayTeamLabel, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_homeTeamLabel = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_homeTeamLabel, 200);
    lv_obj_set_height(ui_homeTeamLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_homeTeamLabel, -270);
    lv_obj_set_y(ui_homeTeamLabel, 50);
    lv_obj_set_align(ui_homeTeamLabel, LV_ALIGN_TOP_RIGHT);
    lv_label_set_long_mode(ui_homeTeamLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_homeTeamLabel, "Qatar");
    lv_obj_set_style_text_align(ui_homeTeamLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_homeTeamLabel, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_awayFlag = lv_img_create(ui_matchScreen);
    lv_img_set_src(ui_awayFlag, &ui_img_ecuador_png);
    lv_obj_set_width(ui_awayFlag, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_awayFlag, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_awayFlag, 160);
    lv_obj_set_y(ui_awayFlag, 0);
    lv_obj_set_align(ui_awayFlag, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_awayFlag, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_awayFlag, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_vsLabel = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_vsLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_vsLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_vsLabel, 0);
    lv_obj_set_y(ui_vsLabel, 50);
    lv_obj_set_align(ui_vsLabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_vsLabel, "vs");
    lv_obj_set_style_text_font(ui_vsLabel, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_stadiumText = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_stadiumText, 350);
    lv_obj_set_height(ui_stadiumText, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_stadiumText, 80);
    lv_obj_set_y(ui_stadiumText, -10);
    lv_obj_set_align(ui_stadiumText, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_long_mode(ui_stadiumText, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_stadiumText, "Khalifa International Stadium, Doha");
    lv_obj_set_style_text_font(ui_stadiumText, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_homeFlag = lv_img_create(ui_matchScreen);
    lv_img_set_src(ui_homeFlag, &ui_img_qatar_png);
    lv_obj_set_width(ui_homeFlag, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_homeFlag, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_homeFlag, -160);
    lv_obj_set_y(ui_homeFlag, 0);
    lv_obj_set_align(ui_homeFlag, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_homeFlag, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_homeFlag, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_refereeText = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_refereeText, 350);
    lv_obj_set_height(ui_refereeText, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_refereeText, 80);
    lv_obj_set_y(ui_refereeText, -30);
    lv_obj_set_align(ui_refereeText, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_long_mode(ui_refereeText, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_refereeText, "Daniele Orsato, Italy");
    lv_obj_set_style_text_font(ui_refereeText, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_matchGroup = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_matchGroup, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_matchGroup, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_matchGroup, 0);
    lv_obj_set_y(ui_matchGroup, 20);
    lv_obj_set_align(ui_matchGroup, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_matchGroup, "World Cup, Group A");
    lv_obj_set_style_text_font(ui_matchGroup, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_stadiumLabel = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_stadiumLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_stadiumLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_stadiumLabel, 10);
    lv_obj_set_y(ui_stadiumLabel, -10);
    lv_obj_set_align(ui_stadiumLabel, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_stadiumLabel, "Stadium:");
    lv_obj_set_style_text_font(ui_stadiumLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_refereeLabel = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_refereeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_refereeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_refereeLabel, 10);
    lv_obj_set_y(ui_refereeLabel, -30);
    lv_obj_set_align(ui_refereeLabel, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_refereeLabel, "Referee:");
    lv_obj_set_style_text_font(ui_refereeLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_matchTime = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_matchTime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_matchTime, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_matchTime, 0);
    lv_obj_set_y(ui_matchTime, 100);
    lv_obj_set_align(ui_matchTime, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_matchTime, "35:24");
    lv_obj_set_style_radius(ui_matchTime, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_matchTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_matchTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_matchTime, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_matchTime, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_matchTime, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_matchTime, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_matchTime, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_countdownLabel = lv_label_create(ui_matchScreen);
    lv_obj_set_width(ui_countdownLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_countdownLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_countdownLabel, 0);
    lv_obj_set_y(ui_countdownLabel, 230);
    lv_obj_set_align(ui_countdownLabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_countdownLabel, "01:23:30");
    lv_obj_add_flag(ui_countdownLabel, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_font(ui_countdownLabel, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_matchScreen_screen_init();
    lv_disp_load_scr(ui_matchScreen);
}
