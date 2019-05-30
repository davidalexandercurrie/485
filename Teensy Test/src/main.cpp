#include <Arduino.h>

// GOAL: Send MIDI from the PC, blink and LED on the Teensy

void OnNoteOn(byte channel, byte note, byte velocity)
{
  if (note == 60 && velocity > 0)
  {
    digitalWrite(13, HIGH); //turn on the LED
  }
}

void OnNoteOff(byte channel, byte note, byte velocity)
{
  if (note == 60)
  {
    digitalWrite(13, LOW);
  }
}

void setup()
{
  //associate a callback with a MIDI noteOn message
  pinMode(13, OUTPUT);
  //WHEN a noteOn arrives, wee'll call a particular function
  usbMIDI.setHandleNoteOn(OnNoteOn); //OnNoteOn() gets called when a NoteOn message arrives
  usbMIDI.setHandleNoteOff(OnNoteOff);
  Serial.begin(9600);
}

void loop()
{
  usbMIDI.read();
}
