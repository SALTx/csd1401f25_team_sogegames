#include "cprocessing.h"
#include "abstraction.h"
#include "Screens/splash.h"

void main_init(void){}
void main_update(void){}
void main_exit(void){}

int main(void)
{
	// Essential configuration
	CP_System_SetWindowSize(1600, 900);
	CP_System_SetFrameRate(60.0f); // Set the framerate to 60 FPS for consistency

	CP_Engine_SetNextGameState(splash_init, splash_update, splash_exit);
	CP_Engine_Run(1);
	return 0;
}
