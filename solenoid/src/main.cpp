#include <Arduino.h>
int solenoidPin = 4;
int solenoidPin2 = 5;
void setup()
{
  // put your setup code here, to run once:
  pinMode(solenoidPin, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(solenoidPin, HIGH);
  digitalWrite(solenoidPin, LOW);
  delay(500);
  digitalWrite(solenoidPin, LOW);
  digitalWrite(solenoidPin, HIGH);
  delay(500);
}