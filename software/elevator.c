#include "elevator.h"
#include "file.h"

void eleSetup()
{
	wiringPiSetup();
	pinMode(DI, OUTPUT);
	pinMode(FR_STEP, OUTPUT);
	pinMode(FL_STEP, OUTPUT);
	pinMode(BR_STEP, OUTPUT);
	pinMode(BL_STEP, OUTPUT);

	digitalWrite(DI, LOW);
	digitalWrite(FR_STEP, LOW);
	digitalWrite(FL_STEP, LOW);
	digitalWrite(BR_STEP, LOW);
	digitalWrite(BL_STEP, LOW);
}

void up()
{
	digitalWrite(DI, HIGH);

	eleMove(ELEVATOR_STEPS);
}

void down()
{
	digitalWrite(DI, LOW);

	eleMove(ELEVATOR_STEPS);
}

void dropFront()
{
	int i = 0;

	digitalWrite(DI, HIGH);
	for (i = 0; i < DROP_STEPS; i++)
	{
		digitalWrite(BR_STEP, HIGH);
		digitalWrite(BL_STEP, HIGH);

		delay(1);

		digitalWrite(BR_STEP, LOW);
		digitalWrite(BL_STEP, LOW);

		delay(1);
	}

	delay(250);

	digitalWrite(DI, LOW);

	for (i = 0; i < DROP_STEPS; i++)
	{
		digitalWrite(BR_STEP, HIGH);
		digitalWrite(BL_STEP, HIGH);

		delay(1);

		digitalWrite(BR_STEP, LOW);
		digitalWrite(BL_STEP, LOW);

		delay(1);
	}
}

void dropBack()
{
	int i = 0;

	digitalWrite(DI,HIGH);
	for (i = 0; i < DROP_STEPS; i++)
	{
		digitalWrite(FR_STEP, HIGH);
		digitalWrite(FL_STEP, HIGH);

		delay(1);

		digitalWrite(FR_STEP, LOW);
		digitalWrite(FL_STEP, LOW);

		delay(1);
	}

	delay(250);

	digitalWrite(DI, LOW);

	for (i = 0; i < DROP_STEPS; i++)
	{
		digitalWrite(FR_STEP, HIGH);
		digitalWrite(FL_STEP, HIGH);

		delay(1);

		digitalWrite(FR_STEP, LOW);
		digitalWrite(FL_STEP, LOW);

		delay(1);
	}
}

void dropLeft()
{
	int i = 0;

	digitalWrite(DI,HIGH);
	for (i = 0; i < DROP_STEPS; i++)
	{
		digitalWrite(FR_STEP, HIGH);
		digitalWrite(BR_STEP, HIGH);

		delay(1);

		digitalWrite(FR_STEP, LOW);
		digitalWrite(BR_STEP, LOW);

		delay(1);
	}

	delay(250);

	digitalWrite(DI, LOW);

	for (i = 0; i < DROP_STEPS; i++)
	{
		digitalWrite(FR_STEP, HIGH);
		digitalWrite(BR_STEP, HIGH);

		delay(1);

		digitalWrite(FR_STEP, LOW);
		digitalWrite(BR_STEP, LOW);

		delay(1);
	}
}

void dropRight()
{
	int i = 0;

	digitalWrite(DI,HIGH);

	for (i = 0; i < DROP_STEPS; i++)
	{
		digitalWrite(FL_STEP, HIGH);
		digitalWrite(BL_STEP, HIGH);

		delay(1);

		digitalWrite(FL_STEP, LOW);
		digitalWrite(BL_STEP, LOW);

		delay(1);
	}

	delay(250);

	digitalWrite(DI, LOW);

	for (i = 0; i < DROP_STEPS; i++)
	{
		digitalWrite(FL_STEP, HIGH);
		digitalWrite(BL_STEP, HIGH);

		delay(1);

		digitalWrite(FL_STEP, LOW);
		digitalWrite(BL_STEP, LOW);

		delay(1);
	}
}

void eleMove(int steps)
{
	int i = 0;

	for (i = 0; i < steps; i++)
	{
		digitalWrite(FR_STEP, HIGH);
		digitalWrite(FL_STEP, HIGH);
		digitalWrite(BR_STEP, HIGH);
		digitalWrite(BL_STEP, HIGH);

		delay(1);

		digitalWrite(FR_STEP, LOW);
		digitalWrite(FL_STEP, LOW);
		digitalWrite(BR_STEP, LOW);
		digitalWrite(BL_STEP, LOW);

		delay(1);
	}
}
