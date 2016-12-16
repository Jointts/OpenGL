//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_CAMERAMANAGER_H
#define OPENGL_CAMERAMANAGER_H


#include <detail/type_mat.hpp>
#include <detail/type_mat4x4.hpp>

class CameraManager {
public:

    GLint perspectiveLoc;
    GLint viewLoc;
    glm::vec3 perspective;
    glm::mat4 projection;
    glm::mat4 view;
    glm::vec3 cameraPos;
    glm::vec3 eyePos;
    glm::vec3 cameraUp;

    CameraManager();

    static CameraManager *getInstance();

    void MoveLeft();

    void MoveRight();

    void MoveForward();

    void MoveBack();

    void UpdateCamera();

    void MoveUp();

    void MoveDown();

private:
    static CameraManager *cameraManager;

};


#endif //OPENGL_CAMERAMANAGER_H
