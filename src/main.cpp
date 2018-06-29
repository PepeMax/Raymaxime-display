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
  }

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
}
