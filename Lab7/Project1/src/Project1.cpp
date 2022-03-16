/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/pinkb95/Desktop/CS480/compSci480/Lab7/Project1/src/Project1.ino"
/**** 
Name: Lab7/Project1 
Author: Ben Pink
Description: Your Description Here 
Bugs: A list here (or "none that I know of", if that is the case) 
Reflection: A short discussion of how you found this assignment 
****/ 

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void setup();
void loop();
#line 14 "/Users/pinkb95/Desktop/CS480/compSci480/Lab7/Project1/src/Project1.ino"
int buttonA = A2;
int buttonB = D2;
int aButtonTimer;
int bButtonTimer;

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
  aButtonTimer = Time.now(); 
  bButtonTimer = Time.now();
}


void loop() {
  // Button A pressed
  if (digitalRead(buttonA) == LOW && digitalRead(buttonB) != LOW)
  {
    if(Time.now() - aButtonTimer < 1)
    {
      aButtonTimer--;
    }
  }
  // Button B Pressed
  else if (digitalRead(buttonB) == LOW && digitalRead(buttonA) != LOW)
  {
    if(Time.now() - bButtonTimer < 1)
    {
      bButtonTimer--;
    }
  }
  // Both buttons pressed
  else if (digitalRead(buttonA) == LOW && digitalRead(buttonB) == LOW)
  {
    if((Time.now() - aButtonTimer < 1) && (Time.now() - bButtonTimer < 1))
    {
      aButtonTimer--;
      bButtonTimer--;
    }

  }
  // No buttons pressed
  else
  {
    aButtonTimer = Time.now();
    bButtonTimer = Time.now();
  }

}