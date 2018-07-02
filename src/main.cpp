#include <M5Stack.h>
#include <Display.h>
#include <Network_Management.h>
#include <WiFiParameters.h>
#include <SnigalK_Sentences.h>
#include <Setup.h>

bool is_btnA_Pressed_1500 = false;
bool is_btnA_Pressed_5000 = false;
bool is_btnC_Pressed_1500 = false;
bool is_btnC_Pressed_5000 = false;

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

  float True_heading = get_json_value(HEADING);
  float Wind_direction = get_json_value(WIND_DIRECTION);
  float Wind_speed = get_json_value(WIND_SPEED);
  float Target_heading = get_json_value(HEADING_TARGET);


  if (M5.BtnA.wasReleased()) {
    Serial.println("+1");
    is_btnA_Pressed_1500 = false;
    is_btnA_Pressed_5000 = false;
  }
  if (M5.BtnA.pressedFor(1500)) {
    if (!is_btnA_Pressed_1500) {
      Serial.println("+9");
      is_btnA_Pressed_1500 = true;
    }
  }
  if (M5.BtnA.pressedFor(5000)) {
    if (!is_btnA_Pressed_5000) {
      Serial.println(TACK);
      is_btnA_Pressed_5000 = true;
    }
  }
  if (M5.BtnC.wasReleased()) {
    Serial.println("-1");
    is_btnC_Pressed_1500 = false;
    is_btnC_Pressed_5000 = false;
  }
  if (M5.BtnC.pressedFor(1500)) {
    if (!is_btnC_Pressed_1500) {
      Serial.println("-9");
      is_btnC_Pressed_1500 = true;
    }
  }
  if (M5.BtnC.pressedFor(5000)) {
    if (!is_btnC_Pressed_5000) {
      Serial.println(TACK);
      is_btnC_Pressed_5000 = true;
    }
  }
  M5.update();
  display_text(TEXT_ZONE_1, Wind_direction, 1);
  display_text(TEXT_ZONE_2, Wind_speed, 2);
  display_text(TEXT_ZONE_3, True_heading, 3);
  display_text(TEXT_ZONE_4, Target_heading, 4);
}
