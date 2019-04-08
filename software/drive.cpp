#include "drive.h"

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

void driveForward (int steps)
{
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, HIGH);
	digitalWrite(BR_DIR, HIGH);
	digitalWrite(BL_DIR, LOW);

	move(steps);
}

void driveBackward (int steps)
{
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, HIGH);

	move(steps);
}

void strafeRight (int steps)
{
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, HIGH);
	digitalWrite(BR_DIR, HIGH);
	digitalWrite(BL_DIR, HIGH);

	move(steps);
}

void strafeLeft (int steps)
{
	digitalWrite(FR_DIR, HIGH);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, LOW);

	move(steps);
}

void turnRight (int steps)
{
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, LOW);

	move(steps);
}

void turnLeft (int steps)
{
	digitalWrite(FR_DIR, HIGH);
	digitalWrite(FL_DIR, HIGH);
	digitalWrite(BR_DIR, HIGH);
	digitalWrite(BL_DIR, HIGH);

	move(steps);
}

void move(int steps)
{
	if (0)
{
	int i;

	for (i = 0; i < steps; i++)
	{
		digitalWrite(STEP,HIGH);
		delayMicroseconds(TOP_SPEED);
		digitalWrite(STEP,LOW);
		delayMicroseconds(TOP_SPEED);
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

