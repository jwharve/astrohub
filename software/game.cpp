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
	if ( a > 0)
	{
		driveBackward((int)(a*FB_TO_STEP));
	}


	driveForward(40);

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

	while (dist < 100)
	{
		serialFlush(fd);
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
			}

			// center robot
			center(fd);

			driveOn();
			driveBackward((int)(FB_TO_STEP*20));
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
	straighten(fd);

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

	driveOn();
	a = distance3(fd);
	// drive backward to wall
	if (a > 0)
	{
		driveBackward((int)(a*FB_TO_STEP));
	}
	driveForward(40);
	driveOff();
}

void toBase(int fd)
{
	// whatever quandrant you are currently in, go to that base
	float a = distance1(fd);

	driveOn();

	turnRight(NINETY);
	driveForward((int)(55*FB_TO_STEP));
	driveBackward(20);
	raiseFlag(fd);
	return;




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
	printf("X - %d\n",x);
	printf("Y - %d\n",y);

	if (x < -120)
	{
		printf("too far left\n");
		return 1;
	}
	else if (y > 110 && y < 140)
	{
		printf("miss stripe\n");
		return 1;
	}
	else if (y > 150)
	{
		printf("too far\n");
		return 1;
	}
	else if (x > -25)
	{
		printf("too far right\n");
		return 1;
	}
	else
	{
		printf("good\n");
		return 0;
	}




	if (x < -100)
	{
		printf("too far left\n");
		return 1;
	}
	else if (x < -90 && y > 80 && y < 125)
	{
		printf("avoid inside middle\n");
		return 1;
	}
	else if (x > -15)
	{
		printf("too far right\n");
		return 1;
	}
	else if (y > 105 && y < 125)
	{
		printf("avoid middle\n");
		return 1;
	}
	else if (y > 190)
	{
		printf("too far\n");
		return 1;
	}
	else
	{
		printf("good\n");
		return 0;
	}
}
