//
// Created by Joonas on 29/09/2016.
//

#ifndef OPENGL_ENGINE_H
#define OPENGL_ENGINE_H


#include "ShaderProgram.h"
#include "Display.h"
#include "Input.h"

class Engine {
    ShaderProgram *shaderProgram;

public:
    Input *input;
    Display *display;
    const int WIDTH = 800;
    const int HEIGHT = 600;
    int Start();
};


#endif //OPENGL_ENGINE_H
