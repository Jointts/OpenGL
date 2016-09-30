//
// Created by Joonas on 29/09/2016.
//

#ifndef OPENGL_SHADERS_H
#define OPENGL_SHADERS_H

#include <glad/glad.h>

class ShaderProgram {
    GLuint vertexShader;
    GLuint fragmentShader;
    GLint success;
    GLchar infoLog[512];

public:
    GLuint shaderProgram;

    ShaderProgram();

    GLuint CreateShader(GLuint shaderType, GLchar *shaderPath);

    void Start();

    void Stop();

    ~ShaderProgram();
};

#endif //OPENGL_SHADERS_H
