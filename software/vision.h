#ifndef VISION_H
#define VISION_H

#include <math.h>

#define PI 3.14159265

#define DEG_H (float)60
#define DEG_V (float)40

#define PIX_H (float)1296
#define PIX_V (float)967
#define PIX_SIZE (float)0.0000019

#define PIXY_ANGLE (float)50

#define NUM_COLS (float)315
#define NUM_ROWS (float)207

#define HEIGHT (float)24.5/*26.5*//*((10.375-2)*2.54)*/

void loc(int, int, float *, float *);
int pixy(int *, float *,float *);
int pixyIgnore(int *signature, float *x, float *y, int ignoreNum);
char sig2Color(int sig);

#endif
