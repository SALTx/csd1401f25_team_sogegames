#ifndef ABSTRACTION_H
#define ABSTRACTION_H

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

#endif // ABSTRACTION_H
