#include "pickup.h"

int getClosest(void)
{
	float x,y;
	float x_des = -10, y_des = 5;
	float x_delta, y_delta;
	
	
	if (pixy(&x,&y) < 0)
		printf("didn't see any objects\n");
		return -1;
	}
	
	x_delta = x-x_des;
	y_delta = y-y_des;
	
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
		driveBack((int)(FB_TO_STEP*fabsf(y_delta)));
	}
	else
	{
		driveForward((int)(FB_TO_STEP*fabsf(y_delta)));
	}
	
	driveForward((int)(FB_TO_STEP*12));
	strafeLeft((int)(LR_TO_STEP*5));
	
}