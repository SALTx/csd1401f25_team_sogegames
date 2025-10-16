#include "cprocessing.h"
#include "../abstraction.h"
#include "settings_screen.h"
#include "mainmenu.h"
#include "../Utils/ui_elements.h";

// Load assets
CP_Font font;

// Real settings
int soundEnabled = 1;
int musicEnabled = 1;

CheckBox soundToggle;
CheckBox musicToggle;


void settings_init(void) {
	// Load font
	font = CP_Font_Load("Assets/Fonts/Exo2-Regular.ttf");

	// Setup text
	CP_Font_Set(font);
	textSize(16.0f);
	textAlign(2, 16);

	soundToggle = (CheckBox){
		(Point) {1200, HEIGHT/2},
		&soundEnabled,
		NULL, // No callback for now but i might implement
	};

	musicToggle = (CheckBox){
		(Point) {1200, HEIGHT/2+32.0f},
		&musicEnabled,
		NULL, // No callback for now but i might implement
	};
}

void settings_update(void) {
	// Reset background
	background(BLACK);

	// Settings title
	fill(WHITE);
	textSize(32.0f);
	text("Settings", WIDTH / 2, 50);

	//fill(WHITE);
	//textSize(16.0f);
	//text("Not implemented yet", WIDTH / 2, HEIGHT / 2);
	//text("Press Q to go back", WIDTH / 2, HEIGHT / 2 + 16.0f);

	// Draw settings
	fill(WHITE);
	textSize(16.0f);
	text("Sound: ", WIDTH / 2, HEIGHT / 2);
	text("Music: ", WIDTH / 2, HEIGHT / 2 + 32.0f);
	drawCheckbox(soundToggle);
	drawCheckbox(musicToggle);

	// Go back to menu with Q
	if (CP_Input_KeyTriggered(KEY_Q)) {
		CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	}
}

void settings_exit(void) {
	CP_Font_Free(font);
}
