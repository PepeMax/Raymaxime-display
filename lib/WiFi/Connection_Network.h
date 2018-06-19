#include <WiFi.h>

void ConnecteToWiFi(char* ssid, char* password );
void ConnectToNmeaSocket(char* nmea_host, int nmea_port);

bool isWifiConnected();
bool nmeaConnected();
String readNmeaLine();
