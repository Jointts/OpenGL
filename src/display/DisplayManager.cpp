//
// Created by Joonas on 06/10/2016.
//

#ifndef __gl_h_

#include <glad/glad.h>

#endif

#include "DisplayManager.h"

DisplayManager *DisplayManager::displayManager = 0;

DisplayManager::DisplayManager() {
    display = new Display(3440, 1440, "Summit Engine");
}

DisplayManager *DisplayManager::getInstance() {
    if (!displayManager) {
        displayManager = new DisplayManager();
    }
    return displayManager;
}