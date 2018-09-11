//
// Created by jointts on 9.03.18.
//

#include "MouseController.h"
#include "../display/DisplayManager.h"
#include "../gui/GuiManager.h"
#include "../camera/CameraManager.h"

MouseController   *MouseController::mouseController = nullptr;

MouseController *MouseController::getInstance() {
    if (!mouseController) {
        mouseController = new MouseController();
    }
    return mouseController;
}

void MouseController::ReceivePosEvent(GLFWwindow *pWwindow, double xpos, double ypos) {

//    GuiManager::getInstance()->guiFrameBuffer->ReadColor(xpos, ypos);
//    if (MouseController::getInstance()->checkButtonInput(GLFW_MOUSE_BUTTON_LEFT, KeyState::HOLD) &&
//        lastMouseXPos != 0) {
//        int cameraMovementX = xpos - lastMouseXPos;
//        int cameraMovementY = ypos - lastMouseYPos;
//
//        CameraManager::getInstance()->mainCamera->MoveByX(cameraMovementX);
//        CameraManager::getInstance()->mainCamera->MoveByZ(cameraMovementY);
//    }
//
//    lastMouseXPos = xpos;
//    lastMouseYPos = ypos;
}

void MouseController::ReceiveKeyEvent(GLFWwindow *window, int button, int action, int mods) {
    MouseController::getInstance()->insertKey(button);
}


void MouseController::ReceiveScrollEvent(GLFWwindow *window, double xoffset, double yoffset) {
    CameraManager::getInstance()->mainCamera->MoveByY(yoffset);
}

