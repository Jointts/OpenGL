//
// Created by Joonas on 06/10/2016.
//

#include <gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <gtc/type_ptr.hpp>
#include <iostream>
#include "CameraManager.h"
#include "ShaderProgram.h"
#include "ShaderManager.h"


CameraManager *CameraManager::cameraManager = 0;
ShaderProgram *shaderProgram = 0;

CameraManager *CameraManager::getInstance() {
    if(!cameraManager){
        cameraManager = new CameraManager;
    }
    return cameraManager;
}

CameraManager::CameraManager(){
    ShaderProgram *shaderProgram = ShaderManager::getInstance()->shaderProgram;
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    cameraPos = glm::vec3(0.0f, 20.0f, 7.0f);
    eyePos = glm::vec3(0.0f, -5.0f, -3.0f);

    projection = glm::perspective(glm::radians(90.0f), 3440.0f / 1440.0f, 0.1f, 100.0f);
    perspectiveLoc = glGetUniformLocation(shaderProgram->shaderProgramID, "perspective");
    glUniformMatrix4fv(perspectiveLoc, 1, GL_FALSE, glm::value_ptr(projection));

    viewLoc = glGetUniformLocation(shaderProgram->shaderProgramID, "view");
    UpdateCamera();
}

void CameraManager::MoveLeft() {
    cameraPos.x -= 1.0f;
    UpdateCamera();
}

void CameraManager::MoveRight() {
    cameraPos.x += 1.0f;
    UpdateCamera();
}

void CameraManager::MoveForward() {
    cameraPos.z -= 1.0f;
    UpdateCamera();
}

void CameraManager::MoveBack() {
    cameraPos.z += 1.0f;
    UpdateCamera();
}

void CameraManager::MoveUp() {
    cameraPos.y += 1.0f;
    UpdateCamera();
}

void CameraManager::MoveDown() {
    cameraPos.y -= 1.0f;
    UpdateCamera();
}

void CameraManager::UpdateCamera() {
    view = glm::lookAt(cameraPos,
                       cameraPos + eyePos,
                       cameraUp);
}




