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
#include "physics/PhysicsManager.h"
#include "ShaderManager.h"
#include "geometry/Plane.h"
#include "geometry/Quad.h"
#include "FreeType.h"
#include "DebugDrawer.h"
#include "Entity.h"
#include "Tree.h"
#include "Terrain.h"
#include "water/Water.h"
#include "Time.h"
#include "gui/GuiWidget.h"
#include "EntityController.h"
#include "EntityManager.h"

#include <sys/time.h>


int Engine::Start() {

    DisplayManager::getInstance();

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    ControllerManager::getInstance();
    PhysicsManager* physicsManager = PhysicsManager::getInstance()->physicsManager;
    physicsManager->worldPhysics->InitPhysics();
    physicsManager->guiPhysics->InitPhysics();

    //Model* rock = new Model("res/rock_1.FBX");

    //  Utter crap class, just for testing subclass pointers
    Tree* tree = new Tree("res/tree_1.FBX", true);
    tree->Translate(glm::vec3(25, 5, 25));
    tree->Rotate(90.0f, glm::vec3(1.0, 0.0, 0.0));
    Entity* entity = new Entity("res/rock_1.FBX", true);

    GuiWidget* guiWidget = new GuiWidget(100, 100);
    guiWidget->setMarginLeft(50.0f);
    guiWidget->setMarginBottom(50.0f);
    guiWidget->setTexture((GLchar *) "res/nice_circle.png");
    guiWidget->GenerateCollision();

    FreeType* freeType = new FreeType();
    freeType->Initalize();
    //Water *water = new Water(200, 200, 0, false);
    //plane->generateHeightMap = true;
    //Plane *water = new Plane(200, 200, 0, false);
    Entity *terrain = new Entity();
    //terrain->GenerateRivers();
    terrain->terrain->generateCollision();
    EntityManager *entityManager = EntityManager::getInstance();
    entityManager->playerController->setMovementSpeed(0.5f);

    while (!glfwWindowShouldClose(DisplayManager::getInstance()->window)) {
        glfwPollEvents();
        Time::calculateFrameTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glEnable(GL_MULTISAMPLE);

        PhysicsManager::getInstance()->Tick();
        //RenderManager::getInstance()->DrawModels();
        //RenderManager::getInstance()->RenderCelShader();
        //tree->Rotate(0.003f, glm::vec3(0.0f, 1.0f, 0.0f));
        //plane->Draw();
        //RenderManager::getInstance()->RenderCelShader();
        //terrain->Draw();
        //water->Draw();
        //guiWidget->Draw();
        glfwSwapBuffers(DisplayManager::getInstance()->window);
    }

}

