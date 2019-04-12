#include "pickup.h"

int getClosest(int *x_steps, int *y_steps, int ignoreNum)
{
	float x,y;
	float x_des = -10;
	float y_des = 10;
	float x_delta;
	float y_delta;
	int signature;

	*x_steps = 0;
	*y_steps = 0;

	if (pixyIgnore(&signature,&x,&y,ignoreNum) < 0)
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
		*x_steps -= ((int)(LR_TO_STEP*fabsf(x_delta)));
	}
	else
	{
		strafeRight((int)(LR_TO_STEP*fabsf(x_delta)));
		*x_steps += ((int)(LR_TO_STEP*fabs(x_delta)));
	}

	// take another picture
	if (pixyIgnore(&signature,&x,&y,ignoreNum) < 0)
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
		*x_steps -= ((int)(LR_TO_STEP*fabsf(x_delta)));
	}
	else
	{
		strafeRight((int)(LR_TO_STEP*fabsf(x_delta)));
		*x_steps += ((int)(LR_TO_STEP*fabsf(x_delta)));
	}

	if (y_delta < 0)
	{
		driveBackward((int)(FB_TO_STEP*fabsf(y_delta)));
		*y_steps -= ((int)(FB_TO_STEP*fabsf(y_delta)));
	}
	else
	{
		driveForward((int)(FB_TO_STEP*fabsf(y_delta)));
		*y_steps += ((int)(FB_TO_STEP*fabsf(y_delta)));
	}

	// drive until proximity sensor is tripped
	*y_steps += (int)(FB_TO_STEP*proximity());

	// drive backwards slightly
	driveBackward((int)(LR_TO_STEP*2));
	strafeLeft((int)(LR_TO_STEP*15));
	strafeRight((int)(LR_TO_STEP*2));
	driveForward(20);
	
	driveOff();

	*y_steps -= (int)(FB_TO_STEP*10);
	*x_steps -= (int)(LR_TO_STEP*15);
	*x_steps += (int)(LR_TO_STEP*2);
	*y_steps += 20;

	return 0;
}
