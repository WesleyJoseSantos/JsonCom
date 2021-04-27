#include <Arduino.h>
#include "JsonCom.h"

JsonComSerial jsonCom;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  jsonCom.setSerial(&Serial);
  jsonCom.init();

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  jsonCom.task();
  jsonCom.readVariable(blinkTime);
  
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(blinkTime);
}