//
// Created by Joonas on 1/2/2017.
//

#ifndef OPENGL_SHADERMANAGER_H
#define OPENGL_SHADERMANAGER_H

#include "ShaderProgram.h"

class ShaderManager {
    ShaderManager();
public:
    static ShaderManager* shaderManager;

    static ShaderProgram* shaderProgram;

    static ShaderManager *getInstance();
};


#endif //OPENGL_SHADERMANAGER_H
