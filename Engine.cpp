//
// Created by Joonas on 29/09/2016.
//

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include <detail/type_mat.hpp>
#include <detail/type_mat4x4.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>
#include <glad/glad.h>
#include "Engine.h"
#include "Model.h"
#include "RenderManager.h"
#include "PhysicsManager.h"

int Engine::Start() {
    DisplayManager::getInstance();

    glfwInit();

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    ControllerManager::getInstance();
    PhysicsManager::getInstance()->physicsManager->InitPhysics();

    Model* rock = new Model("res\\rock_1.FBX");
    Model* tree = new Model("res\\tree_1.FBX");

    while (!glfwWindowShouldClose(DisplayManager::getInstance()->window)) {
        glfwPollEvents();
        RenderManager::getInstance()->Render();
    }
}

