#include <Arduino.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform waveform1;  //xy=297,488
AudioEffectEnvelope envelope1; //xy=480,485
AudioOutputAnalog dac1;        //xy=755,656
AudioConnection patchCord1(waveform1, envelope1);
AudioConnection patchCord2(envelope1, dac1);
// GUItool: end automatically generated code

void setup(void)
{

  // Set up
  AudioMemory(8);

  waveform1.pulseWidth(0.5);
  waveform1.begin(0.4, 220, WAVEFORM_PULSE);

  envelope1.attack(50);
  envelope1.decay(50);
  envelope1.release(250);
}

void loop()
{

  float w;
  for (uint32_t i = 1; i < 20; i++)
  {
    w = i / 20.0;
    waveform1.pulseWidth(w);
    envelope1.noteOn();
    delay(800);
    envelope1.noteOff();
    delay(600);
  }
}
