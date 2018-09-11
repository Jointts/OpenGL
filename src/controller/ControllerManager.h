//
// Created by Joonas on 06/10/2016.
//

#ifndef SUMMIT_ENGINE_CONTROLLERMANAGER_H
#define SUMMIT_ENGINE_CONTROLLERMANAGER_H


#include <GLFW/glfw3.h>
#include "../display/DisplayManager.h"
#include "../camera/CameraManager.h"
#include "../Entity.h"
#include "MouseController.h"

class ControllerManager {
public:
    ControllerManager();

    static ControllerManager *getInstance();
private:
    static ControllerManager *controllerManager;
};


#endif //SUMMIT_ENGINE_CONTROLLERMANAGER_H
