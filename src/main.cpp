#include <M5Stack.h>
#include <Connection_Network.h>
#include <WiFiParameters.h>
#include <NMEA.h>

WiFiServer server(80);

double Current_Cap;

String NMEA_Line;
String NMEA_Header;

void setup() {
  Serial.begin(115200);
  M5.begin();
  M5.Lcd.fillRoundRect(0, 0, 320, 240, 7, 0xffff);
  M5.Lcd.setTextColor(0x7bef);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(90, 90);
  M5.Lcd.print("STARTING...");
  M5.Lcd.setCursor(90, 110);
  M5.Lcd.print("WAIT A MOMENT");

  initNMEA();
}

void loop() {
  if(!nmeaConnected()) {
    if (!isWifiConnected()) {
      ConnecteToWiFi(WIFI_SSID, WIFI_PASSWORD);
    }
    ConnectToNmeaSocket(NMEA_HOST, NMEA_PORT);
  }

  else {
    NMEA_Line = readNmeaLine();
    NMEA_Header = getValue(NMEA_Line, ',', 0).substring(3);
    if (isNMEAChecksumValid(NMEA_Line)) {

      if (NMEA_Header == "HDG") {
        Current_Cap = getValue(NMEA_Line, ',', 1).toInt();
        Serial.printf("Cap = %1f \n", Current_Cap);
      }

      else if (NMEA_Header == "VTG") {
        float Speed = getValue(NMEA_Line, ',', 7).toFloat();
        Serial.printf("Speed = %.2f K/H \n", Speed);
      }

      else if (NMEA_Header == "MWD") {
        String Wind = getValue(NMEA_Line, ',', 1);
        Serial.printf("Vent = %1f \n", Wind);;
      }

    }
  }
}
