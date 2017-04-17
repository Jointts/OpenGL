//
// Created by Joonas on 06/10/2016.
//

#include <iostream>
#include <gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stb_image.h>
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb_image_resize.h>
#include "ControllerManager.h"

ControllerManager *ControllerManager::controllerManager = 0;

DisplayManager *displayManager = DisplayManager::getInstance();
CameraManager *cameraManager = 0;
int ControllerManager::EXIT_KEY = GLFW_KEY_ESCAPE;
GLfloat lastXpos = 0;
GLfloat lastYpos = 0;
GLfloat yaw = -90.0f;
GLfloat pitch = 0.0f;
bool firstMouse = true;

ControllerManager *ControllerManager::getInstance() {
    if (!controllerManager) {
        controllerManager = new ControllerManager();
    }
    return controllerManager;
}

ControllerManager::ControllerManager() {
    cameraManager = CameraManager::getInstance();
    glfwSetKeyCallback(displayManager->window, this->key_callback);
    int height = 0;
    int width = 0;
    int bytesPerPixel = 0;
    char *path = (char *) "/Users/joonas/CLionProjects/OpenGL/cmake-build-debug/res/cursor.png";
    unsigned char *pixelData = stbi_load(path, &width, &height, &bytesPerPixel, STBI_rgb_alpha);
    GLFWimage glfWimage;
    glfWimage.height = height;
    glfWimage.width = width;
    glfWimage.pixels = pixelData;

    GLFWcursor *glfWcursor = glfwCreateCursor(&glfWimage, 0, 0);
    glfwSetCursor(displayManager->window, glfWcursor);
    glfwSetCursorPosCallback(displayManager->window, this->mouse_callback);
}

void ControllerManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == EXIT_KEY && action == GLFW_PRESS) {
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }
    if (key == GLFW_KEY_A) {
        cameraManager->mainCamera->MoveLeft();
    }
    if (key == GLFW_KEY_D) {
        cameraManager->mainCamera->MoveRight();
    }
    if (key == GLFW_KEY_W) {
        cameraManager->mainCamera->MoveForward();
    }
    if (key == GLFW_KEY_S) {
        cameraManager->mainCamera->MoveBack();
    }
    if (key == GLFW_KEY_Q) {
        cameraManager->mainCamera->MoveUp();
    }
    if (key == GLFW_KEY_E) {
        cameraManager->mainCamera->MoveDown();
    }
}

void ControllerManager::mouse_callback(GLFWwindow *window, double xpos, double ypos) {

}
