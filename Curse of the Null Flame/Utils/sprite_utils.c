#include "cprocessing.h"
#include "../abstraction.h"
#include "sprite_utils.h"

void drawSprite(Sprite sprite, Quad properties, int alpha) {
	int t0 = sprite.row * (sprite.spriteSheet.spriteHeight + sprite.spriteSheet.gap);
	int s0 = sprite.column * (sprite.spriteSheet.spriteWidth + sprite.spriteSheet.gap);

	CP_Image_DrawSubImage(
		sprite.spriteSheet.spriteSheetImage,
		properties.position.x, properties.position.y,
		properties.width, properties.height,
		s0, t0,
		s0 + sprite.spriteSheet.spriteWidth, t0 + sprite.spriteSheet.spriteHeight,
		alpha
	);
}
