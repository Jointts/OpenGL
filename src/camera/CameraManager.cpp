//
// Created by Joonas on 06/10/2016.
//

#include "CameraManager.h"


CameraManager *CameraManager::cameraManager = nullptr;
MainCamera    *CameraManager::mainCamera    = nullptr;
GuiCamera     *CameraManager::guiCamera     = nullptr;

CameraManager::CameraManager() {
    mainCamera = new MainCamera;
    guiCamera  = new GuiCamera;
}

CameraManager *CameraManager::getInstance() {
    if (!cameraManager) {
        cameraManager = new CameraManager;
    }
    return cameraManager;
}





