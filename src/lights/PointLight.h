//
// Created by Joonas on 10/29/2017.
//

#ifndef GAME_POINTLIGHT_H
#define GAME_POINTLIGHT_H


#include <glm/vec3.hpp>

class PointLight {
public:
    PointLight(const glm::vec3& position, const glm::vec3& diffuse, float constant, float linear, float quadratic);

    void Enable();

private:
    glm::vec3 position;
    glm::vec3 diffuse;

    float constant;
    float linear;
    float quadratic;

};


#endif //GAME_POINTLIGHT_H
