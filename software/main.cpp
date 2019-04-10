#include "drive.h"
#include "vision.h"
#include "pins.h"
#include "colorSensor.h"
#include "pi2Arduino.h"
#include <time.h>
#include <signal.h>

#define RED 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3

// time threshold in seconds
#define TIME_THRESH 120


void handle_SIGINT(int unused)
{
	driveOff();
	arduinoClose(fd);
	exit(0);
}

int main (int argc, char * argv[])
{
	signal(SIGINT, handle_SIGINT);

	int currentColor;

	// time variables
	long int start_time;
	long int match_time;
	struct timespec get_time;

	int i,j;
	int base;

	int fd;

	// setup
	printf("BEGINNING SETUP...\n");
	driveSetup();
	fd = arduinoSetup();
	printf("SETUP FINISHED\n\n");
	
	// busy wait for start button
	printf("BUSY WAIT...\n");

	// start timer
	clock_gettime(CLOCK_REALTIME, &get_time);
	start_time = get_time.tv_sec;
	printf("MATCH STARTED\n");

	
	// read home base color from color sensor
	int base;
	Sensor rgb;
	unsigned int red = rgb.readRed();
	unsigned int green = rgb.readGreen();                
	unsigned int blue = rgb.readBlue();

	// determine colors based on treshold
	// red: 255-0-0
	// yellow: 255-255-0
	// blue: 0-0-255
	// green: 0-255-0

	printf("READING COLOR...\n");
	if (red > 200 && green < 50 && blue < 50)
	{
		base = RED;
		printf("HOME BASE IS RED\n");
	}
	else if (red > 200 && green > 200 && blue < 50)
	{
		base = YELLOW;
		printf("HOME BASE IS YELLOW\n");
	}
	else if (red < 50 && green < 50 && blue > 200)
	{
		base = BLUE;
		printf("HOME BASE IS BLUE\n");
	}
	else if (red < 50 && green > 200 && blue < 50)
	{
		base = GREEN;
		printf("HOME BASE IS GREEN\n");
	}
	else
	{
		printf("UNABLE TO DETERMINE HOME BASE...GUESSING 0\n");
		base = 0;
		// NEED TO GUESS A HOME BASE HERE
		// maybe make a note not to bother dropping off though
	}

	printf("R = %d\n", red);
	printf("G = %d\n", green);
	printf("B = %d\n", blue);

	clock_gettime(CLOCK_REALTIME, &get_time);
	match_time = get_time.tv_sec - start_time;

	printf("STARTING NAVIGATION\n");
	for (i = 0; (i < 4) && (match_time < TIME_THRESH); i++)
	{
		currentColor = (i + base) % 4;
		if (currentColor == base)
		{
			printf("STARTING HOME BASE (%d)\n",currentColor);
			
			// move from home base function
			printf("MOVING FROM HOME...\n");
			// fromHome();

			// do corner at starting orientation
			printf("DOING HOME CORNER...\n");
			// doHome();

			// move to next corner
			printf("MOVING TO NEXT CORNER\N");
			// moveCorner();
		}
		else
		{
			printf("STARTING CORNER (%d)\n",currentColor);
			
			// do corner
			printf("DOING CORNER...\n");
			// doCorner(base);

			// move to next corner
			printf("MOVING TO NEXT CORNER\N");
			// moveCorner();
		}
		clock_gettime(CLOCK_REALTIME, &get_time);
		match_time = get_time.tv_sec - start_time;
	}

	// after collecting in all zones, start drop off process
	if (match_time < TIME_THRESH)
	{
		printf("HAVE ENOUGH TIME TO DROP OFF...\n");
		for (j = 0; (j < 4) && (match_time < TIME_THRESH); i++)
		{
			j++;
			currentColor = (i + base) % 4;
			
			if (currentColor != base)
			{
				// go to base
				printf("GOING TO BASE %d\n");
				// toBase();
				
				// drop off
				// dumpBase at home will raise the flag
				// dumpBase(base+i);
			}
			
			// move corner
			printf("MOVING TO NEXT CORNER\N");
			// moveCorner();
	
			clock_gettime(CLOCK_REALTIME, &get_time);
			match_time = get_time.tv_sec - start_time;
	
			arduinoClose(fd);
			return 0;
		}
	}

	clock_gettime(CLOCK_REALTIME, &get_time);
	match_time = get_time.tv_sec - start_time;
	// go home from anywhere in field
	printf("GOING HOME...TIME: %ld\n",match_time);
	// goHome(i);
	
	printf("RAISING THE FLAG\n");
	// dumpBase at home will raise the flag
	// dumpBase(base+i);
	
	printf("DONE.\n");
	arduinoClose(fd);
	return 0;
}
