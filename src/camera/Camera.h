//
// Created by Joonas on 12/04/2017.
//

#ifndef SUMMIT_ENGINE_CAMERA_H
#define SUMMIT_ENGINE_CAMERA_H


#include <glm/vec3.hpp>
#include <glm/detail/type_mat4x4.hpp>

class Camera {
public:
    glm::mat4 perspective;
    glm::mat4 view;
    glm::vec3 cameraPos;
    glm::vec3 eyePos;
    glm::vec3 cameraUp;
};


#endif //SUMMIT_ENGINE_CAMERA_H
