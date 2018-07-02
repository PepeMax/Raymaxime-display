#include <M5Stack.h>
#include <Display.h>
#include <Network_Management.h>
#include <WiFiParameters.h>
#include <SnigalK_Sentences.h>
#include <Setup.h>

float True_heading;
float Wind_direction;
float Wind_speed;
float Target_heading;

bool is_btnA_Pressed_1500 = false;
bool is_btnA_Pressed_5000 = false;
bool is_btnC_Pressed_1500 = false;
bool is_btnC_Pressed_5000 = false;
bool status_pilot = false;

void setup() {
  Serial.begin(115200);
  M5.begin();
  initDisplay();
}

void loop() {
  if (!isWifiConnected()) {
    Display_Connexion_WiFi(WIFI_SSID);
    ConnecteToWiFi(WIFI_SSID, WIFI_PASSWORD); //Try to connecte to wifi
    Display_WiFi_Connected();
    ConnectToTCPSocket(TCP_HOST, TCP_PORT); //Try to connecte to TCP Socket
    delay(1000);
    display_lines();
  }
  True_heading = get_json_value(HEADING);
  Wind_direction = get_json_value(WIND_DIRECTION);
  Wind_speed = get_json_value(WIND_SPEED);
  Target_heading = get_json_value(HEADING_TARGET);


  if (M5.BtnB.wasReleased()) {
    if (status_pilot == false) {
      set_json_sentence_String(PILOTE_STATUS, true);
      set_json_sentence_float(HEADING_TARGET, True_heading);
      status_pilot = true;
    }
    else if (status_pilot == true) {
      set_json_sentence_String(PILOTE_STATUS, false);
      status_pilot = false;
    }
  }
  if (M5.BtnA.wasReleased()) {
    set_json_sentence_float(HEADING_TARGET, Target_heading + 1);
    is_btnA_Pressed_1500 = false;
    is_btnA_Pressed_5000 = false;
  }
  if (M5.BtnA.pressedFor(1500)) {
    if (!is_btnA_Pressed_1500) {
      set_json_sentence_float(HEADING_TARGET, Target_heading + 9);
      is_btnA_Pressed_1500 = true;
    }
  }
  if (M5.BtnA.pressedFor(3000)) {
    if (!is_btnA_Pressed_5000) {
      set_json_sentence_float(HEADING_TARGET, Target_heading + TACK);
      is_btnA_Pressed_5000 = true;
    }
  }
  if (M5.BtnC.wasReleased()) {
    set_json_sentence_float(HEADING_TARGET, Target_heading - 1);
    is_btnC_Pressed_1500 = false;
    is_btnC_Pressed_5000 = false;
  }
  if (M5.BtnC.pressedFor(1500)) {
    if (!is_btnC_Pressed_1500) {
      set_json_sentence_float(HEADING_TARGET, Target_heading - 9);
      is_btnC_Pressed_1500 = true;
    }
  }
  if (M5.BtnC.pressedFor(3000)) {
    if (!is_btnC_Pressed_5000) {
      set_json_sentence_float(HEADING_TARGET, Target_heading - TACK);
      is_btnC_Pressed_5000 = true;
    }
  }
  M5.update();

  display_text(TEXT_ZONE_1, Wind_direction, 1);
  display_text(TEXT_ZONE_2, Wind_speed, 2);
  display_text(TEXT_ZONE_3, True_heading, 3);
  display_text(TEXT_ZONE_4, Target_heading, 4);

}
