#ifndef ABSTRACTION_H
#define ABSTRACTION_H

//Static Game Vars
#define GAME_NAME "Curse of the Null Flame"

// Colors
#define BLACK CP_Color_Create(0, 0, 0, 255)
#define WHITE CP_Color_Create(255, 255, 255, 255)

#define RED CP_Color_Create(255, 0, 0, 255)
#define GREEN CP_Color_Create(0, 255, 0, 255)
#define BLUE CP_Color_Create(0, 0, 255, 255)
#define YELLOW CP_Color_Create(255, 255, 0, 255)

// Input
#define mouseX CP_Input_GetMouseX()
#define mouseY CP_Input_GetMouseY()

// Window
#define WIDTH CP_System_GetWindowWidth()
#define HEIGHT CP_System_GetWindowHeight()

// Shapes and background
#define background CP_Graphics_ClearBackground
#define fill CP_Settings_Fill
#define ellipse CP_Graphics_DrawEllipse
#define rect CP_Graphics_DrawRect

// Font and text
#define text CP_Font_DrawText
#define textSize CP_Settings_TextSize
#define textAlign CP_Settings_TextAlignment

// Position vars
#define CENTER 0
#define CORNER 1

#endif // ABSTRACTION_H
