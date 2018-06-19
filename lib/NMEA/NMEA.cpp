#include <Arduino.h>
#include <Define_NMEA.h>

char* tmpNmeaSentence;

void initNMEA() {
  tmpNmeaSentence = (char*)malloc(MAX_NMEA_LENGHT*sizeof(char));
}

String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

bool isNMEAChecksumValid(String sentence) {
  int checksum = 0;

  char* tmpLine = tmpNmeaSentence;
  sentence.toCharArray(tmpLine, sentence.length()+1);

  tmpLine++;
  while (tmpLine[0] != '*') {
    checksum = checksum ^ tmpLine[0];
    tmpLine++;
  }

  tmpLine++;

  int printedChecksum = strtol(tmpLine, NULL, 16);
  tmpLine = NULL;

  return printedChecksum == checksum;
}
