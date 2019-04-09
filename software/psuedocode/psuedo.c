// includes
#include <time.h>

#define RED 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3

#define timeThreshold 120


int main (void)
{
	// timer variables
	long int startTime;
	long int matchTime;
	struct timespec getTime;

	int i = 0;
	int homeBase = 0;

	// busy wait for start button

	// start timer
	clock_gettime(CLOCK_REALTIME, &getTime);
	startTime = getTime.tv_sec;

	// color sensor function, to get home base color
	// sets base color variable (red=0, yellow=1, blue=2, green=3)
	// example: red
	homeBase = RED;

	clock_gettime(CLOCK_REALTIME, &getTime);
	matchTime = getTime.tv_sec - startTime;

	for (i = 0; (i < 3) && (matchTime < timeThreshold); i++)
	{
		if (i == 0)
		{
			// move from home base function
			// fromHome();

			// do home corner
			// doHome(homeBase);

			// move corner
			// moveCorner();
		}
		else
		{
			// do corner
			// doCorner(homeBase);

			// move corner
			// moveCorner();
		}
		clock_gettime(CLOCK_REALTIME, &getTime);
		matchTime = getTime.tv_sec - startTime;

	}

	// start drop off process

	for (i = 0; (i < 3) && (matchTime < timeTreshold); i++)
	{
		// move corner
		// moveCorner();

		// go to base
		// toBase();

		// drop off
		// dumpBase at home will raise a flag
		// dumpBase(homeBase+i);

		clock_gettime(CLOCK_REALTIME, &getTime);
		matchTime = getTime.tv_sec;

		return 0;
	}

	if (matchTime < timeTheshold)
	{
		goHome(i);
		return 0;
	}
}
