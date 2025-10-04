#ifndef SPRITE_UTILS_H
#define SPRITE_UTILS_H

#include "cprocessing.h"
#include "shape_utils.h"

typedef struct {
	CP_Image spriteSheetImage;
	int spriteWidth;
	int spriteHeight;
	int spritesPerRow;
	int spritesPerColumn;
	int gap;
} SpriteSheet;

typedef struct {
	SpriteSheet spriteSheet;
	int row;
	int column;
} Sprite;

void drawSprite(Sprite sprite, Quad properties, int alpha);

#endif // SPRITE_UTILS_H
