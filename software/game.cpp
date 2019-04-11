#include "game.h"

#define RED 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3

void fromHome(int fd)
{
	// starting at home position

	// strafe left until edge of zone 2
	strafeLeft(2000);
	straighten(fd);

	// after this doHome will start the process of gridding
}

void doCorner(int fd)
{
	int i = 0;
	double int homing_x = 0;
	double int homing_y = 0;
	int x_steps = 0;
	int y_steps = 0;

	float x, y;
	int signature = -1;

	for (i = 0; i < 3; i++)
	{

		// check if pixy detects objects
		// if no object was detected, move on
		if (pixy(&signature, &x, &y) < 0)
		{
			;
		}
		else
		{
			// locate closest object
			getClosest(&x_steps, &y_steps);
			collection(fd,signature);
			delay(3000);
	
			// return to reference position
			if (x_steps > 0)
			{
				strafeLeft(homing_x);
			}
			else if (x_steps < 0)
			{
				strafeRight(-1*homing_x);
			}
			
			straighten();

			if (y_steps > 0)
			{
				driveBackward(homing_y);
			}
			else if (y_steps < 0)
			{
				driveForward(-1*homing_y);
			}
		}
	}

	// stop when done
}

void moveHome(int fd)
{
	// same as move corner but no turn
}

void moveCorner(int fd)
{
	// turn left 90 degrees

	// strafe to center robot in quandrant

	// drive forward until on line conneting next quadrant

	// strafe left to get to the side
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
