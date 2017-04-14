//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_CAMERAMANAGER_H
#define OPENGL_CAMERAMANAGER_H


#include <detail/type_mat.hpp>
#include <detail/type_mat4x4.hpp>
#include "MainCamera.h"

class CameraManager {
public:
    CameraManager();

    static CameraManager *getInstance();

    static MainCamera* mainCamera;

private:
    static CameraManager *cameraManager;

};


#endif //OPENGL_CAMERAMANAGER_H
