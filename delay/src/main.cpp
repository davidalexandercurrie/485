#include <Arduino.h>

int ledState = LOW;
long previousMillis = 0;
long interval = 100;

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis(); //the number of ms since the arduino started
  if (currentMillis - previousMillis > interval)
  {
    previousMillis = currentMillis;
    //switch our LED state
    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    digitalWrite(13, ledState);
  }
}