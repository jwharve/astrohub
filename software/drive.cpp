#include "drive.h"
#include "pi2Arduino.h"

void driveOn()
{
	digitalWrite(ENABLE,LOW);
}

void driveOff()
{
	digitalWrite(ENABLE,HIGH);
}

void driveSetup()
{
	wiringPiSetup();


	pinMode(ENABLE,OUTPUT);
	driveOff();

	pinMode(STEP, OUTPUT);
	pinMode(FR_DIR, OUTPUT);
	pinMode(FL_DIR, OUTPUT);
	pinMode(BR_DIR, OUTPUT);
	pinMode(BL_DIR, OUTPUT);

	digitalWrite(STEP, LOW);
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, LOW);
}

void driveBackward (int steps)
{
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, HIGH);
	digitalWrite(BR_DIR, HIGH);
	digitalWrite(BL_DIR, LOW);

	move(steps,RAMP);
}

void driveForward (int steps)
{
	digitalWrite(FR_DIR, HIGH);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, HIGH);

	move(steps,RAMP);
}

void strafeRight (int steps)
{
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, LOW);

	move(steps,NO_RAMP);
}

void strafeLeft (int steps)
{
	digitalWrite(FR_DIR, HIGH);
	digitalWrite(FL_DIR, HIGH);
	digitalWrite(BR_DIR, HIGH);
	digitalWrite(BL_DIR, HIGH);

	move(steps,NO_RAMP);
}

void turnRight (int steps)
{
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, HIGH);
	digitalWrite(BL_DIR, HIGH);

	if (steps != 5)
		move(steps,RAMP);
	else
		move(5,NO_RAMP);
}

void turnLeft (int steps)
{
	digitalWrite(FR_DIR, HIGH);
	digitalWrite(FL_DIR, HIGH);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, LOW);

	if (steps != 5)
		move(steps,RAMP);
	else
		move(5,NO_RAMP);

}

void move(int steps, char ramp)
{
	if (ramp == NO_RAMP)
{
	int i;

	for (i = 0; i < steps; i++)
	{
		digitalWrite(STEP,HIGH);
		delayMicroseconds(NR_SPEED);
		digitalWrite(STEP,LOW);
		delayMicroseconds(NR_SPEED);
	}
	return;
}
else
{
	float del[2*NUM_RAMP];
	int i,j;

	// Return if number of steps is 0 (should never be less than 0)
	if (steps <= 0)
	{
		return;
	}

	// CALCULATE SPEEDS
	del[0] = START_DELAY * 1000;
	for (i = 1; i < steps/2 && i < NUM_RAMP; i++)
	{
		del[i] = del[i-1]/(float)ACCEL;
	}
	for (; i < steps && i < NUM_RAMP*2; i++)
	{
		del[i] = del[i-1]*ACCEL;
	}

	// RAMP UP
	j = 0;
	for (i = 0; i < steps/2 && i < NUM_RAMP; i++)
	{
		digitalWrite(STEP,HIGH);
		delayMicroseconds((unsigned int)(del[j]));
		digitalWrite(STEP,LOW);
		delayMicroseconds((unsigned int)(del[j]));
		j++;
	}
	// TOP SPEED
	for (; i < steps - NUM_RAMP; i++)
	{
		digitalWrite(STEP,HIGH);
		delayMicroseconds(TOP_SPEED);
		digitalWrite(STEP,LOW);
		delayMicroseconds(TOP_SPEED);
	}
	// RAMP DOWN
	for (; i < steps; i++)
	{
		digitalWrite(STEP,HIGH);
		delayMicroseconds((unsigned int)(del[j]));
		digitalWrite(STEP,LOW);
		delayMicroseconds((unsigned int)(del[j]));
		j++;
	}
}
}

void straighten(int fd)
{
	float d1, d2;
	int i;
	bool prev;
	bool curr = 0;

	for (i = 0; i < NUM_STRAIGHT; i++)
	{
		prev = curr;
		d1 = 0;
		d2 = 0;
		d1 += distance1(fd);
		d2 += distance2(fd);
		d1 += distance1(fd);
		d2 += distance2(fd);
		d1 += distance1(fd);
		d2 += distance2(fd);

		d1 = d1/3;
		d2 = d2/3;

		if ((d1 - d2) < -A_THRESH)
		{
			curr = 0;
			turnLeft(5);
		}
		else if ((d1-d2) > A_THRESH)
		{
			curr = 0;
			turnRight(5);
		}
		else
		{
			curr = 1;
			if (prev == 1)
				return;
		}
	}
}
