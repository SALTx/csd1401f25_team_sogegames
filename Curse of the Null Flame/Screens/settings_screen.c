#include "cprocessing.h"
#include "../abstraction.h"
#include "settings_screen.h"
#include "mainmenu.h"

// Load assets
CP_Font font;

void settings_init(void) {
	font = CP_Font_Load("Assets/Fonts/Exo2-Regular.ttf");

	// Setup text
	CP_Font_Set(font);
	textSize(16.0f);
	textAlign(2, 16);
}

void settings_update(void) {
	// Reset background
	background(BLACK);

	fill(WHITE);
	text("Not implemented yet", WIDTH / 2, HEIGHT / 2);
	text("Press Q to go back", WIDTH / 2, HEIGHT / 2 + 16.0f);

	if (CP_Input_KeyTriggered(KEY_Q)) {
		CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	}
}

void settings_exit(void) {
	CP_Font_Free(font);
}
