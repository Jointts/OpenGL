//
// Created by Joonas on 29/09/2016.
//

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include <detail/type_mat.hpp>
#include <detail/type_mat4x4.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>
#include "Engine.h"
#include "RenderManager.h"
#include "physics/PhysicsManager.h"
#include "Time.h"
#include "EntityManager.h"
#include "DuplicatedVertexPlane.h"
#include "Tree.h"
#include "gui/GuiWidget.h"
#include "gui/GuiManager.h"
#include "gui/Button.h"
#include "gui/GuiEvents.h"
#include "gamestate/GameStateManager.h"
//#include "audio/AudioManager.h"

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
    Tree* tree = new Tree("res/tree_1.FBX", true);
    Player* player = new Player("res/tree_1.FBX", true);
    player->Translate(glm::vec3(-10.0f, 5.0f, 10.0f));
    player->Scale(glm::vec3(0.3f, 0.3f, 0.3f));
    player->setMovementSpeed(0.1f);
    tree->Translate(glm::vec3(5, 5, 5));
    Entity* entity = new Entity("res/rock_1.FBX", true);
    entity->Translate(glm::vec3(10, 5, 10));
    //Entity* entity2 = new Entity("res/bunny/RRabbit.FBX", true);

    Button* button = new Button(100, 100);
    button->setMarginLeft(50.0f);
    button->setMarginBottom(50.0f);
    button->collisionColor = glm::vec3(226, 65, 65);
    button->clickEvent = std::bind(&GuiEvents::DEBUG_GUI);
    button->setTexture((GLchar *) "res/nice_circle.png");

    GameStateManager::getInstance();

/*    FreeType* freeType = new FreeType();
    freeType->Initalize();*/
    //Water *water = new Water(200, 200, 0, false);
    //plane->generateHeightMap = true;
    //Plane *water = new Plane(200, 200, 0, false);
//    Terrain *terrain = new Terrain(100, 100, 0, true);
    //terrain->terrain->GenerateRivers();
    //terrain->generateCollision();
    //terrain->AddTexture("res/van_gogh.jpg");
    DuplicatedVertexPlane *duplicatedVertexPlane = new DuplicatedVertexPlane(100, 100, true);
//    duplicatedVertexPlane->setImage("res/van_gogh.jpg");

    while (!glfwWindowShouldClose(DisplayManager::getInstance()->window)) {
        ControllerManager::mouseOneClickEventPropagate = false;
        glfwPollEvents();
        Time::calculateFrameTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.5, 0.5, 0.5, 1.0);
        glEnable(GL_MULTISAMPLE);

        PhysicsManager::getInstance()->worldPhysics->debugDrawing = true;

        PhysicsManager::getInstance()->Tick();

        RenderManager::getInstance()->DrawGui();
        RenderManager::getInstance()->DrawModels();
//        AudioManager::getInstance()->getInstance();

        GuiManager::getInstance()->guiEventListener->CheckEvents();

        duplicatedVertexPlane->Draw();
//        terrain->Draw();
        //tree->Rotate(0.003f, glm::vec3(0.0f, 1.0f, 0.0f));
        //plane->Draw();
        //RenderManager::getInstance()->RenderCelShader();
        //water->Draw();
//        guiWidget->Draw();
//        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        glfwSwapBuffers(DisplayManager::getInstance()->window);
    }

    return -1;
}

