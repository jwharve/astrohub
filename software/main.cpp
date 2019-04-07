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

	driveOn();
	strafeRight(1600);
	strafeLeft(1600);
	driveOff();
	return 0;

	down();
	collection(fd);
	delay(3000);

	up();

	dropFront();

	return 0;

	collection(fd);

	dropRight();
	delay(250);
	dropLeft();
	delay(250);
	dropFront();
	delay(250);
	dropBack();

	return 0;
	down();
	collection(fd);
	delay(3000);
	up();
	dropRight();
	dump1(fd);
	dump2(fd);
	dump3(fd);

	printf("%f\n",distance1(fd));
	printf("%f\n",distance2(fd));
	printf("%f\n",distance3(fd));


	driveOn();
//	turnRight(1000);
//	strafeRight(600);
//	driveBackward(1000);
//	delay(1000);
//	driveForward(1000);
	driveOff();


	return 0;

//	down();return 0;

	driveOff();

	//singleMove(FRR, 100, 1);
	//singleMove(FRL, 100, 1);
	//singleMove(RRR, 100, 1);
	//singleMove(RRL, 100, 1);

	//return 0;

	//down();
	//up();
	collection(fd);
	delay(3000);

	up();

//	dumpRight();
	return 0;

	driveOn();
//	driveForward(500);
//	turnRight(500);
	delay(500);
	strafeLeft(750);
	delay(500);
	strafeRight(750);
	driveOff();

	turnLeft(5000);

	driveOff();

	collection(fd);
	dump1(fd);
	dump2(fd);
	dump3(fd);

	return 0;
	Sensor rgb;
	unsigned int red = rgb.readRed();
	unsigned int green = rgb.readGreen();                
	unsigned int blue = rgb.readBlue();
	

	return 0;
}
