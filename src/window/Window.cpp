#include "Window.h"
#include <iostream>
#include <utils/MathUtil.h>
#include <game/MoonLogic.h>

Window::Window(int monitor) {
    if(!glfwInit()){
        std::cout << "Failed to init GLFW" << std::endl;
    }

    GLFWmonitor* primary = glfwGetPrimaryMonitor();

    const GLFWvidmode* mode = glfwGetVideoMode(primary);

    this->windowSize = {320, 288};
    this->viewportSize = {160, 144};

    this->window = glfwCreateWindow(this->windowSize.x, this->windowSize.y, "Moonside", NULL, NULL);
    glfwSetWindowPos(this->window, 0, 0);

    if(!this->window){
        std::cout << "Failed to create window" << std::endl;
        glfwDestroyWindow(this->window);
    }

    glfwSetWindowUserPointer(this->window, this);
    glfwMakeContextCurrent(this->window);
    glfwSwapInterval(1);

    MoonLogic * logic = new MoonLogic();

    logic->window = this;

    logic->load();

    float time = 0;
    float oldTime = 0;

    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, this->windowSize.x, this->windowSize.y);
    glLoadIdentity();
    glOrtho(0, this->viewportSize.x, this->viewportSize.y, 0, -1, 1);

    while(!glfwWindowShouldClose(this->window)) {
        time = glfwGetTime();
        logic->deltaTime = ( time - oldTime );
        oldTime = time;

        logic->update();

        double xMPos, yMPos;
        glfwGetCursorPos(this->window, &xMPos, &yMPos);

        logic->mouse = { (float) xMPos, (float) yMPos };

        glClearColor(0, 0, 0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        logic->draw();

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
    logic->dispose();
    delete logic;
    glfwDestroyWindow(this->window);
    glfwTerminate();
}