//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_RENDERMANAGER_H
#define OPENGL_RENDERMANAGER_H


#include <array>
#include <vector>
#include "Model.h"
#include "ShaderProgram.h"
#include "Entity.h"

class RenderManager{
public:

    static int cameraPosition;

    std::vector<Entity*> entities;

    static RenderManager *getInstance();

    static RenderManager *renderManager;

    void RenderModels();

    void RenderCelShader(bool drawModels);

    void RenderBaseShader(bool drawModels);

    void RenderCelShader();

    void RenderBaseShader();

    void DrawModels();

    void RenderWaterShader();

    void RenderGuiShader();

    void RenderDebugShader();
};


#endif //OPENGL_RENDERMANAGER_H
