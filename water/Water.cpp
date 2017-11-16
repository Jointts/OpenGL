//
// Created by Joonas on 12/23/2016.
//

#include "Water.h"
#include "../shaders/ShaderManager.h"
#include "../Time.h"
#include "../renderer/RenderManager.h"

Water::Water(int sizeX, int sizeZ, int tileSize, bool generateHeightMap) : Plane(sizeX, sizeZ, tileSize,
                                                                                 generateHeightMap) {

}

void Water::UpdateShader() {
    ShaderProgram *waterShader = ShaderManager::getInstance()->waterShader;
    double currentCycle = Time::currentCycle * oscillatingSpeed;

    GLint waterCycleLoc = glGetUniformLocation(waterShader->shaderProgramID, "waterCycle");
    glUniform1f(waterCycleLoc, 0.0f);

    bool odd = false;

    for (int i = 0; i < vertices.size(); ++i) {
        odd ^= true;
        if (odd) {
            if (i < vertices.size()) {
                vertices[i].position.y = (float) sin(i) * oscillatingMagnitude * (float) sin(currentCycle);
            }
            if (i + 2 < vertices.size()) {
                vertices[i + 1].position.y = oscillatingMagnitude * (float) cos(currentCycle + tan(i));
            }
            if (i * sizeX + 1 < vertices.size()) {
                vertices[i * sizeX + 1].position.y = oscillatingMagnitude * (float) cos(currentCycle + tan(i));
            }
        }
    }

    UpdateMesh(vertices, indices);
}

void Water::Draw() {
    RenderManager::getInstance()->RenderWaterShader();
    UpdateShader();
    Plane::Draw();
}

