//
// Created by Joonas on 06/10/2016.
//

#ifndef SUMMIT_ENGINE_CAMERAMANAGER_H
#define SUMMIT_ENGINE_CAMERAMANAGER_H


#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include "MainCamera.h"
#include "GuiCamera.h"

class CameraManager {
public:
    CameraManager();

    static CameraManager *getInstance();

    static MainCamera *mainCamera;

    static GuiCamera *guiCamera;

private:
    static CameraManager *cameraManager;

};


#endif //SUMMIT_ENGINE_CAMERAMANAGER_H
