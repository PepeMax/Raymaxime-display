#include <Arduino.h>
#include <Connection_Network.h>
#include <WiFiParameters.h>

const int   watchdog = 5000;        // Fréquence du watchdog - Watchdog frequency
unsigned long previousMillis = millis();

void setup() {

  Serial.begin(115200);
  Serial.print("Connection to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP Adress: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();

  if (!isWifiConnected()) {
    ConnecteToWiFi(WIFI_SSID, WIFI_PASSWORD);
  }
}
