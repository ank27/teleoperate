#include "AccelStepper.h"
#include "axisDirectionStruct.h" //importing AxisAndDirection 

int incomingByte = 0;   // for incoming serial data
int speed = 10;
// The X Stepper pins
#define STEPPER_DIR_PIN 3
#define STEPPER_STEP_PIN 2

// Define some stepper  and the pins the will use
AccelStepper stepper(AccelStepper::DRIVER, STEPPER_STEP_PIN, STEPPER_DIR_PIN);

void setup()
{
	Serial.begin(9600);
  pinMode(13, OUTPUT);
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
    stepper.moveTo(position);
    stepper.setSpeed(speed);
    while (stepper.distanceToGo() != 0)
      stepper.runSpeedToPosition();
}


void loop()
{
  if (Serial.available()) {
    digitalWrite(13, HIGH);     
  }

/*
	if (Serial.available()){
		//incoming data is stored in buffer. Serial.reads reads 1 byte from it. if not read, code under Serial.available will be executed with every spin cycle. 
		incomingByte = Serial.parseInt();
		AxisAndDirection axisAndDirection = getAxisAndDirection(incomingByte);
		int stepsPerKeyStrock = 100;
		if(axisAndDirection.axis == 'x') {
			if(axisAndDirection.direction == -1) {
				stepsPerKeyStrock = -stepsPerKeyStrock;
			}

			blockingRunSpeedToPosition(stepsPerKeyStrock);
		}
	}
*/
}

AxisAndDirection getAxisAndDirection(int incomingByte){
	switch(incomingByte) {
		case 1:
			return {'x', 1};
		case 2:
			return {'x', -1};
		case 3:
			return {'y',1};
		case 4:
			return {'y',-1};
		default:
			return {'A',0};
	}
}
