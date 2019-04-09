#include "drive.h"
#include "elevator.h"
#include "pins.h"
#include "colorSensor.h"
#include "pi2Arduino.h"
#include <time.h>

#define RED 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3

// time threshold in seconds
#define time_thresh 120

int main (int argc, char * argv[])
{
	// time variables
	long int start_time;
	long int match_time;
	struct timespec get_time;

	int i = 0;
	base = 0;

	int fd;

	// setup pins, disable drive
	driveSetup();
	driveOff();

	fd = arduinoSetup();

	// busy wait for start button

	// start timer
	clock_gettime(CLOCK_REALTIME, &get_time);
	start_time = get_time.tv_sec;

	// read home base color from color sensor
	Sensor rgb;
	unsigned int red = rgb.readRed();
	unsigned int green = rgb.readGreen();                
	unsigned int blue = rgb.readBlue();

	// determine colors based on treshold
	// red: 255-0-0
	// yellow: 255-255-0
	// blue: 0-0-255
	// green: 0-255-0

	if (red > 200 && green < 50 && blue < 50)
	{
		base = RED;
	}
	else if (red > 200 && green > 200 && blue < 50)
	{
		base = YELLOW;
	}
	else if (red < 50 && green < 50 && blue > 200)
	{
		base = BLUE;
	}
	else if (red < 50 && green > 200 && blue < 50)
	{
		base = GREEN;
	}
	else
	{
		base = -1;
	}

	printf("%d\n", base);

	clock_gettime(CLOCK_REALTIME, &get_time);
	match_time = get_time.tv_sec - start_time;

	for (i = 0; (i < 3) && (match_time < time_thresh); i++)
	{
		if (i == 0)
		{
			// move from home base function
			// fromHome();

			// do corner at starting orientation
			// doHome();

			// move to next corner
			// moveCorner();
		}
		else
		{
			// do corner
			// doCorner(base);

			// move to next corner
			// moveCorner();
		}
		clock_gettime(CLOCK_REALTIME, &get_time);
		match_time = get_time.tv_sec - start_time;
	}

	// after collecting in all zones, start drop off process
	if (match_time > time_thresh)
	{
		for (i = 0; (i < 3) && (match_time < time_thresh); i++)
		{
			// move corner
			// moveCorner();
	
			// go to base
			// toBase();
	
			// drop off
			// dumpBase at home will raise the flag
			// dumpBase(base+i);
	
			clock_gettime(CLOCK_REALTIME, &get_time);
			match_time = get_time.tv_sec - start_time;
	
			arduinoClose(fd);
			return 0;
		}
	}

	if (match_time < time_thresh)
	{
		// go home from anywhere in field
		// goHome(i);

		arduinoClose(fd);
		return 0;
	}

/*
	int fd;
//	fd = arduinoSetup();

	driveSetup();
	eleSetup();

	driveOn();
//	driveForward(1000);
	strafeRight(1600);
//	strafeLeft(1600);
	turnRight(1000);
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
*/
	return 0;
}
