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

void doHome(int fd)
{
	float x,y;
	int signature = -1;

	// check if pixy detects objects
	// if no object was detected, move on
	if (pixy(&signature, &x, &y) < 0)
	{

	}
	else
	{
		// locate closest object
		getClosest();
		driveOff();
		collection(fd,signature);
		delay(3000);

		// use distance sensors to return to reference position
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

void doCorner(int fd)
{
	// grid quandrant

	// repeat similarly to doHome but with different positioning in mind
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
