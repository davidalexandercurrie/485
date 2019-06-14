#include <Arduino.h>

int SineValues[256]; // an array to store our values for sine
int counter = 0;
int counter2 = 0;
int togglePitch = 0;

void setup()
{
  float ConversionFactor = (2 * PI) / 256; // convert my 0-255 bits in a circle to radians
                                           // there are 2 x PI radians in a circle hence the 2*PI
                                           // Then divide by 256 to get the value in radians
                                           // for one of my 0-255 bits.
  float RadAngle;                          // Angle in Radians
  // calculate sine values
  for (int MyAngle = 0; MyAngle < 256; MyAngle++)
  {
    RadAngle = MyAngle * ConversionFactor;             // 8 bit angle converted to radians
    SineValues[MyAngle] = (sin(RadAngle) * 127) + 128; // get the sine of this angle and 'shift' up so
                                                       // there are no negative values in the data
                                                       // as the DAC does not understand them and would
                                                       // convert to positive values.
  }
}

void loop()
{
  int min = 800;
  int max = 850;
  if ((counter == min) || (counter == 0))
  {
    counter = min;
    togglePitch = 1;
  }
  if (counter == max)
  {
    togglePitch = 0;
  }
  int tempo = random(0, 5§);
  for (int i = 0; i < tempo; i++)
  {
    for (int i = 0; i < counter; i++)
    {
      dacWrite(25, SineValues[i]);
    }
  }
  if (togglePitch == 1)
  {
    counter++;
  }
  if (togglePitch == 0)
  {
    counter--;
  }
  counter2++;
}