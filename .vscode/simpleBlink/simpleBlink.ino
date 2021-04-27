/**
 * @file simpleBlink.ino
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "JsonCom.h"

JsonComSerial jsonCom;
int blinkTime = 500;

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