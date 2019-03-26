#include "drive.h"
#include "elevator.h"
#include "pins.h"

int main (int argc, char * argv[])
{
	eleSetup();
	driveSetup();

	driveOn();
	driveForward(500);
/*	turnRight(500);
	delay(500);
	strafeLeft(750);
	delay(500);
	strafeRight(750);
*/	driveOff();
	return 0;

	turnLeft(5000);

	driveOff();

	return 0;
}
