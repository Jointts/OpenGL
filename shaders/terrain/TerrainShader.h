//
// Created by Joonas on 1/2/2017.
//

#ifndef OPENGL_TERRAINSHADER_H
#define OPENGL_TERRAINSHADER_H


#include "../../ShaderProgram.h"

class TerrainShader : public ShaderProgram{
    char* VERTEX_SHADER_PATH = "shaders\\terrain\\vertex.glsl";
    char* FRAGMENT_SHADER_PATH = "shaders\\terrain\\fragment.glsl";
};


#endif //OPENGL_TERRAINSHADER_H
