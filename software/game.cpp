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

	while (dist < 190)
	{
		// get current location
		x_current = distance1(fd);
		y_current = distance3(fd);

		// get location of first object
		pixyReturn = pixy(&signature, &x, &y);

		i = 1;
		while (pixyReturn >= 0)
		{		
			if (dead_zone(x-x_current-17, y+y_current+22))
			{
				pixyReturn = pixyIgnore(&signature, &x, &y, i);
				i++;
			}
			else
			{
				break;
			}
		}

		if (pixyReturn >= 0)
		{
			printf("Before get\n");
			signature = getClosest(&x_steps, &y_steps, i-1);
			printf("After get\n");
		
			if (signature != -1)
			{
				collection(fd, sig2Color(signature));


				// wait until collection is good
				arduinoReadChar(fd);
			}

			// center robot
			center(fd);	

			driveOn();
			driveBackward((int)(FB_TO_STEP*10));
			driveOff();
		}
		else
		{
			printf("Else\n");
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
	float currX, dX;
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

int dead_zone(int x, int y)
{
	if (x < (-130 + 25) && y < (30))
	{
		printf("dead zone 1\n");
		return 1;
	} 
	else if (y < 135 && y > (130 - 25) && x > -30)
	{
		printf("dead zone 2\n");
		return 1;
	}
	else if (x < (-130 + 17 + 25) && y > (130 - 17 - 25) && y < (130 + 17))
	{
		printf("dead zone 3\n");
		return 1;
	}
	else if (x < (-120 + 25) && y > (260 - 30))
	{
		printf("dead zone 4\n");
		return 1;
	}
	else if (y > 120 - 25 && y < 140 - 25)
	{
		printf("dead zone 5\n");
		return 1;
	}
	else if (x < -120 + 25)
	{
		printf("dead zone 6\n");
		return 1;
	}
	else if (x > 30)
	{
		printf("dead zone 7\n");
		return 1;
	}
	else if (y > 160)
	{
		printf("dead zone 8\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
