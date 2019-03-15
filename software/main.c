#include "drive.h"
#include "elevator.h"

int main (int argc, char * argv[])
{
	eleSetup();
	driveSetup();

	driveForward(5000);

//	down();
return 0;
	delay(1000);
	up();
return 0;
	printf("done setup\n");
//	driveForward(800);
//	strafeLeft(2000);
	delay(1000);
	printf("done forward\n");
	driveBackward(800);
//	down();
	return 0;
}
