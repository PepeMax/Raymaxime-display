#include <M5Stack.h>
#include <Connection_Network.h>
#include <WiFiParameters.h>

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

  ConnecteToWiFi(WIFI_SSID, WIFI_PASSWORD);

  M5.Lcd.fillRoundRect(0, 0, 320, 240, 7, 0xffff);
  M5.Lcd.setCursor(90, 70);
  M5.Lcd.print("WEB SERVER");
  M5.Lcd.setCursor(90, 90);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.print("ACTIVATED");
  M5.Lcd.setCursor(90, 110);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.print("ON IP ADRESS :");
  M5.Lcd.setCursor(90, 130);
  M5.Lcd.print(WiFi.localIP());
  M5.Lcd.setCursor(90, 150);
  server.begin();
}

String parseGET(String str) {
  String tmp = "";
  for (int i = 0, j = 0; i < str.length(); i++) {
    if (str[i] == ' ') j++;
    if (j == 1) {
      if (str[i] != ' ') tmp += str[i];
    }
    if (j == 2) break;
  }
  return tmp;  // tmp.substring(1)
}

void loop() {
  String currentString = "";
  bool readyResponse = false;
  WiFiClient client = server.available();
  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      if ((c != '\r') && (c != '\n'))
      currentString += c;
      else
      readyResponse = true;

      if (readyResponse) {
        String GET = parseGET(currentString);
        client.flush();
        client.println("<!DOCTYPE html");
        client.println("<html lang=\"fr\">");
        client.println("<head>");
        client.println("<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\"/>");
        client.println("<title>Configuration</title>");
        client.println("<style type=\"text/css\">""</style>");
        client.println("</head>");
        client.println("<body>");
        client.println("<p>Hi");
        client.println("</p>");;
        client.println("</body>");
        client.print("</html>");
        client.println();
        client.println();
        readyResponse = false;
        currentString = "";
        client.stop();
      }
    }
  }

}
