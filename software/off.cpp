#include "drive.h"
#include "elevator.h"
#include "pins.h"
#include "colorSensor.h"
#include "pi2Arduino.h"

int main (int argc, char * argv[])
{
	int fd;
//	fd = arduinoSetup();



	driveSetup();
	eleSetup();

	driveOff();
	return 0;
}
