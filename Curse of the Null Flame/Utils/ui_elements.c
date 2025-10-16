#include "cprocessing.h"
#include "../abstraction.h"
#include "ui_elements.h"

// @todo improve button draw and add click functionality

void drawButton(Button button) {
	CP_Settings_Fill(button.style.regular);
	if (pointInRect((Point){mouseX, mouseY }, button.properties)) {
		CP_Settings_Fill(button.style.hover);
		if (CP_Input_MouseClicked()) {
			button.callback();
		}
	}

	CP_Settings_StrokeWeight(button.style.strokeWeight);
	CP_Settings_Stroke(button.style.strokeColor);

	CP_Graphics_DrawRect(
		button.properties.position.x,
		button.properties.position.y,
		button.properties.width,
		button.properties.height
	);

	CP_Settings_Fill(button.text.color);
	CP_Settings_TextSize(button.text.size);
	CP_Font_DrawText(button.value, button.properties.position.x + button.properties.width / 2, button.properties.position.y + button.properties.height / 2);
}

void drawCheckbox(CheckBox box) {
	// Read the actual value safely
	int checked = box.value ? *box.value : 0;

	// base fill
	if (checked) fill(RED); else fill(WHITE);

	// hover and click handling
	if (pointInRect((Point) { mouseX, mouseY }, (Quad) { box.position, 25, 25 })) {
		// hover color
		fill(GREEN);

		// toggle stored value on click and call callback if present
		if (CP_Input_MouseClicked()) {
			if (box.value) {
				*box.value = !(*box.value);
			}
		}
	}

	// draw outer box
	rect(box.position.x, box.position.y, 25, 25);

	// draw inner indicator when checked
	if (checked) {
		fill(BLACK);
		rect(box.position.x + 5.0f, box.position.y + 5.0f, 15.0f, 15.0f);
	}
}

void drawProgressBar(ProgressBar bar) {
	// Background
	fill(bar.backgroundColor);
	rect(bar.properties.position.x, bar.properties.position.y, bar.properties.width, bar.properties.height);

	float currentValue = bar.value ? *bar.value : bar.min;

	// Clamp to min or max
	// TODO: maybe clamp the actual value instead of a pretend value
	if (currentValue < bar.min) currentValue = bar.min;
	if (currentValue > bar.max) currentValue = bar.max;

	float range = bar.max - bar.min;
	float percentage = (range > 0.0f) ? ((currentValue - bar.min) / range) : 0.0f;

	// Draw actual bar
	fill(bar.color);
	float fillWidth = bar.properties.width * percentage;
	rect(bar.properties.position.x, bar.properties.position.y, fillWidth, bar.properties.height);
};

// GAME UI
void drawGameUI() {
	// elements to consider
	// Hunger bar (progress bar > player.hunger)
	// 

	//Test: add border around screen:
	fill(CP_Color_Create(20, 204, 69, 255));
	rect(0, 0, 1600, 10);
	rect(0, 0, 10, 900);
	rect(1600 - 10, 0, 10, 900);
	rect(0, 900 - 10, 1600, 10);
}