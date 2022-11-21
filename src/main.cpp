/*
   MIT License

  Copyright (c) 2022 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  ______________  _____
  ___  __/___  /_ ___(_)_____ _______ _______
  __  /_  __  __ \__  / _  _ \__  __ `/_  __ \
  _  __/  _  /_/ /_  /  /  __/_  /_/ / / /_/ /
  /_/     /_.___/ /_/   \___/ _\__, /  \____/
                              /____/

*/

#define LGFX_USE_V1

#include <Arduino.h>
#include <lvgl.h>
#include "ui.h"
#include <LovyanGFX.hpp>
#include <ESP32Time.h>

#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#ifdef PLUS
#define SCR 30
class LGFX : public lgfx::LGFX_Device
{

  lgfx::Panel_ST7796 _panel_instance;

  lgfx::Bus_Parallel8 _bus_instance;

  lgfx::Light_PWM _light_instance;

  lgfx::Touch_FT5x06 _touch_instance;

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();

      cfg.port = 0;
      cfg.freq_write = 40000000;
      cfg.pin_wr = 47; // pin number connecting WR
      cfg.pin_rd = -1; // pin number connecting RD
      cfg.pin_rs = 0;  // Pin number connecting RS(D/C)
      cfg.pin_d0 = 9;  // pin number connecting D0
      cfg.pin_d1 = 46; // pin number connecting D1
      cfg.pin_d2 = 3;  // pin number connecting D2
      cfg.pin_d3 = 8;  // pin number connecting D3
      cfg.pin_d4 = 18; // pin number connecting D4
      cfg.pin_d5 = 17; // pin number connecting D5
      cfg.pin_d6 = 16; // pin number connecting D6
      cfg.pin_d7 = 15; // pin number connecting D7

      _bus_instance.config(cfg);              // Apply the settings to the bus.
      _panel_instance.setBus(&_bus_instance); // Sets the bus to the panel.
    }

    {                                      // Set display panel control.
      auto cfg = _panel_instance.config(); // Get the structure for display panel settings.

      cfg.pin_cs = -1;   // Pin number to which CS is connected (-1 = disable)
      cfg.pin_rst = 4;   // pin number where RST is connected (-1 = disable)
      cfg.pin_busy = -1; // pin number to which BUSY is connected (-1 = disable)

      // * The following setting values ​​are set to general default values ​​for each panel, and the pin number (-1 = disable) to which BUSY is connected, so please try commenting out any unknown items.

      cfg.memory_width = 320;  // Maximum width supported by driver IC
      cfg.memory_height = 480; // Maximum height supported by driver IC
      cfg.panel_width = 320;   // actual displayable width
      cfg.panel_height = 480;  // actual displayable height
      cfg.offset_x = 0;        // Panel offset in X direction
      cfg.offset_y = 0;        // Panel offset in Y direction
      cfg.offset_rotation = 3;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = false;
      cfg.invert = true;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = true;

      _panel_instance.config(cfg);
    }

    {                                      // Set backlight control. (delete if not necessary)
      auto cfg = _light_instance.config(); // Get the structure for backlight configuration.

      cfg.pin_bl = 45;     // pin number to which the backlight is connected
      cfg.invert = false;  // true to invert backlight brightness
      cfg.freq = 44100;    // backlight PWM frequency
      cfg.pwm_channel = 0; // PWM channel number to use

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance); // Sets the backlight to the panel.
    }

    { // Configure settings for touch screen control. (delete if not necessary)
      auto cfg = _touch_instance.config();

      cfg.x_min = 0;   // Minimum X value (raw value) obtained from the touchscreen
      cfg.x_max = 319; // Maximum X value (raw value) obtained from the touchscreen
      cfg.y_min = 0;   // Minimum Y value obtained from touchscreen (raw value)
      cfg.y_max = 479; // Maximum Y value (raw value) obtained from the touchscreen
      cfg.pin_int = 7; // pin number to which INT is connected
      cfg.bus_shared = false;
      cfg.offset_rotation = 0;

      // For I2C connection
      cfg.i2c_port = 0;    // Select I2C to use (0 or 1)
      cfg.i2c_addr = 0x38; // I2C device address number
      cfg.pin_sda = 6;     // pin number where SDA is connected
      cfg.pin_scl = 5;     // pin number to which SCL is connected
      cfg.freq = 400000;   // set I2C clock

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance); // Set the touchscreen to the panel.
    }

    setPanel(&_panel_instance); // Sets the panel to use.
  }
};

#else
#define SCR 8
class LGFX : public lgfx::LGFX_Device
{

  lgfx::Panel_ST7796 _panel_instance;

  lgfx::Bus_SPI _bus_instance;

  lgfx::Light_PWM _light_instance;

  // lgfx::Touch_FT5x06 _touch_instance;

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config(); // Get the structure for bus configuration.

      // SPI bus settings
      cfg.spi_host = VSPI_HOST; // Select the SPI to use ESP32-S2,C3 : SPI2_HOST or SPI3_HOST / ESP32 : VSPI_HOST or HSPI_HOST
      // * With the ESP-IDF version upgrade, VSPI_HOST and HSPI_HOST descriptions are deprecated, so if an error occurs, use SPI2_HOST and SPI3_HOST instead.
      cfg.spi_mode = 3;                  // Set SPI communication mode (0 ~ 3)
      cfg.freq_write = 27000000;         // SPI clock when sending (up to 80MHz, rounded to 80MHz divided by an integer)
      cfg.freq_read = 6000000;           // SPI clock when receiving
      cfg.spi_3wire = false;             // set to true if receiving on MOSI pin
      cfg.use_lock = true;               // set to true to use transaction lock
      cfg.dma_channel = SPI_DMA_CH_AUTO; // Set the DMA channel to use (0=not use DMA / 1=1ch / 2=ch / SPI_DMA_CH_AUTO=auto setting)
      // * With the ESP-IDF version upgrade, SPI_DMA_CH_AUTO (automatic setting) is recommended for the DMA channel. Specifying 1ch and 2ch is deprecated.
      cfg.pin_sclk = 14; // set SPI SCLK pin number
      cfg.pin_mosi = 13; // Set MOSI pin number for SPI
      cfg.pin_miso = -1; // set SPI MISO pin number (-1 = disable)
      cfg.pin_dc = 21;   // Set SPI D/C pin number (-1 = disable)

      _bus_instance.config(cfg);              // Apply the settings to the bus.
      _panel_instance.setBus(&_bus_instance); // Sets the bus to the panel.
    }

    {                                      // Set display panel control.
      auto cfg = _panel_instance.config(); // Get the structure for display panel settings.

      cfg.pin_cs = 15;   // Pin number to which CS is connected (-1 = disable)
      cfg.pin_rst = 22;  // pin number where RST is connected (-1 = disable)
      cfg.pin_busy = -1; // pin number to which BUSY is connected (-1 = disable)

      // * The following setting values ​​are set to general default values ​​for each panel, and the pin number (-1 = disable) to which BUSY is connected, so please try commenting out any unknown items.

      cfg.memory_width = 320;  // Maximum width supported by driver IC
      cfg.memory_height = 480; // Maximum height supported by driver IC
      cfg.panel_width = 320;   // actual displayable width
      cfg.panel_height = 480;  // actual displayable height
      cfg.offset_x = 0;        // Panel offset in X direction
      cfg.offset_y = 0;        // Panel offset in Y direction
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = false;
      cfg.invert = false;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = false;

      _panel_instance.config(cfg);
    }

    {                                      // Set backlight control. (delete if not necessary)
      auto cfg = _light_instance.config(); // Get the structure for backlight configuration.

      cfg.pin_bl = 23;     // pin number to which the backlight is connected
      cfg.invert = false;  // true to invert backlight brightness
      cfg.freq = 44100;    // backlight PWM frequency
      cfg.pwm_channel = 1; // PWM channel number to use

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance); // Sets the backlight to the panel.
    }

    // { // Configure settings for touch screen control. (delete if not necessary)
    //    auto cfg = _touch_instance.config();

    //    cfg.x_min = 0;    // Minimum X value (raw value) obtained from the touchscreen
    //    cfg.x_max = 319;  // Maximum X value (raw value) obtained from the touchscreen
    //    cfg.y_min = 0;    // Minimum Y value obtained from touchscreen (raw value)
    //    cfg.y_max = 479;  // Maximum Y value (raw value) obtained from the touchscreen
    //    cfg.pin_int = 36; // pin number to which INT is connected
    //    cfg.bus_shared = false;
    //    cfg.offset_rotation = 0;

    //    // For I2C connection
    //    cfg.i2c_port = 0;    // Select I2C to use (0 or 1)
    //    cfg.i2c_addr = 0x38; // I2C device address number
    //    cfg.pin_sda = 18;    // pin number where SDA is connected
    //    cfg.pin_scl = 19;    // pin number to which SCL is connected
    //    cfg.freq = 400000;   // set I2C clock

    //    _touch_instance.config(cfg);
    //    _panel_instance.setTouch(&_touch_instance); // Set the touchscreen to the panel.
    // }

    setPanel(&_panel_instance); // Sets the panel to use.
  }
};

struct TouchData
{
  int xpos;
  int ypos;
  int event;
} touch_data;

#include "FT6336U.h"

FT6336U ft6336u(18, 19, -1, 36);

#endif

#define URL "https://iot.fbiego.com/worldcup/"
#define SECONDS 5 // request interval
#define DELAY (portTICK_PERIOD_MS * 1000 * SECONDS)

const char *ssid = ""; // your wifi name
const char *pass = "";   // your wifi password
bool requests = false;

bool countdown;
long start;

bool playing, firstHalf;
long periodStart;
DynamicJsonDocument json(4096);

// Create an instance of the prepared class.
LGFX tft;

/* Change to your screen resolution */
static const uint32_t screenWidth = 480;
static const uint32_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
static lv_disp_drv_t disp_drv;

static lv_color_t disp_draw_buf[screenWidth * SCR];
static lv_color_t disp_draw_buf2[screenWidth * SCR];

LV_IMG_DECLARE(ui_img_four_64_png);
LV_IMG_DECLARE(ui_img_six_64_png);
LV_IMG_DECLARE(ui_img_eight_64_png);
LV_IMG_DECLARE(ui_img_nine_64_png);
LV_IMG_DECLARE(ui_img_three_64_png);
LV_IMG_DECLARE(ui_img_seven_64_png);

lv_img_dsc_t digits[10] = {ui_img_zero_64_png, ui_img_one_64_png, ui_img_two_64_png, ui_img_three_64_png, ui_img_four_64_png,
                           ui_img_five_64_png, ui_img_six_64_png, ui_img_seven_64_png, ui_img_eight_64_png, ui_img_nine_64_png};

ESP32Time rtc;
WiFiMulti wifiMulti;
HTTPClient http;

lv_img_dsc_t getFlag(String country);

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  if (tft.getStartCount() == 0)
  {
    tft.endWrite();
  }

  tft.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::swap565_t *)&color_p->full);

  lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
#ifdef PLUS
  uint16_t touchX, touchY;

  bool touched = tft.getTouch(&touchX, &touchY);

  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
#else
  data->point.x = touch_data.xpos;
  data->point.y = touch_data.ypos;

  if (touch_data.event == 1)
  {
    data->state = LV_INDEV_STATE_PR;
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
#endif
}

void onBrightnessChange(lv_event_t *e)
{
  lv_obj_t *slider = lv_event_get_target(e);
  int brightness = (int)lv_slider_get_value(slider);
  tft.setBrightness(brightness);
}

void requestResult(int statusCode, String payload)
{
  Serial.printf("Request received, code: %d\n", statusCode);

  if (statusCode == HTTP_CODE_OK)
  {

    deserializeJson(json, payload);

    long time = json["time"].as<long>();
    rtc.setTime(time);

    String tournament = json["match"]["tournament"].as<String>();

    String stad = json["match"]["venue"]["staduim"].as<String>();
    String city = json["match"]["venue"]["city"].as<String>();

    String homeTeam = json["match"]["teams"]["home"]["name"].as<String>();
    String awayTeam = json["match"]["teams"]["away"]["name"].as<String>();

    String referee = json["match"]["referee"]["name"].as<String>();
    String refCountry = json["match"]["referee"]["country"].as<String>();

    String matchStatus = json["match"]["status"]["description"].as<String>();
    int matchCode = json["match"]["status"]["code"].as<int>();

    int homeScore = json["match"]["score"]["home"].as<int>();
    int awayScore = json["match"]["score"]["away"].as<int>();

    String refLabel = referee + ", " + refCountry;
    String stadLabel = stad + ", " + city;

    if (matchCode == 0)
    {
      lv_obj_add_flag(ui_scoreHome1, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_scoreAway1, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_scoreSeparator, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_matchTime, LV_OBJ_FLAG_HIDDEN);
      countdown = true;
      start = json["match"]["time"]["start"].as<long>();
    }
    else
    {
      lv_img_set_src(ui_scoreHome1, &digits[homeScore % 10]);
      lv_img_set_src(ui_scoreAway1, &digits[awayScore % 10]);
      lv_obj_clear_flag(ui_scoreHome1, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_scoreAway1, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_scoreSeparator, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_matchTime, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_countdownLabel, LV_OBJ_FLAG_HIDDEN);
      countdown = false;

      if (matchCode == 6)
      {
        playing = true;
        lv_obj_clear_flag(ui_matchTime, LV_OBJ_FLAG_HIDDEN);
        periodStart = json["match"]["time"]["period"].as<long>();
        firstHalf = (matchCode == 6);
      }
    }

    lv_label_set_text(ui_matchGroup, tournament.c_str());
    lv_label_set_text(ui_homeTeamLabel, homeTeam.c_str());
    lv_label_set_text(ui_awayTeamLabel, awayTeam.c_str());
    lv_label_set_text(ui_stadiumText, stadLabel.c_str());
    lv_label_set_text(ui_refereeText, refLabel.c_str());
    lv_label_set_text(ui_matchStatus, matchStatus.c_str());

    lv_img_dsc_t homeFlag = getFlag(homeTeam);
    lv_img_dsc_t awayFlag = getFlag(awayTeam);

    lv_img_set_src(ui_homeFlag, &homeFlag);
    lv_img_set_src(ui_awayFlag, &awayFlag);
  }
}

void sendRequest(void *parameter)
{
  while (requests)
  {

    http.begin(URL);
    int httpCode;
    httpCode = http.GET();

    String payload = http.getString();
    requestResult(httpCode, payload);
    vTaskDelay(DELAY);
  }
  http.end();
  // When you're done, call vTaskDelete. Don't forget this!
  vTaskDelete(NULL);
}

void connectWiFi(void *parameter)
{
  uint8_t status;
  while (true)
  {
    status = wifiMulti.run();
    Serial.printf("WiFi trying: %d\n", status);
    if (status == WL_CONNECTED || status == WL_CONNECT_FAILED || status == WL_DISCONNECTED || status == WL_NO_SSID_AVAIL)
    {
      break;
    }
  }
  Serial.printf("WiFi exit: %d\n", status);
  // When you're done, call vTaskDelete. Don't forget this!
  vTaskDelete(NULL);
}

bool runRequest()
{
  // returns true if the task was created
  // returns false if the previous task has not completed, new one cannot be created
  if (!requests)
  {
    requests = true;
    // xTaskCreatePinnedToCore(
    xTaskCreate(
        sendRequest,     // Function that should be called
        "HTTP Requests", // Name of the task (for debugging)
        8192,            // Stack size (bytes)
        NULL,            // Parameter to pass
        1,               // Task priority
        NULL
        // NULL,               // Task handle
        // 1
    );

    return true;
  }
  else
  {
    return false;
  }
}

lv_img_dsc_t getFlag(String country)
{
  if (country == "Ecuador")
  {
    return ui_img_ecuador_png;
  }
  else if (country == "Qatar")
  {
    return ui_img_qatar_png;
  }
  else if (country == "Denmark")
  {
    return ui_img_denmark_png;
  }
  else if (country == "Croatia")
  {
    return ui_img_croatia_png;
  }
  else if (country == "Costa Rica")
  {
    return ui_img_costa_rica_png;
  }
  else if (country == "Canada")
  {
    return ui_img_canada_png;
  }
  else if (country == "Cameroon")
  {
    return ui_img_cameroon_png;
  }
  else if (country == "Brazil")
  {
    return ui_img_brazil_png;
  }
  else if (country == "Belgium")
  {
    return ui_img_belgium_png;
  }
  else if (country == "Australia")
  {
    return ui_img_australia_png;
  }
  else if (country == "Argentina")
  {
    return ui_img_argentina_png;
  }
  else if (country == "Morocco")
  {
    return ui_img_morocco_png;
  }
  else if (country == "Netherlands")
  {
    return ui_img_netherlands_png;
  }
  else if (country == "Poland")
  {
    return ui_img_poland_png;
  }
  else if (country == "Portugal")
  {
    return ui_img_portugal_png;
  }
  else if (country == "Saudi Arabia")
  {
    return ui_img_saudi_arabia_png;
  }
  else if (country == "Serbia")
  {
    return ui_img_serbia_png;
  }
  else if (country == "South Korea")
  {
    return ui_img_south_korea_png;
  }
  else if (country == "Spain")
  {
    return ui_img_spain_png;
  }
  else if (country == "Switzerland")
  {
    return ui_img_switzerland_png;
  }
  else if (country == "Tunisia")
  {
    return ui_img_tunisia_png;
  }
  else if (country == "USA")
  {
    return ui_img_united_states_png;
  }
  else if (country == "Uruguay")
  {
    return ui_img_uruguay_png;
  }
  else if (country == "Wales")
  {
    return ui_img_wales_png;
  }
  else if (country == "England")
  {
    return ui_img_england_png;
  }
  else if (country == "France")
  {
    return ui_img_france_png;
  }
  else if (country == "Germany")
  {
    return ui_img_germany_png;
  }
  else if (country == "Ghana")
  {
    return ui_img_ghana_png;
  }
  else if (country == "Iran")
  {
    return ui_img_iran_png;
  }
  else if (country == "Japan")
  {
    return ui_img_japan_png;
  }
  else if (country == "Mexico")
  {
    return ui_img_mexico_png;
  }
  else
  {
    return ui_img_qatar_png;
  }
}

void timeTo(long t)
{
  long now = rtc.getLocalEpoch();
  long diff = t - now;
  int h = diff / 3600;
  diff %= 3600;
  int m = diff / 60;
  int s = diff % 60;

  lv_obj_clear_flag(ui_countdownLabel, LV_OBJ_FLAG_HIDDEN);
  lv_label_set_text_fmt(ui_countdownLabel, "%02d:%02d:%02d", h, m, s);
}

void matchTime(long start, bool first)
{

  long diff = rtc.getLocalEpoch() - start;
  int f = 2700;
  if (!first)
  {
    diff += 2700;
    f = 5400;
  }
  int m = diff / 60;
  int s = diff % 60;

  if (diff > f)
  {
    lv_label_set_text_fmt(ui_matchTime, "%d+%02d:%02d", f / 60, m - (f / 60), s);
  }
  else
  {
    lv_label_set_text_fmt(ui_matchTime, "%02d:%02d", m, s);
  }
}

void setup()
{
  Serial.begin(115200);

  tft.init();
  tft.initDMA();
  tft.startWrite();

#ifndef PLUS
  ft6336u.begin();

#endif

  lv_init();
  Serial.print("Width: ");
  Serial.print(screenWidth);
  Serial.print("\tHeight: ");
  Serial.println(screenHeight);

  if (!disp_draw_buf)
  {
    Serial.println("LVGL disp_draw_buf allocate failed!");
  }
  else
  {

    Serial.print("Display buffer size: ");

    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, disp_draw_buf2, screenWidth * SCR);

    /* Initialize the display */
    lv_disp_drv_init(&disp_drv);
    /* Change the following line to your display resolution */
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /* Initialize the input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    ui_init();

    Serial.println("Setup done");
  }

  wifiMulti.addAP(ssid, pass);

  xTaskCreate(
      connectWiFi,    // Function that should be called
      "WIFI Connect", // Name of the task (for debugging)
      8192,           // Stack size (bytes)
      NULL,           // Parameter to pass
      1,              // Task priority
      NULL);
}

void loop()
{
  lv_timer_handler(); /* let the GUI do its work */
  delay(5);

  if (WiFi.isConnected())
  {
    runRequest();
  }
  if (countdown)
  {
    timeTo(start);
  }
  else
  {
    if (playing)
    {
      matchTime(periodStart, firstHalf);
    }
  }
}