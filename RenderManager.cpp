//
// Created by Joonas on 06/10/2016.
//

#include <glad/glad.h>
#include <gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "RenderManager.h"
#include "Utils.h"
#include "lights/DirectionalLight.h"
#include "DisplayManager.h"
#include "ShaderManager.h"
#include "CameraManager.h"

RenderManager *RenderManager::renderManager = 0;

void RenderManager::Render() {
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    ShaderManager::getInstance()->celShader->Start();

    glUniformMatrix4fv(CameraManager::getInstance()->perspectiveLoc, 1, GL_FALSE, glm::value_ptr(CameraManager::getInstance()->projection));
    glUniformMatrix4fv(CameraManager::getInstance()->viewLoc, 1, GL_FALSE, glm::value_ptr(CameraManager::getInstance()->view));

//    ShaderManager::getInstance()->baseShader->Start();

    for (Model* model : models) {
        model->Draw();
    }

    glm::vec3 lightColor = Utils::color_RGB(255.0f, 255.0f, 255.0f);
    GLfloat lightStrength = 0.1f;
    glm::vec3 lightPos = {1.0f, 1.0f, 1.0f};

    DirectionalLight *directionalLight = new DirectionalLight(lightColor, lightStrength, lightPos);
    directionalLight->Enable();

    glfwSwapBuffers(DisplayManager::getInstance()->window);
}

RenderManager *RenderManager::getInstance() {
    if (!renderManager) {
        renderManager = new RenderManager();
    }
    return renderManager;
}
