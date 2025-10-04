#ifndef UI_ELEMENTS_H
#define UI_ELEMENTS_H

#include "shape_utils.h"

//
typedef struct {
	CP_Color regular;
	CP_Color hover;
	CP_Color strokeColor;
	float strokeWeight;
} ButtonStyle;

typedef struct {
	char value[32];
	CP_Color color;
	CP_Color alt_color;
	float size;
} TextStyle;

// Element definitions
typedef struct {
	Quad properties;
	ButtonStyle style;
	TextStyle text;
} Button;


// DEFAULTS
//ButtonStyle ButtonStyle_Default() {
//	return (ButtonStyle) {
//		.regular = CP_Color_Create(200, 200, 200, 255),
//			.hover = CP_Color_Create(220, 220, 220, 255),
//			.strokeColor = CP_Color_Create(0, 0, 0, 255),
//			.strokeWeight = 1.0f
//	};
//}

void drawButton(Button button);

#endif
