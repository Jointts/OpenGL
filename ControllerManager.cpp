//
// Created by Joonas on 06/10/2016.
//

#include <iostream>
#include <gtc/matrix_transform.hpp>
#include <stdlib.h>
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
//    glfwSetCursorPosCallback(displayManager->window, this->mouse_callback);
    glfwSetInputMode(displayManager->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void ControllerManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == EXIT_KEY && action == GLFW_PRESS) {
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }
    if (key == GLFW_KEY_A) {
        cameraManager->MoveLeft();
    }
    if (key == GLFW_KEY_D) {
        cameraManager->MoveRight();
    }
    if (key == GLFW_KEY_W) {
        cameraManager->MoveForward();
    }
    if (key == GLFW_KEY_S) {
        cameraManager->MoveBack();
    }
    if (key == GLFW_KEY_Q) {
        cameraManager->MoveUp();
    }
    if (key == GLFW_KEY_E) {
        cameraManager->MoveDown();
    }
}

void ControllerManager::mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    if (firstMouse) {
        lastXpos = (float) xpos;
        lastYpos = (float) ypos;
        firstMouse = false;
    }
    yaw += sin(xpos - lastXpos);
    pitch += sin(lastYpos - ypos);
    lastXpos = (float) xpos;
    lastYpos = (float) ypos;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    cameraManager->eyePos.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    cameraManager->eyePos.y = sin(glm::radians(pitch));
    cameraManager->eyePos.z = sin(glm::radians(pitch)) * cos(glm::radians(yaw));
    cameraManager->eyePos = glm::normalize(cameraManager->eyePos);

    cameraManager->UpdateCamera();

//    std::cout << yaw << " " << pitch;
}
