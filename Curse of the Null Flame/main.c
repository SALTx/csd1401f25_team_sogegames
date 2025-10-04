#include "cprocessing.h"
#include "abstraction.h"

void game_init(void)
{
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_CLAMP);

	CP_System_SetWindowSize(1600, 900);
}

void game_update(void)
{
	// Black background
	CP_Graphics_ClearBackground(BLACK);
	
	// Quit with Button Q
	if (CP_Input_KeyDown(KEY_Q))
	{
		CP_Engine_Terminate();
	}
}

void game_exit(void)
{
}

int main(void)
{
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run(0);
	return 0;
}
