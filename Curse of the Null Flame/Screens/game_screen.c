#include "cprocessing.h"
#include "../abstraction.h"
#include "game_screen.h"
#include "mainmenu.h"

#include "../Utils/sprite_utils.h"
#include "../Utils/ui_elements.h"
#include "../Utils/collision_utils.h"
#include "../Utils/game_utils.h"

//Levels (temporary, probably)
#include "../Levels/level1.h";

//Global for now
int level = 1;

// Local struct definitions
typedef struct {
	Quad properties;
	CP_Image image;
	float healAmount;
} Food;


// Assets
CP_Font font;

CP_Image spriteSheetImage;
SpriteSheet spriteSheet;
Sprite playerSprite;
Sprite enemySprite;

CP_Image chickenImage;
CP_Sound chickenSound;

// Player and structs
Entity player;
ProgressBar hungerBar;
Food chickenFood;

Entity enemy;


void game_init(void) {
	font = CP_Font_Load("Assets/Fonts/Exo2-Regular.ttf");
	spriteSheetImage = CP_Image_Load("Assets/Sprites/dungeon_packed.png");
	spriteSheet = (SpriteSheet){ spriteSheetImage, 16, 16, 12, 11, 0 };
	playerSprite = (Sprite){ spriteSheet, 7, 0 };
	enemySprite = (Sprite){ spriteSheet, 10, 0 };

	chickenImage = CP_Image_Load("Assets/Sprites/chicken.png");
	chickenSound = CP_Sound_Load("Assets/Sounds/food-test.wav");

	// Setup Text
	CP_Font_Set(font);
	textSize(16.0f);
	textAlign(2, 16);

	// Initialize player
	player = (Entity){
		(Quad) {10, 10, 50, 50 },
		playerSprite,
		50.0f, // Hunger
		5.0f, // Speed
		1 // facing direction
	};

	enemy = (Entity){
		(Quad) {500, 500, 50, 50 },
		enemySprite,
		100.0f, // Health
		0.5f, // Speed
		1 // facing direction
	};

	// Initialize hunger bar
	hungerBar = (ProgressBar){
		(Quad) { 100, 100, 1400, 50 },
		0.0f, 100.0f,
		&player.HP,
		RED,
		BLACK
	};

	chickenFood = (Food){
		(Quad) { 800, 450, 50, 50 },
		chickenImage,
		20.0f,
	};
}

void drawEntities(void) {
	// Player
	drawEntity(player);
	handlePlayerMovement(&player);

	//Enemy
	drawEntity(enemy);
	enemy.properties.position.x += (player.properties.position.x - enemy.properties.position.x > 0) ? -enemy.speed : enemy.speed;
	enemy.properties.position.y += (player.properties.position.y - enemy.properties.position.y > 0) ? -enemy.speed : enemy.speed;
}

void drawFood(Food* food) {
	Point foodPosition = food->properties.position;
	CP_Image_Draw(food->image, foodPosition.x, foodPosition.y, food->properties.width, food->properties.height, 255);

	// If there is collision
	if (rectInRect(player.properties, food->properties)) {
		// Reset the food position
		food->properties.position.x = CP_Random_GetFloat() * 1600;
		food->properties.position.y = CP_Random_GetFloat() * 900;

		CP_Sound_Play(chickenSound);
		player.HP -= food->healAmount;
	}
}

void game_update(void) {
	// Reset background
	background(BLACK);

	// Draw the chicken
	drawFood(&chickenFood);

	//Player draw and controls
	drawEntities();

	//Game UI
	drawGameUI();

	// draw hunger bar
	drawProgressBar(hungerBar);


	//if (level == 1) {
	//	level1();
	//}
	//else if (level == 2) {
	//	level2();
	//}
	//else if (level == 3) {
	//	level3();
	//}

	//if (CP_Input_MouseClicked()) {
	//	level = (level >= 3) ? 1 : ++level;
	//}

	// Get back to menu with Q
	if (CP_Input_KeyTriggered(KEY_Q)) {
		CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	}
}

void game_exit(void) {
	CP_Font_Free(font);
	CP_Image_Free(spriteSheetImage);
	CP_Image_Free(chickenImage);
	CP_Sound_Free(chickenSound);
}

