#include "pi2Arduino.h"

void dump1(int fd)
{
	arduinoWriteChar(fd, S1);
}

void dump2(int fd)
{
	arduinoWriteChar(fd,S2);
}

void dump3(int fd)
{
	arduinoWriteChar(fd,S3);
}

void collection(int fd, int num)
{
	switch (num)
	{
		case 0:
			arduinoWriteChar(fd,CL);
			arduinoReadChar(fd);
			break;
		case 1:
			arduinoWriteChar(fd,CB);
			arduinoReadChar(fd);
			break;
		case 2:
			arduinoWriteChar(fd,CR);
			arduinoReadChar(fd);
			break;
		case 3:
			arduinoWriteChar(fd,CF);
			arduinoReadChar(fd);
			break;
	}
}

float distance1(int fd)
{
	static char *message;

	arduinoWriteChar(fd, D1);
	message = arduinoReadString(fd);

	return atof(message);
}

float distance2(int fd)
{
	static char *message;

	arduinoWriteChar(fd, D2);
	message = arduinoReadString(fd);

	return atof(message);
}

float distance3(int fd)
{
	static char *message;

	arduinoWriteChar(fd, D3);
	message = arduinoReadString(fd);

	return atof(message);
}

int arduinoSetup(void)
{
	int fd = serialOpen("/dev/ttyUSB0", 9600);

	delay(2000);

	serialFlush(fd);

	delay(2000);

	return fd;
}

void arduinoClose(int fd)
{
	delay(2000);

	serialClose(fd);
}

void arduinoWriteString(int fd, char* string)
{
	serialPuts(fd, string);
}

void arduinoWriteChar(int fd, char c)
{
	serialPutchar(fd, c);
}

char *arduinoReadString(int fd)
{
	int i = 0;
	static char message[50];

	while(serialDataAvail(fd) == 0);

	while(serialDataAvail(fd) > 0)
	{
		message[i] = arduinoReadChar(fd);
		i++;
	}

	message[i] = '\0';

	return message;
}

char arduinoReadChar(int fd)
{
	while(serialDataAvail(fd) == 0);

	return serialGetchar(fd);
}


void elUp(int fd)
{
	arduinoWriteChar(fd,RAISE);
}

void elDown(int fd)
{
	arduinoWriteChar(fd,LOWER);
}
