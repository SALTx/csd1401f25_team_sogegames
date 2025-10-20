#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include "shape_utils.h"
#include "sprite_utils.h"

typedef struct {
	Quad properties;
	Sprite sprite;
	float HP; // Hunger
	float speed;
	int facingDirection; // -1 left : 1 right
} Entity;

typedef struct {
	Quad properties;
	FunctionPtr warp;
	int debug;
} WarpZone;


void drawWarpZone(WarpZone zone, Point playerPosition);
void handlePlayerMovement(Entity* player);
void drawEntity(Entity entity);

#endif // GAME_UTILS_H
