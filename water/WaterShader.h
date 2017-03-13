//
// Created by Joonas on 12/12/2016.
//

#ifndef OPENGL_WATERSHADER_H
#define OPENGL_WATERSHADER_H


#include "../ShaderProgram.h"

class WaterShader: ShaderProgram {
    char *FRAGMENT_SHADER_PATH = "shaders\\fragment.glsl";
    char *VERTEX_SHADER_PATH = "shaders\\vertex.glsl";

};


#endif //OPENGL_WATERSHADER_H
