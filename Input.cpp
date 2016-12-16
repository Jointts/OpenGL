//
// Created by joonas on 18.09.16.
//

#include <cstdlib>
#include <iostream>
#include "Input.h"
#include "RenderManager.h"

const int EXIT_KEY = GLFW_KEY_ESCAPE;

void Input::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == EXIT_KEY && action == GLFW_PRESS) {
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }
}

void Input::startUp() {
    RenderManager::cameraPosition = 1;
}

