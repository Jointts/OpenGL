//
// Created by joonas on 18.09.16.
//

#ifndef OPENGL_INPUT_H
#define OPENGL_INPUT_H
#include <GLFW/glfw3.h>

class Input {
public:
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
};


#endif //OPENGL_INPUT_H
