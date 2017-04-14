//
// Created by Joonas on 06/10/2016.
//

#include "CameraManager.h"
#include "GuiCamera.h"


CameraManager *CameraManager::cameraManager = 0;
MainCamera *CameraManager::mainCamera = 0;
GuiCamera *CameraManager::guiCamera = 0;

CameraManager::CameraManager(){
    mainCamera = new MainCamera;
    guiCamera = new GuiCamera;
}

CameraManager *CameraManager::getInstance() {
    if(!cameraManager){
        cameraManager = new CameraManager;
    }
    return cameraManager;
}





