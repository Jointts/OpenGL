//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_RENDERMANAGER_H
#define OPENGL_RENDERMANAGER_H


#include <array>
#include <vector>
#include "../Model.h"
#include "../shaders/ShaderProgram.h"
#include "../Entity.h"

class RenderManager {
public:

    static int cameraPosition;

    static RenderManager *getInstance();

    static RenderManager *renderManager;

    void RenderCelShader();

    void RenderBaseShader();

    void DrawModels();

    void RenderWaterShader();

    void RenderGuiShader();

    void RenderDebugShader();

    void DrawGui();

    void DrawPointLights();

    void DrawDirectionalLight();
};


#endif //OPENGL_RENDERMANAGER_H
