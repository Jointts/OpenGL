//
// Created by Joonas on 29/09/2016.
//

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include <detail/type_mat.hpp>
#include <detail/type_mat4x4.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>
#include <glad/glad.h>
#include "Engine.h"
#include "RenderManager.h"
#include "physics/PhysicsManager.h"
#include "geometry/Quad.h"
#include "FreeType.h"
#include "Tree.h"
#include "Time.h"
#include "gui/GuiWidget.h"
#include "EntityManager.h"
#include "CEGUI/CEGUI.h"
#include "DuplicatedVertexPlane.h"

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

    PhysicsManager::getInstance()->Tick();
    //  Utter crap class, just for testing subclass pointers
    //Tree* tree = new Tree("res/tree_1.FBX", true);
    Player* player = new Player("res/tree_1.FBX", false);
    player->Translate(glm::vec3(-10.0f, 10.0f, 10.0f));
    //tree->Translate(glm::vec3(25, 5, 25));
    //tree->Rotate(90.0f, glm::vec3(1.0, 0.0, 0.0));
    //Entity* entity = new Entity("res/rock_1.FBX", true);
    //Entity* entity2 = new Entity("res/bunny/RRabbit.FBX", true);

/*    GuiWidget* guiWidget = new GuiWidget(100, 100);
    guiWidget->setMarginLeft(50.0f);
    guiWidget->setMarginBottom(50.0f);
    guiWidget->setTexture((GLchar *) "res/nice_circle.png");
    guiWidget->GenerateCollision();*/

/*    FreeType* freeType = new FreeType();
    freeType->Initalize();*/
    //Water *water = new Water(200, 200, 0, false);
    //plane->generateHeightMap = true;
    //Plane *water = new Plane(200, 200, 0, false);
    //Terrain *terrain = new Terrain(100, 100, 0, false);
    //terrain->terrain->GenerateRivers();
    //terrain->generateCollision();
    //terrain->AddTexture("res/van_gogh.jpg");
    DuplicatedVertexPlane *duplicatedVertexPlane = new DuplicatedVertexPlane(100, 100, true);
    duplicatedVertexPlane->setImage("res/van_gogh.jpg");

    while (!glfwWindowShouldClose(DisplayManager::getInstance()->window)) {
        glfwPollEvents();
        Time::calculateFrameTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glEnable(GL_MULTISAMPLE);

        PhysicsManager::getInstance()->Tick();
        RenderManager::getInstance()->DrawModels();
        duplicatedVertexPlane->Draw();
        //tree->Rotate(0.003f, glm::vec3(0.0f, 1.0f, 0.0f));
        //plane->Draw();
        //RenderManager::getInstance()->RenderCelShader();
        //water->Draw();
        //guiWidget->Draw();
        CEGUI::System::getSingleton().renderGUI() ;
        glfwSwapBuffers(DisplayManager::getInstance()->window);
    }

    return -1;
}

