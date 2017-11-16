//
// Created by joonas on 16.09.16.
//

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include "Display.h"

Display::Display(int width, int height, const char *title) {
    if(!glfwInit()){
        std::cout << "Initialization failed!";
    }

    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    this->height= mode->height;
    this->width = mode->width;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 8);

    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if(!window){
        std::cout << "Failed to create a window!";
    }
    glfwMakeContextCurrent(window);
    glfwGetFramebufferSize(window, &width, &height);
}

Display::~Display() {
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
