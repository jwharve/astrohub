#ifndef DRIVE_H
#define DRIVE_H

#include "pins.h"

#define START_DELAY 1.75 /* cannot be larger than 16 */
#define ACCEL 1.005
#define NUM_RAMP 113 /* number of accelerations need to get to full speed (1) */

void driveOn();
void driveOff();
void driveSetup();
void driveForward(int);
void driveBackward(int);
void strafeRight(int);
void strafeLeft(int);
void turnRight(int);
void turnLeft(int);
void move(int);

#endif
