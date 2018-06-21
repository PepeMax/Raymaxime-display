#include <M5Stack.h>

void initDisplay() {
  M5.Lcd.fillRoundRect(0, 0, 320, 240, 7, 0xffff);
  M5.Lcd.setTextColor(0x7bef);
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
