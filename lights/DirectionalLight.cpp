//
// Created by Joonas on 12/12/2016.
//

#include <glad/glad.h>
#include "DirectionalLight.h"
#include "../ShaderProgram.h"
#include "../ShaderManager.h"

DirectionalLight::DirectionalLight(glm::vec3 lightColor, GLfloat lightStrength, glm::vec3 lightPos){
    this->lightColor = lightColor;
    this->lightStrength = lightStrength;
    this->lightDirection = lightPos;
}

void DirectionalLight::Enable(){
    glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "ambientStrength"), lightStrength);
    glUniform3f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "ambientColor"), 1.0f, 1.0f, 1.0f);
    glUniform3f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "lightColor"), lightColor.x, lightColor.y, lightColor.z);
    glUniform3f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "lightDirection"), lightDirection.x, lightDirection.y, lightDirection.z);
}


