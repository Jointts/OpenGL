#ifndef OPENGL_DIRECTIONALLIGHT_H
#define OPENGL_DIRECTIONALLIGHT_H


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


#endif //OPENGL_DIRECTIONALLIGHT_H
