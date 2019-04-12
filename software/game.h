#ifndef GAME_H
#define GAME_H

#include "pins.h"
#include "drive.h"
#include "vision.h"
#include "pickup.h"

void fromHome(int);
void doHome(int);
void moveCorner(int);
void doCorner(int);
void toBase(int);
void dumpBase(int, int);
void goHome(int, int, int);
void go(float x, float y, int fd);
void center(int fd);

#endif
