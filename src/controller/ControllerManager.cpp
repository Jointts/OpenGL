//
// Created by Joonas on 06/10/2016.
//



#include "ControllerManager.h"
#include "KeyBoardController.h"


ControllerManager *ControllerManager::controllerManager = nullptr;

ControllerManager *ControllerManager::getInstance() {
    if (!controllerManager) {
        controllerManager = new ControllerManager();
    }
    return controllerManager;
}

ControllerManager::ControllerManager() {
    DisplayManager *displayManager = DisplayManager::getInstance();

    glfwSetKeyCallback(displayManager->display->window, KeyBoardController::ReceiveKeyEvent);
    glfwSetCursorPosCallback(displayManager->display->window, MouseController::ReceivePosEvent);
    glfwSetMouseButtonCallback(displayManager->display->window, MouseController::ReceiveKeyEvent);
    glfwSetScrollCallback(displayManager->display->window, MouseController::ReceiveScrollEvent);

    glfwSetInputMode(displayManager->display->window, GLFW_STICKY_MOUSE_BUTTONS, 1);
}
