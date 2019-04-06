#include <Arduino.h>
int solenoidPin1 = 4;
int solenoidPin2 = 5;
int buttonPin = 2;

unsigned long solenoidTimer1 = 0;
unsigned long solenoidTimer2 = 0;
int solenoidInterval1 = 0;
int solenoidInterval2 = 0;
int solenoidState1 = 0;
int solenoidState2 = 0;
int reverseSolenoids = false;

int buttonState = 0;
int buttonPresses = 0;
int newPress = true;
int intervalAfterClick = 500;
int activated = false;
int instruction = 0;
unsigned long noExtraClicks = 0;
unsigned long buttonWasClicked = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(solenoidPin1, OUTPUT);
  pinMode(solenoidPin2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

//If no clicks are registered for 500ms then send instruction (number of clicks)
int noActivitySincePress()
{
  if (millis() >= (buttonWasClicked + intervalAfterClick))
  {
    return true;
  }
  else
  {
    return false;
  }
}

//add a small amount of time after clicks so that extra clicks aren't registered
void stopTheClicks()
{
  noExtraClicks = millis() + 50;
}

// I made a mistake somewhere and LOW and HIGH for the button seemed to be backwards.
// A bunch of conditions to make sure extra clicks aren't counted as clicks
// and also to allow 500ms after each click to click again and increase the total number of clicks
// buttonPresses is only sent as an instruction to the player if no clicks are received for 500ms after
// the last click.
void buttonPressed()
{
  if (buttonState == HIGH)
  {
    reverseSolenoids = false;
  }
  buttonState = digitalRead(buttonPin);
  //check if button is pressed and if button was not pressed since last press
  if ((buttonState == LOW) && (newPress == true) && (millis() > noExtraClicks))
  {
    buttonPresses++;
    newPress = false;
    stopTheClicks();
    buttonWasClicked = millis();
    activated = true;
    Serial.println("buttonClicked");
  }
  // if it is not pressed change newPress to true so that next press can increment buttonPresses
  if ((buttonState == HIGH) && (millis() > noExtraClicks))
  {
    newPress = true;
    stopTheClicks();
    //Serial.println("button not clicked");
  }
  // check for recent activity of if there have been 5 clicks send the value 5 immediately
  if ((activated == true) && (noActivitySincePress() == true) || (buttonPresses == 5))
  {
    instruction = buttonPresses;
    Serial.println(buttonPresses);
    activated = false;
    buttonPresses = 0;
    if (buttonState == LOW)
    {
      reverseSolenoids = true;
    }
  }
}

//select rhythmic pattern based on number of clicks
void solenoidRhythms()
{
  if (instruction == 1)
  {
    solenoidInterval1 = random(10, 30);
    solenoidInterval2 = random(40, 50);
  }
  if (instruction == 2)
  {
    solenoidInterval1 = random(100, 300);
    solenoidInterval2 = random(10, 50);
  }
  if (instruction == 3)
  {
    solenoidInterval1 = random(1000, 3000);
    solenoidInterval2 = random(5, 20);
  }
  if (instruction == 4)
  {
    solenoidInterval1 = random(300, 600);
    solenoidInterval2 = random(1000, 2000);
  }
  if (instruction == 5)
  {
    solenoidInterval1 = random(600, 1400);
    solenoidInterval2 = random(1000, 1020);
  }
}

//Switching from HIGH to LOW state
int stateSwitcher(int solenoidState)
{
  if (solenoidState == HIGH)
  {
    return LOW;
  }
  else
  {
    return HIGH;
  }
}

//Setup separate timers for rhythms and reverse solenoid signals if reverseSolenoids == true
void play()
{
  if (reverseSolenoids == true)
  {
    reverseSolenoids = solenoidInterval1;
    solenoidInterval1 = solenoidInterval2;
    solenoidInterval2 = reverseSolenoids;
    reverseSolenoids = true;
  }
  if (millis() > solenoidTimer1 + solenoidInterval1)
  {
    solenoidState1 = stateSwitcher(solenoidState1);
    solenoidTimer1 = millis();
    digitalWrite(solenoidPin1, solenoidState1);
  }
  if (millis() > solenoidTimer2 + solenoidInterval2)
  {
    solenoidState2 = stateSwitcher(solenoidState2);
    solenoidTimer2 = millis();
    digitalWrite(solenoidPin2, solenoidState2);
  }
}

void loop()
{
  buttonPressed();
  solenoidRhythms();
  play();
}
