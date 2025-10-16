#include "cprocessing.h"
#include "../abstraction.h"
#include "game_utils.h";

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