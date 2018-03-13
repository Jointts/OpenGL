//
// Created by Joonas on 06/10/2016.
//

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stb_image.h>
#include <stb_image_resize.h>
#include <btBulletCollisionCommon.h>
#include "ControllerManager.h"
#include "../physics/PhysicsManager.h"
#include "../EntityManager.h"
#include "../gui/GuiManager.h"
#include "MouseController.h"


ControllerManager *ControllerManager::controllerManager = 0;
bool ControllerManager::mouseOneClicked = false;
bool ControllerManager::mouseOneReleased = false;
bool ControllerManager::mouseOneClickEventPropagate = false;
bool ControllerManager::mouseOneClickHoldEventPropagate = false;
int ControllerManager::lastMouseXPos = 0;
int ControllerManager::lastMouseYPos = 0;

DisplayManager *displayManager = DisplayManager::getInstance();
static MouseController *mouseController = 0;
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
    mouseController = MouseController::getInstance();

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

    if(key == GLFW_MOUSE_BUTTON_2){
        PhysicsManager::getInstance()->worldPhysics->mouseOneClicked = true;
    }else{
        PhysicsManager::getInstance()->worldPhysics->mouseOneClicked = false;
    }
}

void ControllerManager::mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    //PhysicsManager::getInstance()->worldPhysics->RayCast(xpos, ypos);
    GuiManager::getInstance()->guiFrameBuffer->ReadColor(xpos, ypos);
	if(MouseController::getInstance()->checkButtonInput(GLFW_MOUSE_BUTTON_LEFT, MouseEvent::HOLD) && lastMouseXPos != 0 && lastMouseXPos != 0)
	{
		int cameraMovementX = xpos - lastMouseXPos;
		int cameraMovementY = ypos - lastMouseYPos;

		CameraManager::getInstance()->mainCamera->MoveByX(cameraMovementX);
		CameraManager::getInstance()->mainCamera->MoveByZ(cameraMovementY);
	}

    lastMouseXPos = xpos;
    lastMouseYPos = ypos;
}

void ControllerManager::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    mouseController->insertKey(button);
}

void ControllerManager::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	CameraManager::getInstance()->mainCamera->MoveByY(yoffset);
}