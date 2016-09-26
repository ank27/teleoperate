#include "AccelStepper.h"
#include "axisDirectionStruct.h" //importing AxisAndDirection 

String incomingByte;   // for incoming serial data
int speed = 20;
// The X Stepper pins
#define STEPPER_DIR_PIN 10
#define STEPPER_STEP_PIN 2
#define led_pin 13

// Define some stepper and the pins the will use
//AccelStepper::DRIVER means that we are using Driver, or we can write simply "1"
AccelStepper stepper(AccelStepper::DRIVER, STEPPER_STEP_PIN, STEPPER_DIR_PIN);

void setup()
{
    Serial.begin(9600);
    pinMode(led_pin, OUTPUT);
    stepper.setMaxSpeed(40);
}

void blockingRunSpeedToPosition(long position)
{
    /*
       runSpeedToPosition is non blocking.
       You must call this as frequently as possible, but at least once per step interval,		
       But we want blocking so we have to implement own loop using while
     */

    stepper.setCurrentPosition(0);

    ///stepper.moveTo function : Set the target position absolute to the current position
    //  stepper.moveTo(position);

    ///stepper.move funtion : Set the target position relative to the current position
    /// if position is negative then anticlockwise from the current position, else clockwise from current position
    stepper.move(position);
    stepper.setSpeed(speed);
    while (stepper.distanceToGo() != 0)
        stepper.runSpeedToPosition();
}


void loop()
{
    while (Serial.available()==0) { }  //Wait for serial data

    incomingByte=Serial.readString();
    incomingByte.trim();

    Serial.println(incomingByte); //debugging

    AxisAndDirection axisAndDirection = getAxisAndDirection(incomingByte);

    int stepsPerKeyStrock = 200;
    if(axisAndDirection.axis == 'x') {
        digitalWrite(led_pin,HIGH);
        if(axisAndDirection.direction == -1) {
            stepsPerKeyStrock = -stepsPerKeyStrock;
        }
        blockingRunSpeedToPosition(stepsPerKeyStrock);
    }else{
        digitalWrite(led_pin,LOW);
    }
}

AxisAndDirection getAxisAndDirection(String data){

    if(data.equals("x")){
        return {'x', 1};
    }else if(data.equals("x-")){
        return {'x', -1};
    }else if(data.equals("y")){
        return {'y', 1};
    }else if(data.equals("y-")){
        return {'y', -1};
    }else{
        return{'A',0};
    }
}


