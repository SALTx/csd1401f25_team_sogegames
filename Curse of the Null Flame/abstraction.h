#ifndef ABSTRACTION_H
#define ABSTRACTION_H

// Colors
#define BLACK CP_Color_Create(0, 0, 0, 255)
#define WHITE CP_Color_Create(255, 255, 255, 255)

#define RED CP_Color_Create(255, 0, 0, 255)
#define GREEN CP_Color_Create(0, 255, 0, 255)
#define BLUE CP_Color_Create(0, 0, 255, 255)
#define YELLOW CP_Color_Create(255, 255, 0, 255)


// Window
#define WIDTH CP_System_GetWindowWidth()
#define HEIGHT CP_System_GetWindowHeight()

#endif // ABSTRACTION_H
