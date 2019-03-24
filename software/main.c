#include "drive.h"
#include "elevator.h"
#include "pins.h"

int main (int argc, char * argv[])
{
	eleSetup();
	driveSetup();

	driveOff();

//	driveForward(5000);

//	driveOff();

	return 0;
}
