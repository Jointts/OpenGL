//
// Created by Joonas on 29/09/2016.
//

#ifndef OPENGL_SHADERPROGRAM_H
#define OPENGL_SHADERPROGRAM_H

#include <glad/glad.h>

class ShaderProgram {
    GLuint vertexShader;
    GLuint fragmentShader;
    GLint success;
    GLchar infoLog[512];
public:
    char *VERTEX_SHADER_PATH = "shaders\\vertex.glsl";
    char *FRAGMENT_SHADER_PATH = "shaders\\fragment.glsl";

    GLuint shaderProgramID;

    ShaderProgram();

    GLuint CreateShader(GLuint shaderType, GLchar *shaderPath);

    void Start();

    void Stop();


    ShaderProgram *shaderProgram;

    ~ShaderProgram();
};

#endif //OPENGL_SHADERPROGRAM_H
