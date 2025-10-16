#include "cprocessing.h"
#include "../abstraction.h"
#include "game_screen.h"
#include "mainmenu.h"

#include "../Utils/sprite_utils.h"
#include "../Utils/ui_elements.h"
#include "../Utils/collision_utils.h"

// Local struct definitions
typedef struct {
	Quad properties;
	Sprite sprite;
	float HP; // Hunger
	float speed;
	int facingDirection; // -1 left : 1 right
} Player;

typedef struct {
	Quad properties;
	CP_Image image;
	float healAmount;
} Food;


// Load assets
CP_Font font;

// Temporary stuff
int directionH = 1;

ProgressBar hungerBar;

CP_Image spriteSheetImage;
SpriteSheet spriteSheet;
Sprite playerSprite;

CP_Image chickenImage;
CP_Sound chickenSound;

// Player
Player player;

Food chickenFood;


void handlePlayerMovement() {
	float moveSpeed = player.speed;

	int pressingUp = (CP_Input_KeyDown(KEY_W) || CP_Input_KeyDown(KEY_UP));
	int pressingDown = (CP_Input_KeyDown(KEY_S) || CP_Input_KeyDown(KEY_DOWN));
	int pressingLeft = (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT));
	int pressingRight = (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT));

	if (pressingUp)
	{ player.properties.position.y -= moveSpeed; }
	
	if (pressingDown) 
	{ player.properties.position.y += moveSpeed; }
	
	if (pressingLeft) 
	{ player.properties.position.x -= moveSpeed; player.facingDirection = -1; }
	
	if (pressingRight) 
	{ player.properties.position.x += moveSpeed; player.facingDirection = 1; }

	if (pressingUp || pressingDown || pressingLeft || pressingRight) {
		// If any movement is happening, increase the hunger a little
		player.HP += 0.05f;
	}
}


// END

void game_init(void) {
	font = CP_Font_Load("Assets/Fonts/Exo2-Regular.ttf");
	spriteSheetImage = CP_Image_Load("Assets/Sprites/dungeon_packed.png");
	spriteSheet = (SpriteSheet){ spriteSheetImage, 16, 16, 12, 11, 0 };
	playerSprite = (Sprite){ spriteSheet, 7, 0 };

	chickenImage = CP_Image_Load("Assets/Sprites/chicken.png");
	chickenSound = CP_Sound_Load("Assets/Sounds/food-test.wav");

	// Setup Text
	CP_Font_Set(font);
	textSize(16.0f);
	textAlign(2, 16);

	// Initialize player
	player = (Player){
		(Quad) {10, 10, 50, 50 },
		playerSprite,
		50.0f, // Hunger
		5.0f, // Speed
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

void drawPlayer(void) {
	drawSprite(
		player.sprite,
		player.properties,
		player.facingDirection,
		255
	);
	handlePlayerMovement();
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

	//// Not implemented yet 
	//fill(WHITE);
	//text("Not implemented yet", WIDTH / 2, HEIGHT / 2);
	//text("Press Q to go back", WIDTH / 2, HEIGHT / 2 + 16.0f);

	// Draw the chicken
	drawFood(&chickenFood);

	//Player draw and controls
	drawPlayer();

	//Game UI
	drawGameUI();

	// draw hunger bar
	drawProgressBar(hungerBar);


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

