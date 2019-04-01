#include <Arduino.h>
#include <Tone.h>

Tone tone1;
Tone tone2;
Tone tone3;

void setup()
{
  tone1.begin(8);
  tone2.begin(9);
  tone3.begin(10);
}

void loop()
{
  tone1.play(100);
  tone2.play(200);
  tone3.play(400);

  tone1.play(1000);
  tone2.play(1000);
  tone3.play(1000);
  Serial.println(millis());
}
