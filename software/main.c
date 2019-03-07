#include "drive.h"
#include "elevator.h"

int main (int argc, char * argv[])
{
	eleSetup();
	driveSetup();
	printf("done setup\n");

	up();
	return 0;
	driveForward(800);
	driveBackward(800);
	return 0;

	up();
	delay(1000);
//	dropFront();
	delay(1000);
	down();
	return 0;

	up();
	printf("done up\n");
	delay(1000);
return 0;
	down();
	printf("done down\n");
	return 0;
	driveForward(1000);
	printf("done forward\n");
	driveBackward(1000);
	printf("done backward\n");
	strafeRight(1000);
	printf("done right\n");
	strafeLeft(1000);
	printf("done left\n");

	return 0;
}
