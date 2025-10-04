#include "cprocessing.h"
#include "../abstraction.h"

// Declare assets
CP_Image digipen_logo;

// Globals
int digipen_logo_alpha;

void splash_init(void) {
	// Load digipen logo 
	digipen_logo = CP_Image_Load("Assets/digipen_logo.png");

	digipen_logo_alpha = 0;
}

void splash_update(void) {
	// Black background
	CP_Graphics_ClearBackground(BLACK);

	// Draw the digipen logo
	CP_Image_Draw(digipen_logo, 0.0f, 0.0f, CP_Image_GetWidth(digipen_logo), CP_Image_GetHeight(digipen_logo), digipen_logo_alpha++);


	// Skip to main menu by clicking
	if (CP_Input_MouseClicked()) {
		CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	}

	// Quit
	if (CP_Input_KeyTriggered(KEY_Q)) {
		CP_Engine_Terminate();
	}
}

void splash_exit(void) {
	CP_Image_Free(digipen_logo);
}
