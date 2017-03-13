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
#include "Utils.h"
#include "geometry/Plane.h"
#include "lights/DirectionalLight.h"
#include "water/Water.h"
#include "water/WaterShader.h"
#include "ShaderManager.h"
#include "shaders/terrain/TerrainShader.h"

int Engine::Start() {
    DisplayManager *displayManager = DisplayManager::getInstance();

    glfwInit();

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

//    ShaderProgram *shaderProgram = ShaderProgram::getInstance();
//    WaterShader *waterShader = (WaterShader *) WaterShader::getInstance();
    CameraManager *cameraManager = CameraManager::getInstance();
    ShaderManager *shaderManager = ShaderManager::getInstance();
    ControllerManager *controllerManager = ControllerManager::getInstance();

    Plane *plane = new Plane(2, 2, 5);
//    std::vector<Model*> modelArray;

//    for(int x=0; x < 100; x++){
        Model *model2 = new Model();
        model2->model_file = "C:\\Users\\Joonas\\ClionProjects\\OpenGL\\res\\rock_1.FBX";
        model2->importFile();
        Model *model = new Model();
        model->model_file = "C:\\Users\\Joonas\\ClionProjects\\OpenGL\\res\\tree_1.FBX";
        model->importFile();
        model->Translate(glm::vec3(0.0f, 0.0f , 0.0f));
        model->Scale(glm::vec3(0.5f, 0.5f , 0.5f));
        Water *water = new Water(3, 3, 5);
        TerrainShader *terrainShader = new TerrainShader();
//        modelArray.push_back(model);
//    }
//    model->Rotate(180.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(displayManager->window)) {
        glFrontFace(GL_CW);
        glCullFace(GL_BACK);
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        glUniformMatrix4fv(cameraManager->perspectiveLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->projection));
        glUniformMatrix4fv(cameraManager->viewLoc, 1, GL_FALSE, glm::value_ptr(cameraManager->view));

//        waterShader->Start();
        terrainShader->Start();
//        for(int x=0; x < 100; x++){
//            modelArray[x]->Draw();
//        }

        model->Draw();
        model2->Draw();

        glm::mat4 terrainModelMatrix = glm::mat4();
        glUniformMatrix4fv(glGetUniformLocation(terrainShader->shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(terrainModelMatrix));
        water->Draw();
//        plane->Draw();
        glm::vec3 lightColor = Utils::color_RGB(255.0f, 255.0f, 255.0f);
        GLfloat lightStrength = 0.1f;
        glm::vec3 lightPos = {1.0f, 1.0f, 1.0f};

        DirectionalLight *directionalLight = new DirectionalLight(lightColor, lightStrength, lightPos);
        directionalLight->Enable();

        glfwSwapBuffers(displayManager->window);
    }
}

