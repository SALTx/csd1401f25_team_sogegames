#include "cprocessing.h"
#include "../abstraction.h"
#include "game_utils.h";
#include "../Utils/ui_elements.h"

// This will contain function definitions for
// Warpzones

// This isnt literally drawing anything, it just goes in the update
// Either rename or add proper documentation
void drawWarpZone(WarpZone zone, Point playerPosition) {
	// If debug is enabled, physically draw a rect to visualise
	if (zone.debug) {
		Quad properties = zone.properties;
		fill(CP_Color_Create(255, 0, 0, 255));
		rect(properties.position.x, properties.position.y, properties.width, properties.height);
	}
}

void handlePlayerMovement(Entity* player) {
	float moveSpeed = player->speed;

	int pressingUp = (CP_Input_KeyDown(KEY_W) || CP_Input_KeyDown(KEY_UP));
	int pressingDown = (CP_Input_KeyDown(KEY_S) || CP_Input_KeyDown(KEY_DOWN));
	int pressingLeft = (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT));
	int pressingRight = (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT));

	// If pressing up and the resultant movement doesnt bring them out of bounds
	if (pressingUp && (player->properties.position.y - moveSpeed) > 0)
	{
		player->properties.position.y -= moveSpeed;
	}

	if (pressingDown && (player->properties.position.y + moveSpeed) < HEIGHT - player->properties.height)
	{
		player->properties.position.y += moveSpeed;
	}

	if (pressingLeft && (player->properties.position.x - moveSpeed) > 0)
	{
		player->properties.position.x -= moveSpeed; player->facingDirection = -1;
	}

	if (pressingRight && (player->properties.position.x + moveSpeed) < WIDTH - player->properties.width)
	{
		player->properties.position.x += moveSpeed; player->facingDirection = 1;
	}

	if (pressingUp || pressingDown || pressingLeft || pressingRight) {
		// If any movement is happening, increase the hunger a little
		player->HP += 0.05f;
	}
}

void drawEntity(Entity entity) {
	// Draw the sprite
	drawSprite(
		entity.sprite,
		entity.properties,
		entity.facingDirection,
		255
	);

	// mini health bar
	ProgressBar healthBar = {
		(Quad) {entity.properties.position.x, entity.properties.position.y, entity.properties.width, 10},
		0.0f, 100.0f,
		&entity.HP,
		RED, WHITE
	};
	drawProgressBar(healthBar);
}
