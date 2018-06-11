#include <Arduino.h>
#include <WiFi.h>
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

  if ( currentMillis - previousMillis > watchdog ) {
    previousMillis = currentMillis;
    WiFiClient client;

    if (!client.connect(NMEA_HOST, NMEA_PORT)) {
      Serial.println("Connetion failed");
      return;
    }

    String url = "/watchdog?command=watchdog&uptime=";
    url += String(millis());
    url += "&ip=";
    url += WiFi.localIP().toString();



    // Envoi la requete au serveur
    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "NMEA_HOST: " + NMEA_HOST + "\r\n" +
               "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client timeout !");
        client.stop();
        return;
      }
    }

    // Affichage de toutes les lignes envoyées par le serveur sur un terminal série
    // Read all the lines of the reply from server and print them to Serial
    while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print("Check line " + line);

    }
  }
}
