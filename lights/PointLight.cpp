//
// Created by Joonas on 10/29/2017.
//

#include "PointLight.h"
#include "../ShaderManager.h"

PointLight::PointLight(const glm::vec3 &position, const glm::vec3 &diffuse, float constant, float linear,
                       float quadratic) : position(position), diffuse(diffuse), constant(constant), linear(linear),
                                          quadratic(quadratic) {
}

void PointLight::Enable() {
    glUniform3f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "pointLight.position"), position.x, position.y, position.z);
    glUniform3f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "pointLight.diffuse"), diffuse.r, diffuse.g, diffuse.b);
    glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "pointLight.constant"), constant);
    glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "pointLight.linear"), linear);
    glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "pointLight.quadratic"), quadratic);
}