#include "cprocessing.h"
#include "../abstraction.h"
#include "../Utils/ui_elements.h"

// Assets
CP_Font font;

// Globals
ButtonStyle buttonStyle;
TextStyle textStyle;

// Buttons
Button exitButton;


void mainmenu_init(void) {
	// Set shape rules
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	// Load assets
	font = CP_Font_Load("Assets/Fonts/Exo2-Regular.ttf");

	// Set button styles
	buttonStyle = (ButtonStyle){ RED, GREEN, BLUE, 0.0f };
	textStyle = (TextStyle){ "Exit", BLACK, WHITE, 36.0f };

	// Set exit button
	exitButton = (Button){
		(Quad) { 200, 200, 200, 200 },
		buttonStyle,
		textStyle
	};

}

void mainmenu_update(void) {
	CP_Graphics_ClearBackground(CP_Color_Create(0, 255, 0, 255));

	drawButton(exitButton);
}

void mainmenu_exit(void) {
	CP_Font_Free(font);
}
