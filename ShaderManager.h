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

    static ShaderProgram* baseShader;

    static ShaderProgram* celShader;

    static ShaderProgram* guiShader;

    static ShaderProgram* waterShader;

    static ShaderProgram* debugShader;

    static ShaderManager *getInstance();
};


#endif //OPENGL_SHADERMANAGER_H
