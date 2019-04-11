#include "pickup.h"

int getClosest(void)
{
	float x,y;
	float x_des = -10;
	float y_des = 10;
	float x_delta;
	float y_delta;
	int signature;

	if (pixy(&signature,&x,&y) < 0)
	{
		printf("didn't see any objects\n");
		return -1;
	}

	x_delta = x - x_des;

	printf("x_delta - %f\n",x_delta);

	driveOn();
	if (x_delta < 0)
	{
		strafeLeft((int)(LR_TO_STEP*fabsf(x_delta)));
	}
	else
	{
		strafeRight((int)(LR_TO_STEP*fabsf(x_delta)));
	}


	// take another picture
	if (pixy(&signature,&x,&y) < 0)
	{
		printf("didn't see any objects\n");
		return -1;
	}

	x_delta = x - x_des;
	y_delta = y - y_des;

	printf("x_delta - %f\n",x_delta);
	printf("y_delta - %f\n",y_delta);

	if (x_delta < 0)
	{
		strafeLeft((int)(LR_TO_STEP*fabsf(x_delta)));
	}
	else
	{
		strafeRight((int)(LR_TO_STEP*fabsf(x_delta)));
	}

	if (y_delta < 0)
	{
		driveBackward((int)(FB_TO_STEP*fabsf(y_delta)));
	}
	else
	{
		driveForward((int)(FB_TO_STEP*fabsf(y_delta)));
	}

	delay(2000);


	driveForward((int)(FB_TO_STEP*20));
	strafeLeft((int)(LR_TO_STEP*15));
	strafeRight((int)(LR_TO_STEP*2));
	driveOff();

	return 0;
}
