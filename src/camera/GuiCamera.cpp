//
// Created by Joonas on 12/04/2017.
//

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GuiCamera.h"
#include "../display/DisplayManager.h"

GuiCamera::GuiCamera() {
    DisplayManager *displayManager = DisplayManager::getInstance();

    cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
    cameraPos   = glm::vec3(0.0f, 0.0f, 0.0f);
    eyePos      = glm::vec3(0.0f, 0.0f, 0.0f);
    perspective = glm::ortho(0.0f, (float) displayManager->display->width, 0.0f,
                             (float) displayManager->display->height);
}
