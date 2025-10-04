#include "cprocessing.h"
#include "../abstraction.h"
#include "mainmenu.h"

CP_Image digipen_logo;
int digipen_logo_alpha;

void splash_init(void) {
	digipen_logo = CP_Image_Load("Assets/digipen_logo.png");
	digipen_logo_alpha = 0;
}

void splash_update(void) {
	CP_Graphics_ClearBackground(BLACK);

	// Draw the digipen logo
	CP_Image_Draw(digipen_logo, WIDTH / 2, HEIGHT / 2, CP_Image_GetWidth(digipen_logo), CP_Image_GetHeight(digipen_logo), digipen_logo_alpha++);

	// Finish splash or if player skips
	if (digipen_logo_alpha >= 255 || CP_Input_MouseClicked()) {
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
