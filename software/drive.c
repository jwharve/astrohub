#include "drive.h"

void driveSetup()
{
	wiringPiSetup();
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
	
	digitalWrite(ENABLE,OFF);
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
	digitalWrite(FR_DIR, HIGH);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, HIGH);

	move(steps);
}

void strafeRight (int steps)
{
	digitalWrite(FR_DIR, HIGH);
	digitalWrite(FL_DIR, HIGH);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, LOW);

	move(steps);
}

void strafeLeft (int steps)
{
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, HIGH);
	digitalWrite(BL_DIR, HIGH);

	move(steps);
}

void turnRight (int steps)
{
	digitalWrite(FR_DIR, HIGH);
	digitalWrite(FL_DIR, HIGH);
	digitalWrite(BR_DIR, HIGH);
	digitalWrite(BL_DIR, HIGH);

	move(steps);
}

void turnLeft (int steps)
{
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, LOW);

	move(steps);
}

int move(int steps)
{
	float del[2*NUM_RAMP];

	// Return if number of steps is 0 (should never be less than 0)
	if (num_steps <= 0)
	{
		return 0;
	}

	// CALCULATE SPEEDS
	del[0] = START_DELAY * 1000;
	for (i = 1; i < num_steps/2 && i < NUM_RAMP; i++)
	{
		del[i] = del[i-1]/(float)ACCEL;
	}
	for (; i < num_steps && i < NUM_RAMP*2; i++)
	{
		del[i] = del[i-1]*ACCEL;
	}
	
	// RAMP UP
	for (i = 0; i < num_steps/2 && i < NUM_RAMP; i++)
	{
		digitalWrite(STEP,HIGH);
		delayMicroseconds(static_cast<int>(del[j]));
		digitalWrite(STEP,LOW);
		delayMicroseconds(static_cast<int>(del[j]));
		j++;
	}
	// TOP SPEED
	for (; i < num_steps - NUM_RAMP; i++)
	{
		digitalWrite(STEP,HIGH);
		delay(1);
		digitalWrite(STEP,LOW);
		delay(1);
	}
	// RAMP DOWN
	for (; i < num_steps; i++)
	{
		digitalWrite(STEP,HIGH);
		delayMicroseconds(static_cast<int>(del[j]));
		digitalWrite(STEP,LOW);
		delayMicroseconds(static_cast<int>(del[j]));
	}
}

