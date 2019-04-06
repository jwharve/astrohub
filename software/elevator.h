#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "pins.h"

#define ELEVATOR_STEPS 	1400
#define DROP_STEPS 	200

#define FRL 0
#define FRR 1
#define RRL 2
#define RRR 3


void eleSetup();
void up();
void down();
void dropFront();
void dropBack();
void dropLeft();
void dropRight();
void eleMove(int);
void singleMove(char motor, int steps, char dir);

#endif