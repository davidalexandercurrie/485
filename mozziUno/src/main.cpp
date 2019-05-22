#include <Arduino.h>
#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/triangle_analogue512_int8.h> // wavetable
#include <tables/cos2048_int8.h>              // wavetable
#include <AudioDelay.h>
#include <mozzi_midi.h> // for mtof

#define CONTROL_RATE 256 // Hz, powers of 2 are most reliable

Oscil<TRIANGLE_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aTriangle(TRIANGLE_ANALOGUE512_DATA);
Oscil<COS2048_NUM_CELLS, CONTROL_RATE> kFreq(COS2048_DATA);

AudioDelay<256> aDel;
int del_samps;

void setup()
{
  aTriangle.setFreq(mtof(60.f));
  kFreq.setFreq(.63f);
  startMozzi(CONTROL_RATE);
}

void loop()
{
  audioHook();
}

void updateControl()
{
  del_samps = 128 + kFreq.next();
}

int updateAudio()
{
  char asig = aDel.next(aTriangle.next(), del_samps);
  return (int)asig;
}