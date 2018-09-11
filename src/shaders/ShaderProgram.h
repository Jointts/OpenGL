//
// Created by Joonas on 29/09/2016.
//

#ifndef OPENGL_SHADERPROGRAM_H
#define OPENGL_SHADERPROGRAM_H

#ifndef __gl_h_

#include <glad/glad.h>

#endif

typedef char GLchar;

class ShaderProgram {
public:

    GLuint shaderProgramID;
    GLuint vertexShader;
    GLuint fragmentShader;
    GLint  success;
    GLchar infoLog[512];
    char   *VERTEX_SHADER_PATH;
    char   *FRAGMENT_SHADER_PATH;

    ShaderProgram() = delete;
    ShaderProgram(char *vertexShader, char *fragmentShader);

    void Start();
    void Stop();
    GLuint CreateShader(GLuint shaderType, GLchar *shaderPath);


    ~ShaderProgram();
};

#endif //OPENGL_SHADERPROGRAM_H
