#include "drive.h"
#include "file.h"

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
	digitalWrite(FR_DIR, LOW);
	digitalWrite(FL_DIR, HIGH);
	digitalWrite(BR_DIR, LOW);
	digitalWrite(BL_DIR, HIGH);

	move(steps);
}

void strafeLeft (int steps)
{
	digitalWrite(FR_DIR, HIGH);
	digitalWrite(FL_DIR, LOW);
	digitalWrite(BR_DIR, HIGH);
	digitalWrite(BL_DIR, LOW);

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

void move (int steps)
{
	int i = 0;

	for(i = 0; i < steps; i++)
	{
		digitalWrite(STEP, HIGH);

		delay(1);

		digitalWrite(STEP, LOW);

		delay(1);
	}
}
