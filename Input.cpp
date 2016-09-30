//
// Created by joonas on 18.09.16.
//

#include <cstdlib>
#include <iostream>
#include "Input.h"

const int EXIT_KEY = GLFW_KEY_ESCAPE;

class Engine;

void Input::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == EXIT_KEY && action == GLFW_PRESS) {
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }
}

