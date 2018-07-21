//
// Created by joonas on 16.09.16.
//

#ifndef OPENGL_DISPLAY_H
#define OPENGL_DISPLAY_H

#include "string"
#include <GLFW/glfw3.h>

class Display {
public:
    int width  = 0;
    int height = 0;

    GLFWwindow *window;

    Display(int width, int height, const char *title);
    ~Display();
};


#endif //OPENGL_DISPLAY_H
