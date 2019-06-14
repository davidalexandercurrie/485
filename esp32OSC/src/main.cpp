#include <Arduino.h>

void setup()
{
  Serial.begin(115200);

  // add callbacks...
}

void loop()
{
  Serial.print("one ");
  Serial.println(10);
  Serial.print("two ");
  Serial.println(20);
}