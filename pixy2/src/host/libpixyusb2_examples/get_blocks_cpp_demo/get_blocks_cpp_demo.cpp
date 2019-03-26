//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//

/*************************************************************************

Editing program to attempt and find the distance from the given pixels.



*************************************************************************/


#define OBJECT_WIDTH 2.5 /* inches*/
#define PIXEL_WIDTH 24 /* pixels*/
#define MEASURED_DISTANCE 21 /**/

#include <signal.h>
#include "libpixyusb2.h"

Pixy2        pixy;
static bool  run_flag = true;


void handle_SIGINT(int unused)
{
  // On CTRL+C - abort! //

  run_flag = false;
}

void  get_blocks()
{
  int  Block_Index;

  // Query Pixy for blocks //
  pixy.ccc.getBlocks();

  // Were blocks detected? //
  if (pixy.ccc.numBlocks)
  {
    // Blocks detected - print them! //

    printf ("Detected %d block(s)\n", pixy.ccc.numBlocks);

    for (Block_Index = 0; Block_Index < pixy.ccc.numBlocks; ++Block_Index)
    {
      printf ("  Block %d: ", Block_Index + 1);
      pixy.ccc.blocks[Block_Index].print();
    }
  }
}

void modify_blocks()
{
	
	int Block_Index;

	int blockHeight;
	int blockWidth;
	int blockX;
	int blockY;
	int blockAngle;
	int blockSignature;

	float focalLength; // units -> pixels
	float measuredDistance; // units -> inches    initial distance from camera to object
	float objectWidth; // units -> inchess
	float pixelWidth; // units -> pixels     pixel width of object given by pixy cam
	float newDistance = 0; // units -> inches     new distance from object to camera when the camera moves

	measuredDistance = MEASURED_DISTANCE; 
	objectWidth = OBJECT_WIDTH;
	pixelWidth = PIXEL_WIDTH;

 	 // Query Pixy for blocks //
  	 pixy.ccc.getBlocks();
	
	 // finds constant that will be used for the new distance
	 // need to measure measuredDistance and objectWidth to calibrate
	 focalLength = (pixelWidth * measuredDistance) / objectWidth;


  	 // Were blocks detected? //
 	 if (pixy.ccc.numBlocks)
  	 {
    	
			
	


		// Blocks detected - print them! //
    	printf ("Detected %d block(s)\n", pixy.ccc.numBlocks);

    	for (Block_Index = 0; Block_Index < pixy.ccc.numBlocks; ++Block_Index)
    	{

			blockHeight = pixy.ccc.blocks[Block_Index].m_height;
			blockWidth = pixy.ccc.blocks[Block_Index].m_width;
			blockX = pixy.ccc.blocks[Block_Index].m_x;
			blockY = pixy.ccc.blocks[Block_Index].m_y;
			blockAngle = pixy.ccc.blocks[Block_Index].m_angle;
			blockSignature = pixy.ccc.blocks[Block_Index].m_signature;

			pixelWidth = blockWidth;
			
			

			// maths
			// Focal Length = (Pixel Width of Object * Distance from Camera to Obejct) / (Width of the object)
			// New Distance = (Width of Object * Focal Length) / (Pixel Width of Object) 

	
			// Finds new distance of the object when the pixy cam is taken away
			newDistance = (objectWidth * focalLength) / pixelWidth;
	

      	
			printf ("  \n\nObject height:  %d \n", blockHeight);
			printf ("  \nObject width:  %d \n", blockWidth);
			printf ("  \nObject X (pixels): %d \n", blockX);
			printf ("  \nObject Y (Pixels):  %d \n", blockY);
			printf ("  \nObject Angle:  %d \n", blockAngle);
			printf ("  \nObject Signature:  %d \n", blockSignature);
			printf ("  \nFocal Length:  %.3f \n", focalLength);
			printf ("  \nNew Distance:  %.3f \n", newDistance);
      	
			//pixy.ccc.blocks[Block_Index].print();
    	}
  	 }	
}




int main()
{
  int  Result;

  // Catch CTRL+C (SIGINT) signals //
  signal (SIGINT, handle_SIGINT);

  printf ("=============================================================\n");
  printf ("= PIXY2 Get Blocks Demo                                     =\n");
  printf ("=============================================================\n");

  printf ("Connecting to Pixy2...");

  // Initialize Pixy2 Connection //
  {
    Result = pixy.init();

    if (Result < 0)
    {
      printf ("Error\n");
      printf ("pixy.init() returned %d\n", Result);
      return Result;
    }

    printf ("Success\n");
  }

  // Get Pixy2 Version information //
  {
    Result = pixy.getVersion();

    if (Result < 0)
    {
      printf ("pixy.getVersion() returned %d\n", Result);
      return Result;
    }

    pixy.version->print();
  }

  // Set Pixy2 to color connected components program //
  pixy.changeProg("color_connected_components");

  while(1)
  {

   // get_blocks();

	 modify_blocks();

    if (run_flag == false)
    {
      // Exit program loop //
      break;
    }
  }

  printf ("PIXY2 Get Blocks Demo Exit\n");
}
