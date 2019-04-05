#include "pi2Arduino.h"

void dump1(int fd)
{
	arduinoWriteChar(fd, 'a');
}

void dump2(int fd)
{
	arduinoWriteChar(fd,'b');
}

void dump3(int fd)
{
	arduinoWriteChar(fd,'c');
}

float distance1(int fd)
{
	static char *message;

	arduinoWriteChar(fd, 'd');
	message = arduinoReadString(fd);

	return atof(message);
}

float distance2(int fd)
{
	static char *message;

	arduinoWriteChar(fd, 'e');
	message = arduinoReadString(fd);

	return atof(message);
}

float distance3(int fd)
{
	static char *message;

	arduinoWriteChar(fd, 'f');
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
