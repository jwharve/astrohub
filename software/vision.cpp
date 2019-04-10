#include "pins.h"
#include "vision.h"

void loc(int C, int R, float * x, float * y)
{
	float degH0, degV0, h, v, d1, d2, d, pH, pV, hDeg, vDeg;


	degH0 = -DEG_H/2;
	degV0 = PIXY_ANGLE-DEG_V/2;

	h = PIX_H*PIX_SIZE;
	v = PIX_V*PIX_SIZE;

	d1 = (0.5*h)/tan(DEG_H/2 * PI/180.0);
	d2 = (0.5*v)/tan(DEG_V/2 * PI/180.0);

	d = (d1+d2)/2;

	printf("d - %f\n",d);

	printf("nc/2 - %f\n",NUM_COLS/2);

	pH = (((float)C)-NUM_COLS/2)/NUM_COLS;
	pV = ((NUM_ROWS - ((float)R)) - NUM_ROWS/2)/NUM_ROWS;

	printf("pH - %f\n", pH);
	printf("h - %f\n", h);
	printf("d - %f\n",d);
	printf("atan - %f\n",pH*h/d);

	hDeg = degH0 + DEG_H/2 + atan(pH * h / d) * 180.0/PI;
	vDeg = degV0 + DEG_V/2 + atan(pV * v / d) * 180.0/PI;

	printf("hDeg %f, vDeg %f\n", hDeg, vDeg);

	*y = HEIGHT*tan(vDeg * PI/180.0);
	*x = sqrt((*y)*(*y) + (HEIGHT * HEIGHT)) * tan(hDeg * PI/180);

	return;
}
