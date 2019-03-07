#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>
#include "file.h"

#define DI	6
#define FR_STEP 11
#define FL_STEP 10
#define BR_STEP 26
#define BL_STEP 31

#define ELEVATOR_STEPS 	1250
#define DROP_STEPS 	200

void eleSetup();
void up();
void down();
void dropFront();
void dropBack();
void dropLeft();
void dropRight();
void eleMove(int);
