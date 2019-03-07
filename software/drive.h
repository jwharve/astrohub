#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>
#include "file.h"

#define STEP 13
#define FR_DIR 30
#define FL_DIR 14
#define BR_DIR 21
#define BL_DIR 22

void driveSetup();
void driveForward(int);
void driveBackward(int);
void strafeRight(int);
void strafeLeft(int);
void turnRight(int);
void turnLeft(int);
void move(int);
