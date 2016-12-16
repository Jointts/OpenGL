//
// Created by Joonas on 06/10/2016.
//

#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include "DisplayManager.h"

DisplayManager *DisplayManager::displayManager = 0;

DisplayManager::DisplayManager(int width, int height, const char *title) {
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

DisplayManager *DisplayManager::getInstance() {
    if(!displayManager){
        displayManager = new DisplayManager(3440, 1440, "OpenGL");
    }
    return displayManager;
}

DisplayManager::~DisplayManager() {
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}