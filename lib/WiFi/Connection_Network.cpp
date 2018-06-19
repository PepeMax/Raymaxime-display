#include <WiFi.h>

const int lf = 10;  // Linefeed in ASCII

const int watchdog = 5000;  // Fréquence du watchdog - Watchdog frequency

unsigned long previousMillis = millis();

WiFiClient client;

bool nmeaConnected(){
  return client.available();
}

String readNmeaLine(){
  return client.readStringUntil(lf);
}

bool isWifiConnected(){
  return WiFi.status() == WL_CONNECTED;
}

IPAddress GetIp() {
  return WiFi.localIP();
}


//----------------------------------//
//  Connection to the WiFi Network  //
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
  Serial.print("WiFi connected");
  Serial.print(WiFi.localIP());
}
//----------------------------------//
//  Connection to the WiFi Network  //

void ConnectToNmeaSocket(char* nmea_host, int nmea_port) {
  unsigned long currentMillis = millis();

  if ( currentMillis - previousMillis > watchdog ) {
    previousMillis = currentMillis;

    if (!client.connect(nmea_host, nmea_port)) {
      Serial.println("Connexion échoué");
      return;
    }

    String url = "/watchdog?command=watchdog&uptime=";
    url += String(millis());
    url += "&ip=";
    url += WiFi.localIP().toString();

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
    "NMEA_HOST: " + nmea_host + "\r\n" +
    "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client expiré !");
        client.stop();
        return;
      }
    }
  }
}
