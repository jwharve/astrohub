#include "drive.h"
#include "elevator.h"
#include "pins.h"

int main (int argc, char * argv[])
{
	eleSetup();
	driveSetup();

	driveForward(5000);

	return 0;
}
