#include <Arduino.h>

void setup()
{
  pinMode(6, OUTPUT);
}

void loop()
{
  int potVal = analogRead(A0);
  potVal = potVal / 4;
  analogWrite(6, potVal);
}