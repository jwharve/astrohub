#include "drive.h"
#include "vision.h"
#include "pins.h"
#include "colorSensor.h"
#include "pi2Arduino.h"
#include "pickup.h"
#include "game.h"
#include <time.h>
#include <signal.h>

// time threshold in seconds
#define TIME_THRESH 120

int fd;

void handle_SIGINT(int unused)
{
	driveOff();
	elUp(fd);
	raiseFlag(fd);
	arduinoClose(fd);
	exit(0);
}

int main (void)
{
	signal(SIGINT, handle_SIGINT);

	int currentColor;

	// time variables
	long int start_time;
	long int match_time;
	struct timespec get_time;

	int i,j;
	int base;

	Sensor rgb;
	unsigned int red;
	unsigned int green;
	unsigned int blue;

	// setup
	printf("<%3ld> BEGINNING SETUP...\n", -1);
	driveSetup();
	proxInit();
	fd = arduinoSetup();

	pullUpDnControl (START_PIN, PUD_DOWN);

	pinMode(START_PIN,INPUT);
	elDown(fd);
	printf("<%3ld> SETUP FINISHED\n\n", -1);

	// busy wait for start button
	printf("<%3ld> BUSY WAIT...\n", -1);
	while(digitalRead(START_PIN) == 0);

	// start timer
	clock_gettime(CLOCK_REALTIME, &get_time);
	start_time = get_time.tv_sec;
	printf("<%ld> MATCH STARTED\n", 0);

	// read home base color from color sensor
	red = rgb.readRed();
	green = rgb.readGreen();
	blue = rgb.readBlue();
	// determine colors based on treshold
	// red: 255-0-0
	// yellow: 255-255-0
	// blue: 0-0-255
	// green: 0-255-0

	clock_gettime(CLOCK_REALTIME, &get_time);
	match_time = get_time.tv_sec - start_time;
	printf("<%3ld> READING COLOR...\n", match_time);
	if (red > 30000 && green < 30000 && blue < 30000)
	{
		base = RED;
		printf("<%3ld> HOME BASE IS RED\n", match_time);
	}
	else if (red > 30000 && green > 30000 && blue < 30000)
	{
		base = YELLOW;
		printf("<%3ld> HOME BASE IS YELLOW\n", match_time);
	}
	else if (red < 30000 && green < 30000 && blue > 30000)
	{
		base = BLUE;
		printf("<%3ld> HOME BASE IS BLUE\n", match_time);
	}
	else if (red < 30000 && green > 30000 && blue < 30000)
	{
		base = GREEN;
		printf("<%3ld> HOME BASE IS GREEN\n", match_time);
	}
	else
	{
		printf("<%3ld> UNABLE TO DETERMINE HOME BASE...\n", match_time);
		base = BLUE;

		// if base is -1, do not drop off
	}

	clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
	printf("<%3ld> R = %d\n", match_time, red);
	printf("<%3ld> G = %d\n", match_time, green);
	printf("<%3ld> B = %d\n", match_time, blue);

	clock_gettime(CLOCK_REALTIME, &get_time);
	match_time = get_time.tv_sec - start_time;

	printf("<%3ld> STARTING NAVIGATION\n", match_time);
	i = 0;
	for (i = 0; (i < 4) && (match_time < TIME_THRESH); i++)
	{
		currentColor = (i + base) % 4;
		if (currentColor == base)
		{
			clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
			printf("<%3ld> STARTING HOME BASE (%d)\n", match_time, currentColor);

			// move from home base function
			clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
			printf("<%3ld> MOVING FROM HOME...\n", match_time);
			fromHome(fd);

			// do corner at starting orientation
			clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
			printf("<%3ld> DOING HOME CORNER...\n", match_time);
			doCorner(fd);

			// move to next corner
			clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
			printf("<%3ld> MOVING TO NEXT CORNER\n", match_time);
			moveCorner(fd);
		}
		else
		{
			clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
			printf("<%3ld> STARTING CORNER (%d)\n", match_time, currentColor);

			// do corner
			clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
			printf("<%3ld> DOING CORNER...\n", match_time);
			doCorner(fd);

			// move to next corner
			clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
			printf("<%3ld> MOVING TO NEXT CORNER\n", match_time);
			moveCorner(fd);
		}
		clock_gettime(CLOCK_REALTIME, &get_time);
		match_time = get_time.tv_sec - start_time;
	}

//	if (match_time >= TIME_THRESH)
//	{
		for (j = 0; j < 4 && match_time < 150; i++)
		{
			j++;
			currentColor = (i + base) % 4;
			if (currentColor != base)
			{
				moveCorner(fd);
			}
			else
			{
				toBase(fd);
				break;
			}
			clock_gettime(CLOCK_REALTIME, &get_time);
			match_time = get_time.tv_sec - start_time;
		}

		if (match_time >= 150)
		{
			driveForward(2000);
		}
//	}

/*
	// after collecting in all zones, start drop off process
	if (match_time < TIME_THRESH)
	{
		printf("<%3ld> HAVE ENOUGH TIME TO DROP OFF...\n", match_time);
		for (j = 0; (j < 4) && (match_time < TIME_THRESH); i++)
		{
			j++;
			currentColor = (i + base) % 4;

			// move corner
			clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
			printf("<%3ld> MOVING TO NEXT CORNER\n", match_time);
			// moveCorner();

			if (currentColor != base)
			{
				// go to base
				clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
				printf("<%3ld> GOING TO BASE %d\n", match_time, currentColor);
				// toBase();

				// drop off
				// dumpBase at home will raise the flag
				// dumpBase(base+i);
			}

			clock_gettime(CLOCK_REALTIME, &get_time);
			match_time = get_time.tv_sec - start_time;
		}
	}

	// go home from anywhere in field
	clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
	printf("<%3ld> GOING HOME...TIME: %ld\n",match_time, match_time);
	// goHome(i);

	clock_gettime(CLOCK_REALTIME, &get_time); match_time = get_time.tv_sec - start_time;
	printf("<%3ld> RAISING THE FLAG\n", match_time);
	// dumpBase at home will raise the flag
	// dumpBase(base+i);
*/
	printf("<%3ld> DONE.\n", match_time);
	elUp(fd);
	raiseFlag(fd);
	arduinoClose(fd);
	return 0;
}
