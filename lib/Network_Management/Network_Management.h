#include <WiFi.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson

bool isWifiConnected();

void ConnecteToWiFi(char* ssid, char* password);
void ConnectToTCPSocket(char* tcp_host, int tcp_port);

JsonObject& get_json_sentence(String name_json_get);
float get_json_value(String name_value);
void set_json_sentence_float(String name_json_set, float value_json_set);
void set_json_sentence_String(String name_json_set, bool value_json_set);
