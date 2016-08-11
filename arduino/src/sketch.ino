#include "axisDirectionStruct.h" //importing AxisAndDirection 
#define led 13
int incomingByte = 0;   // for incoming serial data
bool flag = false;

void setup()
{
	pinMode(led,OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	if (Serial.available()){
		//incoming data is stored in buffer. Serial.reads reads 1 byte from it. if not read, code under Serial.available will be executed with every spin cycle. 
		incomingByte = Serial.parseInt();
		AxisAndDirection axisAndDirection = getAxisAndDirection(incomingByte);
		if(axisAndDirection.axis == 'x') {

			bool ledStatus = false;
			ledStatus = toggle_led();
			//Serial.print(ledStatus);
			digitalWrite(led, ledStatus);
		}
		Serial.print(axisAndDirection.axis);
		Serial.print(axisAndDirection.direction);
	}
}

AxisAndDirection getAxisAndDirection(int incomingByte){
	switch(incomingByte) {
		case 1:
			return {'x', 1};
			break;
		case 2:
			return {'x', -1};
			break;
		case 3:
			return {'y',1};
			break; 
		case 4:
			return {'y',-1};
			break; 
		default:
			return {'A',0};
			break; 
	}
}

bool toggle_led() {
	flag = !flag;
	return flag;
}
