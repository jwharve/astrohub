#include "game.h"

#define RED 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3

void fromHome(int fd)
{
	// starting at home position

	// strafe left until at far side of quadrant
	strafeLeft(2000);

	// after this doHome will start the process of gridding
}

void doHome(int fd)
{
	// check if pixy detects objects

		// if so pick closest object

		// calculate distance

		// check distance sensors

		// determine if going driving to that location is a good idea
		// i.e. not in a zone that will hit a spacetel or at a location we cant pick up

			// if so, look for other objects
			// if no other objects continue gridding that column
		// for food objects
		// drive to location using distance and start collection process
		// once done, return to inital grid position to continue

	// if no objects are detected on that column, reset backwards and strafe right to next column

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
