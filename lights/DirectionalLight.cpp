//
// Created by Joonas on 12/12/2016.
//

#include <glad/glad.h>
#include "DirectionalLight.h"
#include "../shaders/ShaderProgram.h"
#include "../shaders/ShaderManager.h"
#include "LightManager.h"

DirectionalLight::DirectionalLight(glm::vec3 lightColor, GLfloat lightStrength, glm::vec3 lightPos) {
    this->lightColor = lightColor;
    this->lightStrength = lightStrength;
    this->lightDirection = lightPos;
    LightManager::getInstance()->directionalLight = this;
}

void DirectionalLight::Enable() {
    glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "ambientStrength"),
                1.0f);
    glUniform3f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "ambientColor"), 1.0f,
                1.0f, 1.0f);
    glUniform3f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID,
                                     "directionalLight.lightColor"), lightColor.x, lightColor.y, lightColor.z);
    glUniform3f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID,
                                     "directionalLight.lightDirection"), lightDirection.x, lightDirection.y,
                lightDirection.z);
    glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID,
                                     "directionalLight.lightStrength"), lightStrength);
}


