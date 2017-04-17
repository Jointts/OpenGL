//
// Created by Joonas on 12/04/2017.
//

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "GuiCamera.h"

GuiCamera::GuiCamera() {
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
    eyePos = glm::vec3(0.0f, 0.0f, 0.0f);
    perspective = glm::ortho(0.0f, 1440.0f, 0.0f, 900.0f);
}
