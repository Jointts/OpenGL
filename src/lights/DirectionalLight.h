#ifndef SUMMIT_ENGINE_DIRECTIONALLIGHT_H
#define SUMMIT_ENGINE_DIRECTIONALLIGHT_H


#include <glm/vec3.hpp>
#include <glad/glad.h>

class DirectionalLight {

    glm::vec3 lightColor;
    GLfloat lightStrength;
    glm::vec3 lightDirection;

public:
    DirectionalLight(glm::vec3 lightColor, GLfloat lightStrength, glm::vec3 lightPos);

    void Enable();
};


#endif //SUMMIT_ENGINE_DIRECTIONALLIGHT_H
