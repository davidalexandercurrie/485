#include <Arduino.h>

// int SENDPIN = 21;

// void setup()
// {
//   pinMode(SENDPIN, OUTPUT);
// }

// void loop()
// {
//   digitalWrite(SENDPIN, HIGH);
//   delay(500);
//   digitalWrite(SENDPIN, LOW);
//   delay(500);
// }

// int RECEIVEPIN = 21;
// int ONOFF;

// void setup()
// {
//   pinMode(RECEIVEPIN, INPUT);
//   pinMode(BUILTIN_LED, OUTPUT);
//   Serial.begin(115200);
// }

// void loop()
// {
//   ONOFF = digitalRead(RECEIVEPIN);
//   Serial.println(ONOFF);
//   if (ONOFF == 1)
//   {
//     digitalWrite(BUILTIN_LED, HIGH);
//   }
//   else
//   {
//     digitalWrite(BUILTIN_LED, LOW);
//   }
// }

// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

#include <Wire.h>

byte x = 0;
uint8_t target = 0x66;

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop()
{
  Wire.beginTransmission(target); // transmit to device #8
  Wire.write("x is ");            // sends five bytes
  Wire.write(x);                  // sends one byte
  Wire.endTransmission();         // stop transmitting
  Serial.println("fml?");

  x++;
  delay(500);
}