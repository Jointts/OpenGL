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
