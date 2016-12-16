//
// Created by Joonas on 29/09/2016.
//

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include <detail/type_mat.hpp>
#include <detail/type_mat4x4.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>
#include <glad/glad.h>
#include "Engine.h"
#include "Model.h"
#include "Terrain.h"
#include "DirectionalLight.h"
#include "Utils.h"
#include "TerrainShader.h"
#include "Water.h"

int Engine::Start() {
    DisplayManager *displayManager = DisplayManager::getInstance();

    glfwInit();

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    ShaderProgram *shaderProgram = ShaderProgram::getInstance();
    CameraManager *cameraManager = CameraManager::getInstance();
    ControllerManager *controllerManager = ControllerManager::getInstance();

    Terrain *terrain = new Terrain();
    Water *water = new Water();
    std::vector<Model*> modelArray;

    for(int x=0; x < 100; x++){
        Model *model = new Model();
        model->model_file = "C:\\Users\\Joonas\\ClionProjects\\OpenGL\\res\\tree_1.FBX";
        model->importFile();
        model->Translate(glm::vec3(x, 0.0f , 0.0f));
        model->Scale(glm::vec3(0.5f, 0.5f , 0.5f));
        modelArray.push_back(model);
    }
//    model->Rotate(180.0f, glm::vec3(1.0f, 0.0f, 0.0f));
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    while (!glfwWindowShouldClose(displayManager->window)) {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        glUniformMatrix4fv(cameraManager->perspectiveLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->projection));
        glUniformMatrix4fv(cameraManager->viewLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->view));

        shaderProgram->Start();
        for(int x=0; x < 100; x++){
            modelArray[x]->Draw();
        }

        glm::mat4 terrainModelMatrix = glm::mat4();
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram->shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(terrainModelMatrix));
        terrain->Draw();
        water->Draw();
        glm::vec3 lightColor = Utils::color_RGB(255.0f, 255.0f, 255.0f);
        GLfloat lightStrength = 0.1f;
        glm::vec3 lightPos = {1.0f, 1.0f, 1.0f};

        DirectionalLight *directionalLight = new DirectionalLight(lightColor, lightStrength, lightPos);
        directionalLight->Enable();

        glfwSwapBuffers(displayManager->window);
    }
}

