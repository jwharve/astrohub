#include "pins.h"
#include "vision.h"
#include "libpixyusb2.h"

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

	pH = (((float)C)-NUM_COLS/2)/NUM_COLS;
	pV = ((NUM_ROWS - ((float)R)) - NUM_ROWS/2)/NUM_ROWS;

	hDeg = degH0 + DEG_H/2 + atan(pH * h / d) * 180.0/PI;
	vDeg = degV0 + DEG_V/2 + atan(pV * v / d) * 180.0/PI;

	*y = HEIGHT*tan(vDeg * PI/180.0);
	*x = sqrt((*y)*(*y) + (HEIGHT * HEIGHT)) * tan(hDeg * PI/180);

	return;
}

int pixy(int *signature, float *x, float *y)
{
	int  Result;
	int i;
	int max_y = 0;
	int max_loc = -1;

	Pixy2 pixy;

  // Initialize Pixy2 Connection //
  {
	printf("Connecting...\n");
    Result = pixy.init();

    if (Result < 0)
    {
      printf ("Error\n");
      printf ("pixy.init() returned %d\n", Result);
      return -1;
    }

    printf ("Success\n");
  }
  
  
  pixy.ccc.getBlocks();
 

	for (i = 0; i < pixy.ccc.numBlocks; i++)
	{
		if (pixy.ccc.blocks[i].m_y > max_y)
		{
			max_y = pixy.ccc.blocks[i].m_y;
			max_loc = i;
		}
	}

	*signature = pixy.ccc.blocks[max_loc].m_signature;

//	printf("m_x - %d\n", pixy.ccc.blocks[max_loc].m_x);
//	printf("m_y - %d\n", pixy.ccc.blocks[max_loc].m_y);
	
	loc(pixy.ccc.blocks[max_loc].m_x, pixy.ccc.blocks[max_loc].m_y, x, y);
	
//	printf("X - %f\n", x);
//	printf("Y - %f\n", y);
	return 0;
}
