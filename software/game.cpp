#include "game.h"
#include "drive.h"

#define RED 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3

void fromHome(int fd)
{
	// starting at home position

	// strafe left until edge of zone 2
	driveOn();
	strafeLeft((int)(LR_TO_STEP*80));
	straighten(fd);

	float a = distance3(fd);
	if ( a > 5)
	{
		driveBackward((int)((a-5)*FB_TO_STEP));
	}

	driveOff();
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

	float currX, currY;

	// FOR EACH COLUMN
	for (i = 0; i < 2; i++)
	{
		END_OF_COL = 0;

printf("...starting column %d\n",i);

		// get starting distance
		homing_x = distance1(fd);
		homing_y = distance3(fd);

		while (!END_OF_COL)
		{
			// check if pixy detects objects
			// if no object was detected, move on
			
			if (pixy(&signature, &x, &y) < 0)
			{
printf("missed first\n");
				driveOn();
				// drive to next position
printf("drove forward\n");
				driveForward((int)(FB_TO_STEP*40));
				driveOff();

				// update new starting distance

				// don't find an object again
				if (pixy(&signature, &x, &y) < 0)
				{
					if (i != 1)
					{
						// go to next column
						driveOn();
						driveBackward((int)(FB_TO_STEP*30));
						strafeRight((int)(LR_TO_STEP*30));
					}
					END_OF_COL = 1;
				}
				else
				{
					currX = distance1(fd);
					currY = distance3(fd);
					if ((currX + x) < 120 && (currY + y) < 120)
					{
						if (getClosest(&x_steps, &y_steps) == 0)
						{
							collection(fd,signature);
						}
					}

					go(homing_x,homing_y+5,fd);

				}

			}
			else
			{
				// locate closest object
printf("got first\n");
				currX = distance1(fd);
				currY = distance3(fd);
				if ((currX + x) < 120 && (currY + y) < 120)
				{
					if (getClosest(&x_steps, &y_steps) == 0)
					{
						collection(fd,signature);
					}
				}

				delay(3000);

				go(homing_x,homing_y+5,fd);

				// return to reference position
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
	x_step = (LR_TO_STEP*(65 - distance1(fd)));
	y_step = (FB_TO_STEP*(65 - distance3(fd)));

	if (x_step > 0)
	{
		strafeRight(x_step);
	}
	else if (x_step < 0)
	{
		strafeLeft(-1*x_step);
	}

	straighten(fd);

	if (y_step > 0)
	{
		driveForward(y_step);
	}
	else if (y_step < 0)
	{
		driveBackward(-1*y_step);
	}

	// drive forward until on line conneting next quadrant
	driveForward(130*FB_TO_STEP);

	// turn left 90 degrees
	turnLeft(NINETY);

	// drive backwards to wall
	driveBackward(190*FB_TO_STEP);

	// strafe keft to doCorner() starting position
}

void toBase(int fd)
{
	// whatever quandrant you are currently in, go to that base
	float a = distance1(fd);
	
	driveOn();
	strafeRight((int)(1.1*a*LR_TO_STEP));
	strafeLeft(25);
	
	a = distance3(fd);
	
	if ( a > 5)
	{
		driveOn();
		driveBackward((int)((a-5)*FB_TO_STEP));
	}
	strafeRight((int)(MIDDLE*LR_TO_STEP));

	driveOff();
}

void dumpBase(int fd, int location)
{
	// open the doors for the corresponding color
	switch (location)
	{
		case 0:
			raiseFlag(fd);
			break;
		case 1:
			dump1(fd);
			break;
		case 2:
			dump2(fd);
			break;
		case 3:
			dump3(fd);
			break;
	}
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

void center(int fd)
{
	float currX, dx;
	int j = 0;
	
	straighten(fd);
	
	currX = distance1(fd);
	
	driveOn();
	
	while ((fabsf(currX - MIDDLE) > 3) && j < 3)
	{
		j++;
		dX = currX - MIDDLE;
	
		if (dX < 0)
		{
			strafeLeft((int)(-3*dX/4*LR_TO_STEP));
		}
		else if (dX > 0)
		{
			strafeRight((int)(3*dX/4*LR_TO_STEP));
		}
		
		currX = distance1(fd);
	}
	
	driveOff();
	
	straighten(fd);
}