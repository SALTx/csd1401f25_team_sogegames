#include "cprocessing.h"
#include "../abstraction.h"
#include "ui_elements.h"

void drawButton(Button button) {
	CP_Settings_Fill(button.style.regular);
	if (pointInRect((Point){mouseX, mouseY }, button.properties)) {
		CP_Settings_Fill(button.style.hover);
	}

	CP_Graphics_DrawRect(
		button.properties.position.x,
		button.properties.position.y,
		button.properties.width,
		button.properties.height
	);

	// Draw the text
	CP_Settings_Fill(button.text.color);
	CP_Settings_TextSize(button.text.size);
	CP_Font_DrawText(button.text.value, button.properties.position.x + button.properties.width / 2, button.properties.position.y + button.properties.height / 2);
}
