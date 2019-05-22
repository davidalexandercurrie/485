#include <Arduino.h>

// GOAL: Send MIDI from the PC, blink and LED on the Teensy

void setup()
{
  //associate a callback with a MIDI noteOn message
  //WHEN a noteOn arrives, wee'll call a particular function
  usbMIDI.setHandleNoteOn(OnNoteOn); //OnNoteOn() gets called when a NoteOn message arrives
}

void loop()
{
  usbMIDI.read();
}

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