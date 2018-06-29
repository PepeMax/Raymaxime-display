#include <WiFi.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson

const int lf = 10;  // Linefeed in ASCII

WiFiClient client;
DynamicJsonBuffer jsonBuffer;

//----------------------------------//
//            Functions             //

bool isWifiConnected(){
  return WiFi.status() == WL_CONNECTED;
}

void ConnecteToWiFi(char* ssid, char* password) {
  WiFi.begin(ssid, password);
  int connection_loop_count = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    if (connection_loop_count++ == 10) {
      ESP.restart();
    }
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
}

void ConnectToTCPSocket(char* tcp_host, int tcp_port) {
  if (client.connect(tcp_host, tcp_port)) {
    Serial.println("Connected to the TCP socket");
  }
  else {
    Serial.println("connection failed");
  }
}

JsonObject& get_json_sentence(String name_json_get) {
  JsonObject& send_json_get = jsonBuffer.createObject();
  send_json_get["method"] = "get";
  send_json_get["name"] = name_json_get;
  String get_output;
  send_json_get.printTo(get_output);
  client.println(get_output);
  jsonBuffer.clear();
  String json_reply = client.readStringUntil(lf);
  JsonObject& json_return = jsonBuffer.parseObject(json_reply);

  jsonBuffer.clear();

  return json_return;
}

float get_json_value(String name_value) {
  JsonObject& json_value = get_json_sentence(name_value);
  if (json_value.success()) {
    return json_value[name_value]["value"];
  }
}

void set_json_sentence(String name_json_set, String value_json_set){
  JsonObject& send_json_set = jsonBuffer.createObject();
  send_json_set["method"] = "set";
  send_json_set["name"] = name_json_set;
  send_json_set["value"] = value_json_set;
  String set_output;
  send_json_set.printTo(set_output);
  client.println(set_output);
}
