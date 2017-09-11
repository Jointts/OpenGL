//
// Created by Joonas on 06/10/2016.
//

#include <glad/glad.h>
#include <gtc/type_ptr.hpp>
#include "RenderManager.h"
#include "Utils.h"
#include "lights/DirectionalLight.h"
#include "ShaderManager.h"
#include "camera/CameraManager.h"
#include "gui/GuiWidget.h"
#include "EntityManager.h"

RenderManager *RenderManager::renderManager = 0;

    void RenderManager::RenderCelShader() {
        CameraManager *cameraManager = CameraManager::getInstance();
        ShaderProgram *celShader = ShaderManager::getInstance()->celShader;

        celShader->Start();

        GLint perspectiveLoc = glGetUniformLocation(celShader->shaderProgramID, "perspective");
        glUniformMatrix4fv(perspectiveLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->mainCamera->perspective));

        GLint viewLoc = glGetUniformLocation(celShader->shaderProgramID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->mainCamera->view));

        GLint modelLoc = glGetUniformLocation(celShader->shaderProgramID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4()));

        GLint vertexColorLoc = glGetUniformLocation(celShader->shaderProgramID, "vertex_color");
        glUniform3f(vertexColorLoc, 0.5f, 0.5f, 0.5f);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_CCW);
    }

    void RenderManager::RenderWaterShader() {
        CameraManager *cameraManager = CameraManager::getInstance();
        ShaderProgram *waterShader = ShaderManager::getInstance()->waterShader;

        waterShader->Start();

        GLint perspectiveLoc = glGetUniformLocation(waterShader->shaderProgramID, "perspective");
        glUniformMatrix4fv(perspectiveLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->mainCamera->perspective));

        GLint viewLoc = glGetUniformLocation(waterShader->shaderProgramID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->mainCamera->view));

        glEnable(GL_CULL_FACE);
        glCullFace(GL_CCW);
        glEnable(GL_DEPTH_TEST);
    }


    void RenderManager::RenderBaseShader() {
        CameraManager *cameraManager = CameraManager::getInstance();
        ShaderProgram *baseShader = ShaderManager::getInstance()->baseShader;

        baseShader->Start();

        GLint perspectiveLoc = glGetUniformLocation(baseShader->shaderProgramID, "perspective");
        glUniformMatrix4fv(perspectiveLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->mainCamera->perspective));

        GLint viewLoc = glGetUniformLocation(baseShader->shaderProgramID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->mainCamera->view));

        GLint modelLoc = glGetUniformLocation(baseShader->shaderProgramID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4()));

        glDisable(GL_CULL_FACE);
        glEnable(GL_DEPTH_TEST);

        glm::vec3 lightColor = Utils::color_RGB(255.0f, 255.0f, 255.0f);
        GLfloat lightStrength = 0.2f;
        glm::vec3 lightPos = {1.0f, 1.0f, 1.0f};

        DirectionalLight *directionalLight = new DirectionalLight(lightColor, lightStrength, lightPos);
        directionalLight->Enable();

    }

    void RenderManager::RenderGuiShader() {
        ShaderProgram *guiShader = ShaderManager::getInstance()->guiShader;
        GuiCamera *guiCamera = CameraManager::getInstance()->guiCamera;

        guiShader->Start();
        int projectionLoc = glGetUniformLocation(guiShader->shaderProgramID, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(guiCamera->perspective));
        glDisable(GL_CULL_FACE);
    }

    void RenderManager::RenderDebugShader() {
        ShaderProgram *debugShader = ShaderManager::getInstance()->debugShader;
        MainCamera *mainCamera = CameraManager::getInstance()->mainCamera;

        debugShader->Start();

        GLint perspectiveLoc = glGetUniformLocation(debugShader->shaderProgramID, "perspective");
        glUniformMatrix4fv(perspectiveLoc, 1, GL_FALSE, glm::value_ptr(mainCamera->perspective));

        GLint viewLoc = glGetUniformLocation(debugShader->shaderProgramID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(mainCamera->view));
    }

    void RenderManager::DrawModels() {
        RenderManager::getInstance()->RenderBaseShader();
        for (Entity *entity : EntityManager::getInstance()->entities) {
                entity->model->Draw();
                if (entity->hasCollision) {
                    btScalar physicsMatrix[16];
                    entity->rigidBody->getWorldTransform().getOpenGLMatrix(physicsMatrix);
                    entity->model->model = Utils::BulletToGlm(physicsMatrix);
                }
        }
    }

    RenderManager *RenderManager::getInstance() {
        if (!renderManager) {
            renderManager = new RenderManager();
        }
        return renderManager;
    }

void RenderManager::DrawTerrain() {
    RenderManager::getInstance()->RenderBaseShader();
    //EntityManager::getInstance()->terrain->Draw();
}

