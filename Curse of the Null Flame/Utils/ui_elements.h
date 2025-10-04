#ifndef UI_ELEMENTS_H
#define UI_ELEMENTS_H

#include "shape_utils.h"

// @todo: figure out default values for the ButtonStyle and TextStyle
// @todo: improve button draw and implement click handler

typedef struct {
	CP_Color regular;
	CP_Color hover;
	CP_Color strokeColor;
	float strokeWeight;
} ButtonStyle;

typedef struct {
	CP_Color color;
	CP_Color alt_color;
	float size;
} TextStyle;

typedef struct {
	Quad properties;
	char value[32];
	ButtonStyle style;
	TextStyle text;
	FunctionPtr callback;
} Button;

void drawButton(Button button);

#endif
