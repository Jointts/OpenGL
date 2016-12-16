//
// Created by Joonas on 29/09/2016.
//

#ifndef OPENGL_SHADERS_H
#define OPENGL_SHADERS_H

#include <glad/glad.h>

class ShaderProgram {
    char *VERTEX_SHADER_PATH = "shaders\\vertex.glsl";
    GLuint vertexShader;
    GLuint fragmentShader;
    GLint success;
    GLchar infoLog[512];

protected:
    char *FRAGMENT_SHADER_PATH = "shaders\\fragment.glsl";
public:
    GLuint shaderProgramID;

    ShaderProgram();

    GLuint CreateShader(GLuint shaderType, GLchar *shaderPath);

    void Start();

    void Stop();

    static ShaderProgram* getInstance();

    static ShaderProgram *shaderProgram;

    ~ShaderProgram();
};

#endif //OPENGL_SHADERS_H
