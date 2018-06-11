#include <M5Stack.h>
#include <Connection_Network.h>
#include <WiFiParameters.h>

const int   watchdog = 5000;        // Fréquence du watchdog - Watchdog frequency
unsigned long previousMillis = millis();

void setup() {
  Serial.begin(115200);

}

void loop() {
  unsigned long currentMillis = millis();

  if (!isWifiConnected()) {
    ConnecteToWiFi(WIFI_SSID, WIFI_PASSWORD);
    Serial.println("");
    Serial.println("WiFi Connected");
    Serial.println("IP Adress: ");
    Serial.println(WiFi.localIP());
  }
}
