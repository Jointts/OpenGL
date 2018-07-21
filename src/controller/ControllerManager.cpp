//
// Created by Joonas on 06/10/2016.
//



#include <iostream>
#include "ControllerManager.h"
#include "../physics/PhysicsManager.h"
#include "../gui/GuiManager.h"


ControllerManager *ControllerManager::controllerManager = nullptr;
int               ControllerManager::lastMouseXPos      = 0;
int               ControllerManager::lastMouseYPos      = 0;
int               ControllerManager::EXIT_KEY           = GLFW_KEY_ESCAPE;

ControllerManager *ControllerManager::getInstance() {
    if (!controllerManager) {
        controllerManager = new ControllerManager();
    }
    return controllerManager;
}

// TODO: Should be observed by mouseController, remove mousecontroller specific code out from here

ControllerManager::ControllerManager() {
    DisplayManager *displayManager = DisplayManager::getInstance();

    glfwSetKeyCallback(displayManager->display->window, this->key_callback);
    glfwSetCursorPosCallback(displayManager->display->window, this->mouse_callback);
    glfwSetMouseButtonCallback(displayManager->display->window, this->mouse_button_callback);
    glfwSetScrollCallback(displayManager->display->window, this->scroll_callback);
    glfwSetInputMode(displayManager->display->window, GLFW_STICKY_MOUSE_BUTTONS, 1);
}

void ControllerManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == EXIT_KEY && action == GLFW_PRESS) {
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    PhysicsManager::getInstance()->worldPhysics->mouseOneClicked = key == GLFW_MOUSE_BUTTON_2;
}

void ControllerManager::mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    //PhysicsManager::getInstance()->worldPhysics->RayCast(xpos, ypos);
    GuiManager::getInstance()->guiFrameBuffer->ReadColor(xpos, ypos);
    if (MouseController::getInstance()->checkButtonInput(GLFW_MOUSE_BUTTON_LEFT, MouseEvent::HOLD) &&
        lastMouseXPos != 0) {
        int cameraMovementX = xpos - lastMouseXPos;
        int cameraMovementY = ypos - lastMouseYPos;

        CameraManager::getInstance()->mainCamera->MoveByX(cameraMovementX);
        CameraManager::getInstance()->mainCamera->MoveByZ(cameraMovementY);
    }

    lastMouseXPos = xpos;
    lastMouseYPos = ypos;
}

void ControllerManager::mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    MouseController::getInstance()->insertKey(button);
}

void ControllerManager::scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    CameraManager::getInstance()->mainCamera->MoveByY(yoffset);
}
