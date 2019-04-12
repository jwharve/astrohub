#ifndef PI2ARDUINO_H
#define PI2ARDUINO_H

#include "pins.h"

#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define S1 'a'
#define S2 'b'
#define S3 'c'
#define D1 'd'
#define D2 'e'
#define D3 'f'
#define RF 'g'
#define CF 'h'
#define CB 'i'
#define CL 'j'
#define CR 'k'
#define RAISE 'l'
#define LOWER 'm'

#define GOOD 'c'
#define BAD 'n'

void dump1(int);
void dump2(int);
void dump3(int);
void collection(int, int);
float distance1(int);
float distance2(int);
float distance3(int);
void raiseFlag(int);

int arduinoSetup(void);
void arduinoClose(int);
void arduinoWriteString(int, char *);
void arduinoWriteChar(int, char);
char *arduinoReadString(int);
char arduinoReadChar(int);

void elUp(int);
void elDown(int);

#endif
