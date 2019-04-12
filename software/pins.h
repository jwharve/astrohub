#ifndef PINS_H
#define PINS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>


// ELEVATOR
#define DI	6
#define FR_STEP 11
#define FL_STEP 10
#define BR_STEP 31
#define BL_STEP 26

// WHEELS
#define STEP 13
#define FR_DIR 30
#define FL_DIR 14
#define BR_DIR 21
#define BL_DIR 22
#define ENABLE 12

#define START_PIN 24

// COLORS
#define RED 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3

#endif
