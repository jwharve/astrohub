#include <wiringPi.h>

#define STEP 8

int main(void)
{
	wiringPiSetup();
	pinMode(STEP, OUTPUT);

	while(1)
	{
		digitalWrite(STEP,HIGH);
		delay(1);
		digitalWrite(STEP,LOW);
		delay(1);
	}
}
