#include <Arduino.h>
#include <Servo.h>
int i = 0; //our servo position value
int x = 0;
Servo myServo; //create an instance of the servo class
//12 servo objects

void setup()
{
  myServo.attach(3);
  Serial.begin(9600);
}

void loop()
{

  while (Serial.available() > 0)
  {
    int inChar = Serial.read();
    if (isDigit(inChar))
    {
      //add this character to our string of characters
      inString += char(inChar);
    }
    if (inChar == '\n')
    {
      delayTime = inString.toInt(); //convert from "1""3""3" to 133
      inString = "";
    }
  }

  //slowly move from 0 to 180 degrees
  for (i = 0; i < 180; i++)
  {
    myServo.write(i);
    delay(delayTime);
  }

  for ()

  // myServo.write(45); //move the servo to "45 degrees"
  // delay(1000);
  // myServo.write(120);
  // delay(1000);
}