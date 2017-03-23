//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_RENDERMANAGER_H
#define OPENGL_RENDERMANAGER_H


#include <array>
#include <vector>
#include "Model.h"

class RenderManager{
public:

    void Render();

    static int cameraPosition;

    static RenderManager *getInstance();

    static RenderManager *renderManager;

    std::vector<Model*> models;
};


#endif //OPENGL_RENDERMANAGER_H
