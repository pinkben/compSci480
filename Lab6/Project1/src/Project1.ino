/**** 
Name: Lab6/Project1 
Author: Ben Pink
Description: Your Description Here 
Bugs: A list here (or "none that I know of", if that is the case) 
Reflection: A short discussion of how you found this assignment 
****/ 

#include "HC_SR04.h"

int button = D3;
int trigPin = D4;
int echoPin = D5;
double inches = 0.0;
int buttonTimer;
HC_SR04 rangeFinder = HC_SR04(trigPin, echoPin);

void setup() {
  pinMode(button, INPUT_PULLUP);
  buttonTimer = Time.now();
}

void loop() {
  if (digitalRead(button) == LOW && Time.now() - buttonTimer < 1)
  {
    buttonTimer--;
    inches = rangeFinder.getDistanceInch();
    delay(50);
    if (inches <= 24)
    {
      Particle.publish("Close_Contact", String(inches), PRIVATE);
    }
  }
  else
  {
    buttonTimer = Time.now();
  }
}