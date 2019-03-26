/***************************************************************

Bradley Selee

PixyCam2

Testing pixy cam capabilities with this file.
Using c++ api on github.com/charmedlabs/pixy2/blob/master/src/host/
libpixyusb2_example/

***************************************************************/

#include <signal.h>
#include "libpixyusb2.h"

Pixy2 pixy; // pixy object


static bool run_flag = true;


// on CTRL+C - end program
void handle_SIGINT(int unused){
	
	
	run_flag = false;	

}


void get_blocks(){

	int Block_Index;

	// query pixy for blocks
	pixy.ccc.getBlocks();
	
	// if blocks are detected
	if(pixy.ccc.numBlocks()){
		
		printf("Detected %d blocks\n", pixy.ccc.numBlocks);

		for(Block_Index = 0; Block_Index < pixy.ccc.numBlocks; ++Block_Index){

			printf("Block %d: ", Block_Index + 1);
			pixy.ccc.blocks[Block_Index].print();

		}
	}
}

int main(













