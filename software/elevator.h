#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "pins.h"

#define ELEVATOR_STEPS 	1400
#define DROP_STEPS 	200

void eleSetup();
void up();
void down();
void dropFront();
void dropBack();
void dropLeft();
void dropRight();
void eleMove(int);

#endif