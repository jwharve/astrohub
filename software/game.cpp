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
	int END_OF_COL = 0;

	int i = 0;
	float homing_x = 0;
	float homing_y = 0;
	int x_steps = 0;
	int y_steps = 0;

	float x, y;
	int signature = -1;

	for (i = 0; i < 3; i++)
	{
		END_OF_COL = 0;

		while (!END_OF_COL)
		{

			// get starting distance
			homing_x = distance1(fd);
			homing_y = distance3(fd);
	
			// check if pixy detects objects
			// if no object was detected, move on
			if (pixy(&signature, &x, &y) < 0)
			{
				driveOn();
				// drive to next position
				driveForward(2000);
				driveOff();
			
				// update new starting distance
				homing_x = distance(fd);
				homing_y = distance(fd);
		
				// don't find an object again
				if (pixy(&signature, &x, &y) < 0)
				{
					if (i != 2)
					{
						// go to next column
						driveOn();
						driveBackward(2000);
						strafeRight(3000);
					}
					END_OF_COL = 1;
				}
			}
			else
			{
				// locate closest object
				getClosest(&x_steps, &y_steps);
				collection(fd,signature);
				delay(3000);
	
				// return to reference position
				driveOn();
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
				driveOff();
	
				// check error and drive to fix
				x_steps = (LR_TO_STEPS)*(distance1(fd) - homing_x);
				y_steps = (FB_TO_STEPS)*(distance3(fd) - homing_y);
			}
		}
	}
}

void moveCorner(int fd)
{
	double x_step = 0;
	double y_step = 0;

	// center robot in quandrant
	// find steps away from center
	x_step = (LR_TO_STEPS*(65 - distance1(fd));
	y_step = (FB_TO_STEPS*(65 - distance3(fd));

	if (x_step > 0)
	{
		strafeRight(x_step);
	}
	else if (x_step < 0)
	{
		strafeLeft(-1*x_step);
	}

	straighten();

	if (y_step > 0)
	{
		driveForward(y_step);
	}
	else if (y_step < 0)
	{
		driveBackground(-1*y_step);
	}

	// drive forward until on line conneting next quadrant
	driveForward(130*FB_TO_STEPS);

	// turn left 90 degrees
	turnLeft();

	// drive backwards to wall
	driveBackground(190*FB_TO_STEPS);

	// strafe keft to doCorner() starting position
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
