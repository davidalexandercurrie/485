#include <Arduino.h>

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 12 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int counter = 0;
int mode = 0;

int SineValues[256]; // an array to store our values for sine

void setup()
{
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
  // END of Trinket-specific code.
  Serial.begin(115200);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  //AUDIO
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
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++)
  { // For each pixel...
    if (counter % 5 == 1)
    {
      pixels.setPixelColor(((i * 7) % 24), pixels.Color(41, 51, 155));
    }
    if (counter % 5 == 2)
    {
      pixels.setPixelColor(((i * 7) % 24), pixels.Color(116, 164, 188));
    }
    if (counter % 5 == 3)
    {
      pixels.setPixelColor(((i * 7) % 24), pixels.Color(182, 214, 204));
    }
    if (counter % 5 == 4)
    {
      pixels.setPixelColor(((i * 7) % 24), pixels.Color(241, 254, 198));
    }
    if (counter % 5 == 0)
    {
      pixels.setPixelColor(((i * 7) % 24), pixels.Color(255, 58, 32));
    }
    pixels.show(); // Send the updated pixel colors to the hardware.
  }
  counter++;

  //AUDIO
  for (int i = 0; i < 256; i++)
    dacWrite(25, SineValues[i]);
}
