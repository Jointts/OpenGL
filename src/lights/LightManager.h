//
// Created by Joonas on 11/15/2017.
//

#ifndef GAME_LIGHTMANAGER_H
#define GAME_LIGHTMANAGER_H


#include "PointLight.h"
#include "DirectionalLight.h"
#include <vector>

class LightManager {

    LightManager();

public:

    static LightManager *lightManager;

    static LightManager *getInstance();

    DirectionalLight *directionalLight;
    std::vector<PointLight *> pointLights;
};


#endif //GAME_LIGHTMANAGER_H
