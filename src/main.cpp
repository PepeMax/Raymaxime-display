#include <M5Stack.h>
#include <Display.h>
#include <Network_Management.h>
#include <WiFiParameters.h>
#include <NMEA.h>
#include <SnigalK_Sentences.h>
#include <Setup.h>

void setup() {

  Serial.begin(115200);
  M5.begin();
  initDisplay();
  initNMEA();
}

void loop() {

  if (!isWifiConnected()) {
    Display_Connexion_WiFi(WIFI_SSID);
    ConnecteToWiFi(WIFI_SSID, WIFI_PASSWORD); //Try to connecte to wifi
    Display_WiFi_Connected();
    ConnectToTCPSocket(TCP_HOST, TCP_PORT); //Try to connecte to TCP Socket
  }

  if (M5.BtnA.wasReleased()) {
  }
  if (M5.BtnC.wasReleased()) {
  }
  M5.update();
}
