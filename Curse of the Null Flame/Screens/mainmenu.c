#include "cprocessing.h"
#include "../abstraction.h"
#include "../Utils/ui_elements.h"
#include "../Utils/sprite_utils.h"

#include "game_screen.h"
#include "settings_screen.h"

#include <stdio.h>

// Assets
CP_Font font;

// Globals
ButtonStyle buttonStyle; // This will be the default button style
TextStyle textStyle; // This will be the default text style for buttons

// Buttons
Button startButton;
Button settingsButton;
Button exitButton;

// Sprite testing
CP_Image dungeon_tileset_image;
SpriteSheet dungeon_tileset;
Sprite randomSprite;

void navigateToGame(void) {
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
}

void navigateToSettings(void) {
	CP_Engine_SetNextGameState(settings_init, settings_update, settings_exit);
}

void mainmenu_init(void) {
	// Set shape rules
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	CP_Settings_ImageFilterMode(CP_IMAGE_FILTER_NEAREST);
	CP_Settings_ImageMode(CP_POSITION_CORNER);

	// Load assets
	font = CP_Font_Load("Assets/Fonts/Exo2-Regular.ttf");
	dungeon_tileset_image = CP_Image_Load("Assets/Sprites/dungeon_packed.png");

	// Set spritesheet and sprite
	dungeon_tileset = (SpriteSheet){
		dungeon_tileset_image,
		16, 16, 12, 11, 0
	};

	randomSprite = (Sprite){ dungeon_tileset, 1, 0 };

	// Set button styles
	buttonStyle = (ButtonStyle){ RED, GREEN, BLUE, 2.0f };
	textStyle = (TextStyle){ BLACK, WHITE, 16.0f };

	// Set Buttons
	startButton = (Button){
		(Quad) { 725, 400, 150, 75 },
		"Start",
		buttonStyle,
		textStyle,
		navigateToGame
	};

	settingsButton = (Button){
		(Quad) { 725, 500, 150, 75 },
		"Settings",
		buttonStyle,
		textStyle,
		navigateToSettings
	};

	exitButton = (Button){
		(Quad) { 725, 600, 150, 75 },
		"Exit",
		buttonStyle,
		textStyle,
		CP_Engine_Terminate
	};

}

void mainmenu_update(void) {
	// Background
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 128));
	
	// new background
	int scale = 100;
	for (int i = 0; i < WIDTH; i += scale) {
		for (int j = 0; j < HEIGHT; j += scale) {
			drawSprite(randomSprite, (Quad) { i, j, scale, scale }, 1, 128);
		}
	}
	
	// Title
	CP_Settings_Fill(BLACK);
	CP_Settings_TextSize(42.0f);
	CP_Font_DrawText("Curse of the null flame", WIDTH / 2, 200);

	// Buttons
	drawButton(startButton);
	drawButton(settingsButton);
	drawButton(exitButton);
}

void mainmenu_exit(void) {
	CP_Font_Free(font);
	CP_Image_Free(dungeon_tileset_image);
}
