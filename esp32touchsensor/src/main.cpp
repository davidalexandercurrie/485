#include <Arduino.h>

#define sensorPin 33
int led = 2;
void setup()
{
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.println("TURNED ON");
}

void loop()
{
  int senseValue = digitalRead(sensorPin);
  if (senseValue == HIGH)
  {
    Serial.println("TOUCHED");
    digitalWrite(led, HIGH);
  }
  else
  {
    Serial.println("not touched");
    digitalWrite(led, LOW);
  }
  delay(500);
}