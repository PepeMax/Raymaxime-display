#include <WiFi.h>

bool isWifiConnected();

void ConnecteToWiFi(char* ssid, char* password);
void ConnectToTCPSocket(char* tcp_host, int tcp_port);

void ap_enable();
void ap_disable();

String readNmeaLine();
