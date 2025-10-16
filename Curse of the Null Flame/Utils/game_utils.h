#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include "shape_utils.h"

typedef struct {
	Quad properties;
	FunctionPtr warp;
	int debug;
} WarpZone;


#endif // GAME_UTILS_H
