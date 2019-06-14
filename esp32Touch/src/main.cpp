#include <Arduino.h>

//Digital Capacitive Touch Sensor Arduino Interfacing

#define sensorPin 33 // capactitive touch sensor - Arduino Digital pin D1

int ledPin = 2; // Output display LED (on board LED) - Arduino Digital pin D13

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop()
{
  int senseValue = digitalRead(sensorPin);
  if (senseValue == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("not touched");
  }
  delay(500);
}