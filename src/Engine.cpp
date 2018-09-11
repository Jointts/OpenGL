//
// Created by Joonas on 29/09/2016.
//

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "Engine.h"
#include "renderer/RenderManager.h"
#include "Time.h"
#include "gui/GuiWidget.h"
#include "gui/GuiManager.h"
#include "gui/Button.h"
#include "gui/GuiEvents.h"
#include "Utils.h"
#include "lights/DirectionalLight.h"
#include "lights/PointLight.h"
#include "geometry/DuplicatedVertexPlane.h"
#include <glm/gtc/matrix_transform.inl>
#include "maths/PoissonGenerator.h"
#include "gui/Text.h"
#include "scripts/Lua.h"
#include "controller/KeyBoardController.h"
//#include "audio/AudioManager.h"

int Engine::Start() {
    DisplayManager::getInstance();

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    ControllerManager::getInstance();
    CameraManager::getInstance();

    Lua::BindLua();
    Lua::LoadScript("main");

    Button *button = new Button(100, 100);
    button->setMarginLeft(50.0f);
    button->setMarginBottom(50.0f);
    button->collisionColor = glm::vec3(226, 65, 65);
    button->clickEvent     = std::bind(&GuiEvents::DEBUG_GUI);
    button->setTexture(static_cast<GLchar *>("res/nice_circle.png"));

    Model *character = new Model("res/model.dae");

    Text *text = new Text("Test Text", "LATO_LIGHT");

    DuplicatedVertexPlane *duplicatedVertexPlane = new DuplicatedVertexPlane(64, 64, false);
    duplicatedVertexPlane->calculatePointHeight(glm::vec2(1.5f, 2.25f));

    Event *event = new Event([=] { Lua::ReloadScript("test"); });
    KeyBoardController::BindKey(GLFW_KEY_Y, event);

    while (!glfwWindowShouldClose(DisplayManager::getInstance()->display->window)) {
        MouseController::getInstance()->resetClickedStates();
        glfwPollEvents();
        Time::calculateFrameTime();

        glEnable(GL_MULTISAMPLE);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        RenderManager::getInstance()->DrawGui();
        RenderManager::getInstance()->RenderBaseShader();

        duplicatedVertexPlane->Draw();
        character->Draw();
        text->Draw();

        GuiManager::getInstance()->guiEventListener->CheckEvents();

        glfwSwapBuffers(DisplayManager::getInstance()->display->window);
    }

    return -1;
}
