//
// Created by Joonas on 11/15/2017.
//

#include "LightManager.h"

LightManager *LightManager::lightManager = 0;

LightManager::LightManager() {

}

LightManager *LightManager::getInstance() {
    if (!lightManager) {
        lightManager = new LightManager();
    }
    return lightManager;
}