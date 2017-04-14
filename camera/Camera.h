//
// Created by Joonas on 12/04/2017.
//

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H


#include <vec3.hpp>
#include <detail/type_mat4x4.hpp>

class Camera {
public:
    glm::mat4 perspective;
    glm::mat4 view;
    glm::vec3 cameraPos;
    glm::vec3 eyePos;
    glm::vec3 cameraUp;
};


#endif //OPENGL_CAMERA_H
