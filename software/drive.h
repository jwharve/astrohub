#ifndef DRIVE_H
#define DRIVE_H

#include "pins.h"

#define START_DELAY 4 /* cannot be larger than 16 */
#define ACCEL 1.005
#define NUM_RAMP 279 /* number of accelerations need to get to full speed (1) */
#define TOP_SPEED 1000

#define NR_SPEED 2500 /* no ramp speed */

#define RAMP 10
#define NO_RAMP 11

#define A_THRESH 0.25
#define NUM_STRAIGHT 25

#define FB_TO_STEP 10.56833
#define LR_TO_STEP 14.47384
#define NINETY 270

void driveOn();
void driveOff();
void driveSetup();
void driveForward(int);
void driveBackward(int);
void strafeRight(int);
void strafeLeft(int);
void turnRight(int);
void turnLeft(int);
void move(int,char);
void straighten(int fd);

#endif
