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

	// Images
	CP_Settings_ImageMode(CP_POSITION_CORNER);

	CP_Engine_SetNextGameState(splash_init, splash_update, splash_exit);
	CP_Engine_Run(0);
	return 0;
}
