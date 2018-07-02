#include <M5Stack.h>

void initDisplay();

void Display_Connexion_WiFi(char* ssid);
void Display_WiFi_Connected();

void display_text(String text_to_display, float value, int zone);
void display_lines();
