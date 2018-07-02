#include <M5Stack.h>

void initDisplay() {
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
}

void display_text(String text_to_display, float value, int zone) {
  if (zone == 1) {
    M5.Lcd.fillRect(0, 40 , 159, 60, BLACK);
    M5.Lcd.setTextDatum(CC_DATUM);
    M5.Lcd.drawString(text_to_display, (int)(M5.Lcd.width()/4), (int)(M5.Lcd.height()/8*1), 1);
    M5.Lcd.drawFloat(value, 2, (int)(M5.Lcd.width()/4), (int)(M5.Lcd.height()/4), 1);
  }
  else if (zone == 2) {
    M5.Lcd.fillRect(0, 160 , 159, 180, BLACK);
    M5.Lcd.setTextDatum(CC_DATUM);
    M5.Lcd.drawString(text_to_display, (int)(M5.Lcd.width()/4), (int)(M5.Lcd.height()/8*5) , 1);
    M5.Lcd.drawFloat(value, 2, (int)(M5.Lcd.width()/4), (int)(M5.Lcd.height()/4*3), 1);
  }
  else if (zone == 3) {
    M5.Lcd.fillRect(161, 40, 159, 60, BLACK);
    M5.Lcd.setTextDatum(CC_DATUM);
    M5.Lcd.drawString(text_to_display, (int)(M5.Lcd.width()/4*3), (int)(M5.Lcd.height()/8*1) , 1);
    M5.Lcd.drawFloat(value, 2, (int)(M5.Lcd.width()/4*3), (int)(M5.Lcd.height()/4), 1);
  }
  else if (zone == 4) {
    M5.Lcd.fillRect(161, 160, 159, 180, BLACK);
    M5.Lcd.setTextDatum(CC_DATUM);
    M5.Lcd.drawString(text_to_display, (int)(M5.Lcd.width()/4*3), (int)(M5.Lcd.height()/8*5) , 1);
    M5.Lcd.drawFloat(value, 2, (int)(M5.Lcd.width()/4*3), (int)(M5.Lcd.height()/4*3), 1);
  }
}

void display_lines() {
  M5.Lcd.clear(BLACK);
  M5.lcd.drawLine((int)(M5.Lcd.width()/2), 0, (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()), WHITE);
  M5.lcd.drawLine(0, (int)(M5.Lcd.height())/2, (int)(M5.Lcd.width()), (int)(M5.Lcd.height())/2, WHITE);
}

void Display_Connexion_WiFi(char* ssid) {
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextDatum(CC_DATUM);
  M5.Lcd.drawString("Try to connecte to", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2), 2);
  M5.Lcd.drawString(ssid, (int)(M5.Lcd.width()/2), 150, 2);
}

void Display_WiFi_Connected() {
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextDatum(CC_DATUM);
  M5.Lcd.drawString("M5Stack has been", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2), 2);
  M5.Lcd.drawString("connected to WiFi", (int)(M5.Lcd.width()/2), 150, 2);

}
