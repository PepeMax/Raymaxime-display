#include <WiFi.h>

void ConnecteToWiFi(char* ssid, char* password ) {
  WiFi.begin(ssid, password);
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i++ > 10) {
      WiFi.reconnect();
      i = 0;
    }
  }
}


bool isWifiConnected(){
  return WiFi.status() == WL_CONNECTED;
}
