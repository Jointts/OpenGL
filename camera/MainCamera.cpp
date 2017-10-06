//
// Created by Joonas on 12/04/2017.
//

#include <gtc/matrix_transform.hpp>
#include "MainCamera.h"
#include "../DisplayManager.h"

MainCamera::MainCamera() {
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    cameraPos = glm::vec3(0.0f, 20.0f, 7.0f);
    eyePos = glm::vec3(0.0f, -5.0f, -3.0f);

    DisplayManager *displayManager = DisplayManager::getInstance();

    perspective = glm::perspective(glm::radians(90.0f),(float) displayManager->width / (float) displayManager->height, 0.1f, 100.0f);
    UpdateCamera();
}

void MainCamera::MoveLeft() {
    currentSpeed += accelerationSpeed;
    cameraPos.x -= currentSpeed;
    UpdateCamera();
}

void MainCamera::MoveRight() {
    currentSpeed += accelerationSpeed;
    cameraPos.x += currentSpeed;
    UpdateCamera();
}

void MainCamera::MoveForward() {
    currentSpeed += accelerationSpeed;
    cameraPos.z -= currentSpeed;
    UpdateCamera();
}

void MainCamera::MoveBack() {
    currentSpeed += accelerationSpeed;
    cameraPos.z += currentSpeed;
    UpdateCamera();
}

void MainCamera::MoveUp() {
    currentSpeed += accelerationSpeed;
    cameraPos.y += currentSpeed;
    UpdateCamera();
}

void MainCamera::MoveDown() {
    currentSpeed += accelerationSpeed;
    cameraPos.y -= currentSpeed;
    UpdateCamera();
}

void MainCamera::UpdateCamera() {
    view = glm::lookAt(cameraPos,
                       cameraPos + eyePos,
                       cameraUp);
}

