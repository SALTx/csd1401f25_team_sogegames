#include "cprocessing.h"
#include "../abstraction.h"
#include "ui_elements.h"

// @todo improve button draw and add click functionality

void drawButton(Button button) {
	// Set the buttons color
	CP_Settings_Fill(button.style.regular);
	if (pointInRect((Point){mouseX, mouseY }, button.properties)) {
		CP_Settings_Fill(button.style.hover);
		if (CP_Input_MouseClicked()) {
			button.callback();
		}
	}

	// Set button style
	CP_Settings_StrokeWeight(button.style.strokeWeight);
	CP_Settings_Stroke(button.style.strokeColor);

	// Draw the rectangle
	CP_Graphics_DrawRect(
		button.properties.position.x,
		button.properties.position.y,
		button.properties.width,
		button.properties.height
	);

	// Draw the text
	CP_Settings_Fill(button.text.color);
	CP_Settings_TextSize(button.text.size);
	CP_Font_DrawText(button.value, button.properties.position.x + button.properties.width / 2, button.properties.position.y + button.properties.height / 2);
}
