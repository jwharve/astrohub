#include "game.h"
#include "drive.h"

#define RED 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3

#define MIDDLE 55

void fromHome(int fd)
{
	// starting at home position

	// strafe left until edge of zone 2
	driveOn();
	strafeLeft((int)(LR_TO_STEP*MIDDLE));
	straighten(fd);

	// drive to wall
	float a = distance3(fd);
	if ( a > 5)
	{
		driveBackward((int)((a-5)*FB_TO_STEP));
	}

	driveOff();
}

void doCorner(int fd)
{
	int x_steps = 0;
	int y_steps = 0;

	int x_current = 0;
	int y_current = 0;

	int i = 0;
	int pixyReturn = 0;

	float x, y;
	int signature = -1;

	float dist = 0;
	dist = distance3(fd);

	while (dist > 190)
	{
		// get current location
		x_current = distance1(fd);
		y_current = distance3(fd);

		// get location of first object
		pixyReturn = pixy(&signature, &x, &y);

		i = 1;
		while (pixyReturn > 0)
		{		
			if ((dead_zone(x,y)))
			{
				pixyReturn = pixyIgnore(&signature, &x, &y, i);
				i++;
			}
			else
			{
				break;
			}
		}

		if (!(dead_zone(x,y)))
		{
			signature = getClosest(&x_steps, &y_steps, i-1);
			collection(fd, signature);

			// wiat until collection is good
			arduinoGetChar();

			// center robot
			center(fd);	

			driveOn();
			driveBackward((int)(FB_TO_STEP*10));
			driveOff();
		}
		else
		{
			driveOn();
			driveForward((int)(FB_TO_STEP*40));
			driveOff();
		}
		dist = distance3(fd);
	}
}

void moveCorner(int fd)
{
	float a = distance3(fd);

	if (a < 190)
	{
		driveOn();
		driveForward((int)(FB_TO_STEP*(190-a)));
		driveOff();
	}

	driveOn();
	// turn left 90 degrees
	turnLeft(NINETY);

	// center robot
	center(fd);

	a = distance3(fd);
	// drive backward to wall
	if (a > 5)
	{
		driveBackward((int)((a-5)*FB_TO_STEP));
	}
}

void toBase(int fd)
{
	// whatever quandrant you are currently in, go to that base
}

void dumpBase(int fd, int location)
{
	// open the doors for the corresponding color
}

void goHome(int fd, int base, int current)
{
	// whereever the robot currently is,
}

void go(float x, float y, int fd)
{
	float currX, currY;
	float dX, dY;

	driveOn();
	straighten(fd);
	currX = distance1(fd);
	currY = distance3(fd);

	dX = currX - x;
	dY = currY - y;

	if (dX < 0)
	{
		strafeLeft((int)(-dX*LR_TO_STEP));
	}
	else if (dX > 0)
	{
		strafeRight((int)(dX*LR_TO_STEP));
	}

	if (dY < 0)
	{
		driveForward((int)(-dY*LR_TO_STEP));
	}
	else if (dY > 0)
	{
		driveBackward((int)(dY*LR_TO_STEP));
	}
}
