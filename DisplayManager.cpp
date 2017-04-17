//
// Created by Joonas on 06/10/2016.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "DisplayManager.h"

DisplayManager *DisplayManager::displayManager = 0;

DisplayManager::DisplayManager(const char *title) {
    if(!glfwInit()){
        std::cout << "Initialization failed!";
    }

    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    height= mode->height;
    width = mode->width;

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

DisplayManager *DisplayManager::getInstance() {
    if(!displayManager){
        displayManager = new DisplayManager("OpenGL");
    }
    return displayManager;
}

DisplayManager::~DisplayManager() {
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}