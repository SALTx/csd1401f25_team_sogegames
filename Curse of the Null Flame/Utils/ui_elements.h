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

// A couple of untested UI elements, they will have the same style for now until after they work
// @todo add customizability

typedef struct {
	Point position;
	int* value; // Pointer to an actual value (like a toggle in settings)
	FunctionPtr callback; // Called every toggle
} CheckBox;

typedef struct {
	Quad properties;
	float min;
	float max;
	float* value;
	FunctionPtr callback; // Called when value changes
} Slider;

typedef struct {
	Quad properties;
	char value[64]; // or 128, see if the bigger number needed
	int isFocused; // 0 no, 1 yes // @todo find a way to have only one active at a time
	TextStyle text;
	FunctionPtr callback; // Called when value changes at the moment // @todo have it call on submit or button press
} TextInput;

void drawButton(Button button);

#endif
