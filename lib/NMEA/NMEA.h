#include <Arduino.h>

String getValue(String data, char separator, int index);
bool isNMEAChecksumValid(String sentence);

void initNMEA();
