#include "cprocessing.h"
#include "../abstraction.h"

#include "mainmenu.h"

CP_Font font;

void credits_init(void) {
	font = CP_Font_Load("Assets/Fonts/Exo2-Regular.ttf");

	// Configure text settings
	CP_Font_Set(font);
	textSize(16.0f);
	textAlign(2, 16);
}

void credits_update(void) {
	// Reset background
	background(BLACK);


	fill(WHITE);
	textSize(42.0f);
	text("Credits", WIDTH / 2, 100);

	text("Team SOGE Games", WIDTH / 2, 500);
	textSize(16.0f);
	text("Saahil", WIDTH / 2, 550);
	text("Jasmine", WIDTH / 2, 570);
	text("Evan", WIDTH / 2, 590);
	text("Han Hui", WIDTH / 2, 610);

	text("Press Q to return", WIDTH / 2, 700);

	if (CP_Input_KeyDown(KEY_Q)) {
		CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	}

}

void credits_exit(void) {
	CP_Font_Free(font);
}

