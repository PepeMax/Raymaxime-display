#include <M5Stack.h>

void initDisplay() {
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
}

void display_text(String text_to_display, int zone) {
  if (zone == 1) {
    M5.Lcd.fillRect(0, 0 , 159, 119, 0xffff);
    M5.Lcd.setCursor(10, 60);
    M5.Lcd.println(text_to_display);
  }
  else if (zone == 2) {
    M5.Lcd.fillRect(0, 161 , 159, 119, 0xffff);
    M5.Lcd.setCursor(10, 180);
    M5.Lcd.println(text_to_display);
  }
  else if (zone == 3) {
    M5.Lcd.fillRect(161, 0, 239, 159, 0xffff);
    M5.Lcd.setCursor(170, 120);
    M5.Lcd.println(text_to_display);
  }
}

void Display_Connexion_WiFi(char* ssid) {
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(50, 110);
  M5.Lcd.println("Try to connecte to");
  M5.Lcd.setCursor(75, 140);
  M5.Lcd.println(ssid);
}

void Display_WiFi_Connected() {
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 120);
  M5.Lcd.print("M5Stack has been connected");
}


/*  M5.Lcd.fillRoundRect(0, 0, 320, 240, 7, 0xffff);
M5.lcd.drawLine(160, 0, 160, 240, 0x00);
M5.lcd.drawLine(0, 120, 160, 120, 0x00);*/
