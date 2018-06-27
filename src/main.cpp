#include <M5Stack.h>
#include <Display.h>
#include <Connection_Network.h>
#include <WiFiParameters.h>
#include <NMEA.h>

String NMEA_Line;
String NMEA_Header;

void setup() {
  Serial.begin(115200);
  M5.begin();
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
    ap_enable();
  }
  if (M5.BtnB.wasReleased()) {
    ap_disable();
  }

  M5.update();
}
