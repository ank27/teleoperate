#include <Arduino.h>
#include "AccelStepper.h"
#include "axisDirectionStruct.h" //importing AxisAndDirection
#define STEPPER_STEP_PIN 2
#define STEPPER_DIR_PIN 3
#define led_pin 13
enum Direction { FORWARD, BACKWORD } direction;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void blockingRunSpeedToPosition(int direction);

AccelStepper stepper(AccelStepper::DRIVER, STEPPER_STEP_PIN, STEPPER_DIR_PIN);


void setup()
{
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  stepper.setMaxSpeed(200.0);
  stepper.setAcceleration(100);
}

void loop()
{
  // print the string when a newline arrives:
  if (stringComplete) {
      Serial.println(inputString);
      // clear the string:
      inputString.trim();
      Serial.println(inputString.length());
      if(inputString == "x") {
          direction = FORWARD;
          blockingRunSpeedToPosition(direction);
      } else if (inputString == "-x") {
          direction = BACKWORD;
          blockingRunSpeedToPosition(direction);
      }

      inputString = "";
      stringComplete = false;

    }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
 void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void blockingRunSpeedToPosition(int direction)
{
  /*
     runSpeedToPosition is non blocking.
     You must call this as frequently as possible, but at least once per step interval,
     But we want blocking so we have to implement own loop using while
   */
   Serial.println("got x");
   stepper.setCurrentPosition(0);

   ///stepper.move funtion : Set the target position relative to the current position
   /// if position is negative then anticlockwise from the current position, else clockwise from current position
   int steps = 200;
   if(direction == BACKWORD) {
       steps = -steps;
   }
   stepper.move(steps);
   while (stepper.distanceToGo() != 0) {
        // stepper.runSpeedToPosition();
        stepper.run();
    }
}
