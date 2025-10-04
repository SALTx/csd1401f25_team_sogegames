#include "cprocessing.h"
#include "../abstraction.h"
#include "game_screen.h"
#include "mainmenu.h"

#include "../Utils/sprite_utils.h"

// Load assets
CP_Font font;

// Temporary stuff
float playerX, playerY;
float playerSpeed = 5.0f;

int directionH = 1;

CP_Image spriteSheetImage;
SpriteSheet spriteSheet;
Sprite playerSprite;


void handleMovement() {
	if (CP_Input_KeyDown(KEY_W))
	{
		playerY -= playerSpeed;
	}
	if (CP_Input_KeyDown(KEY_S)) 
	{
		playerY += playerSpeed;
	}
	if (CP_Input_KeyDown(KEY_A)) 
	{
		playerX -= playerSpeed;
		directionH = -1;
	}
	if (CP_Input_KeyDown(KEY_D)) 
	{
		playerX += playerSpeed;
		directionH = 1;
	}
}


// END

void game_init(void) {
	font = CP_Font_Load("Assets/Fonts/Exo2-Regular.ttf");
	spriteSheetImage = CP_Image_Load("Assets/Sprites/dungeon_packed.png");
	spriteSheet = (SpriteSheet){ spriteSheetImage, 16, 16, 12, 11, 0 };
	playerSprite = (Sprite){ spriteSheet, 7, 0 };

	// Setup Text
	CP_Font_Set(font);
	textSize(16.0f);
	textAlign(2, 16);

	// Set player initial position
	playerX = 10;
	playerY = 10;
}

void drawPlayer(void) {
	fill(YELLOW);
	drawSprite(
		playerSprite,
		(Quad) { playerX + 50 * (directionH == -1), playerY, 50 * directionH, 50 },
		255
	);
	handleMovement();
}

void game_update(void) {
	// Reset background
	background(BLACK);

	fill(WHITE);
	text("Not implemented yet", WIDTH / 2, HEIGHT / 2);
	text("Press Q to go back", WIDTH / 2, HEIGHT / 2 + 16.0f);

	// WASD to move around
	drawPlayer();


	if (CP_Input_KeyTriggered(KEY_Q)) {
		CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	}
}

void game_exit(void) {
	CP_Font_Free(font);
	CP_Image_Free(spriteSheetImage);
}

