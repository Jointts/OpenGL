//
// Created by Joonas on 06/10/2016.
//

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include <iostream>
#include <gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stb_image.h>
#include <stb_image_resize.h>
#include <btBulletCollisionCommon.h>
#include "ControllerManager.h"
#include "physics/PhysicsManager.h"
#include "EntityManager.h"
#include "gui/GuiManager.h"


ControllerManager *ControllerManager::controllerManager = 0;
bool ControllerManager::mouseOneClicked = false;
bool ControllerManager::mouseOneReleased = false;
bool ControllerManager::mouseOneClickEventPropagate = false;

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
    glfwSetKeyCallback(displayManager->display->window, this->key_callback);
    int height = 0;
    int width = 0;
    int bytesPerPixel = 0;
    char *path = (char *) "C:\\Users\\Joonas\\ClionProjects\\OpenGL\\res\\cursor.png";
    unsigned char *pixelData = stbi_load(path, &width, &height, &bytesPerPixel, STBI_rgb_alpha);
    GLFWimage glfWimage;
    glfWimage.height = height;
    glfWimage.width = width;
    glfWimage.pixels = pixelData;

    GLFWcursor *glfWcursor = glfwCreateCursor(&glfWimage, 0, 0);
//    glfwSetCursor(displayManager->window, glfWcursor);
    glfwSetCursorPosCallback(displayManager->display->window, this->mouse_callback);
    glfwSetMouseButtonCallback(displayManager->display->window, this->mouse_button_callback);
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
    PhysicsManager::getInstance()->worldPhysics->RayCast(xpos, ypos);
    GuiManager::getInstance()->guiFrameBuffer->ReadColor(xpos, ypos);
}

void ControllerManager::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    mouseOneReleased = button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE;

    if(mouseOneClicked && mouseOneReleased){
        mouseOneClickEventPropagate = true;
    }

    mouseOneClicked = button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS;
    PhysicsManager::getInstance()->worldPhysics->mouseOneClicked = mouseOneClicked;
}
