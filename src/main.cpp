#include <M5Stack.h>
#include <Connection_Network.h>
#include <WiFiParameters.h>
#include <NMEA.h>
#include <Display.h>

String NMEA_Line;
String NMEA_Header;

WiFiServer server(80);

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
  M5.Lcd.fillRoundRect(0, 0, 320, 240, 7, 0xffff);
  M5.lcd.drawLine(160, 0, 160, 240, 0x00);
  M5.lcd.drawLine(0, 120, 160, 120, 0x00);
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
      if (NMEA_Header == "HDM") {
        double Current_Cap = getValue(NMEA_Line, ',', 1).toInt();
        Serial.printf("Cap = %.2f °\n", Current_Cap); //Debug
        display_text("Cap : " + String(Current_Cap), 1);
      }
      else if (NMEA_Header == "VTG") {
        float Speed = getValue(NMEA_Line, ',', 7).toFloat();
        Serial.printf("Speed = %.2f K/H \n", Speed); //Debug
        display_text("Speed : " + String(Speed), 2);
      }
      else if (NMEA_Header == "MWV") {
        float Wind = getValue(NMEA_Line, ',', 3).toFloat();;
        Serial.printf("Vent = %.2f ND\n", Wind); //Debug
        display_text("Vent : " + String(Wind), 3);
      }
    }
  }
}
