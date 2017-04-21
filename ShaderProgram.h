//
// Created by Joonas on 29/09/2016.
//

#ifndef OPENGL_SHADERPROGRAM_H
#define OPENGL_SHADERPROGRAM_H

#ifndef __gl_h_
#include <glad/glad.h>
#endif

class ShaderProgram {
public:
    ShaderProgram(char *vertexShader, char *fragmentShader);

    GLuint vertexShader;
    GLuint fragmentShader;
    GLint success;
    GLchar infoLog[512];
    char *VERTEX_SHADER_PATH;
    char *FRAGMENT_SHADER_PATH;

    GLuint shaderProgramID;

    ShaderProgram();

    GLuint CreateShader(GLuint shaderType, GLchar *shaderPath);

    void Start();

    void Stop();

    ShaderProgram *shaderProgram;

    ~ShaderProgram();
};

#endif //OPENGL_SHADERPROGRAM_H
