#ifndef PI2ARDUINO_H
#define PI2ARDUINO_H

#include "pins.h"

#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void dump1(int);
void dump2(int);
void dump3(int);
float distance1(int);
float distance2(int);
float distance3(int);

int arduinoSetup(void);
void arduinoClose(int);
void arduinoWriteString(int, char *);
void arduinoWriteChar(int, char);
char *arduinoReadString(int);
char arduinoReadChar(int);

#endif
