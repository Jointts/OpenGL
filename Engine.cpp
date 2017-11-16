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
#include "renderer/RenderManager.h"
#include "physics/PhysicsManager.h"
#include "Time.h"
#include "EntityManager.h"
#include "Tree.h"
#include "gui/GuiWidget.h"
#include "gui/GuiManager.h"
#include "gui/Button.h"
#include "gui/GuiEvents.h"
#include "gamestate/GameStateManager.h"
#include "Utils.h"
#include "lights/DirectionalLight.h"
#include "lights/PointLight.h"
#include "geometry/DuplicatedVertexPlane.h"
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

    //Model* rock = new Model("res/rock_1.FBX");

    PhysicsManager::getInstance()->Tick();
    //  Utter crap class, just for testing subclass pointers
    Tree* tree = new Tree("res/tree_1.FBX", true);
    Player* player = new Player("res/models/fox.FBX", false);
    player->Translate(glm::vec3(-10.0f, 5.0f, 10.0f));
    player->Scale(glm::vec3(0.01f, 0.01f, 0.01f));
    player->setMovementSpeed(0.1f);
    tree->Translate(glm::vec3(5, 5, 5));
    Entity* entity = new Entity("res/rock_1.FBX", true);
    entity->Translate(glm::vec3(10, 5, 10));
    //Entity* entity2 = new Entity("res/bunny/RRabbit.FBX", true);

    Button* button = new Button(100, 100);
    button->setMarginLeft(50.0f);
    button->setMarginBottom(50.0f);
    button->collisionColor = glm::vec3(226, 65, 65);
    button->clickEvent = std::bind(&GuiEvents::DEBUG_PHYSICS);
    button->setTexture((GLchar *) "res/nice_circle.png");

    glm::vec3 lightColor = Utils::color_RGB(255.0f, 255.0f, 255.0f);
    GLfloat lightStrength = 0.5f;
    glm::vec3 lightPos = {1.0f, 1.0f, 1.0f};
    new DirectionalLight(lightColor, lightStrength, lightPos);

    glm::vec3 position = glm::vec3(10.f, 2.f, 10.f);
    glm::vec3 diffuse = Utils::color_RGB(255.f,127.f,80.f);
    float constant = 1.0f;
    float linear = 0.35f;
    float quadratic = 0.44f;
    new PointLight(
            position,
            diffuse,
            constant,
            linear,
            quadratic
    );

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
    DuplicatedVertexPlane *duplicatedVertexPlane = new DuplicatedVertexPlane(64, 64, true);
//    duplicatedVertexPlane->setImage("res/van_gogh.jpg");

    while (!glfwWindowShouldClose(DisplayManager::getInstance()->display->window)) {
        ControllerManager::mouseOneClickEventPropagate = false;
        glfwPollEvents();
        Time::calculateFrameTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0,0.0,0.0, 1.0);
        glEnable(GL_MULTISAMPLE);

        RenderManager::getInstance()->DrawGui();
        RenderManager::getInstance()->DrawModels();
        PhysicsManager::getInstance()->Tick();
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
        glfwSwapBuffers(DisplayManager::getInstance()->display->window);
    }

    return -1;
}

