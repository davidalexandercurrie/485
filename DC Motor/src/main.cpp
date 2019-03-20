#include <Arduino.h>

void setup()
{
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int speed = 0;
  analogWrite(6, speed);
  delay(1000);
  Serial.println(speed);
}