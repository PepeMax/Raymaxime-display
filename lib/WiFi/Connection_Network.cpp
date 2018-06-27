#include <WiFi.h>

const int lf = 10;  // Linefeed in ASCII

WiFiClient client;

//----------------------------------//
//            Functions             //

bool isWifiConnected(){
  return WiFi.status() == WL_CONNECTED;
}

void ConnecteToWiFi(char* ssid, char* password) {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
}

void ConnectToTCPSocket(char* tcp_host, int tcp_port) {
  if (client.connect(tcp_host, tcp_port)) {
    Serial.println("Connected to the TCP socket");
  }
  else {
    Serial.println("connection failed");
  }
}

String readNmeaLine(){
  return client.readStringUntil(lf);
}

void ap_enable(){
  client.println("{\"method\":\"set\", \"name\":\"ap.enabled\", \"value\": false}");
  Serial.print("Auto pilot disabled");
}

void ap_disable(){
  client.println("{\"method\":\"set\", \"name\":\"ap.enabled\", \"value\": true}");
  Serial.print("Auto pilot enabled");
}
