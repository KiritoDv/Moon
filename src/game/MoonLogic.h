//
// Created by alex on 30/08/20.
//

#ifndef MOON_MOONLOGIC_H
#define MOON_MOONLOGIC_H

#include <data/types.h>

class Window;

class MoonLogic {
public:

    Window * window;
    float deltaTime;
    Vec2f mouse;

    void load();
    void update();
    void draw();
    void dispose();
};


#endif //MOON_MOONLOGIC_H
