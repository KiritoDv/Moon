#ifndef MOON_WINDOW_H
#define MOON_WINDOW_H

#include "data/types.h"
#include <GLFW/glfw3.h>

class Window {
public:
    GLFWwindow * window;
    Window(int monitor);
    Size windowSize;
    Size viewportSize;
};


#endif
