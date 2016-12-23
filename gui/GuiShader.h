//
// Created by Joonas on 12/12/2016.
//

#ifndef OPENGL_TERRAINSHADER_H
#define OPENGL_TERRAINSHADER_H


#include "../ShaderProgram.h"

class GuiShader: ShaderProgram {
    char *FRAGMENT_SHADER_PATH = "shaders\\fragment.glsl";
    char *VERTEX_SHADER_PATH = "shaders\\vertex.glsl";
};


#endif //OPENGL_TERRAINSHADER_H
