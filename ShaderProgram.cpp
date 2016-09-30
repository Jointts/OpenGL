//
// Created by Joonas on 29/09/2016.
//

#include <iostream>
#include "ShaderProgram.h"
#include "Utils.h"

char *FRAGMENT_SHADER_PATH = "shaders\\fragment.glsl";
char *VERTEX_SHADER_PATH = "shaders\\vertex.glsl";

GLuint ShaderProgram::CreateShader(GLuint shaderType, GLchar *shaderPath) {
    GLuint shader = glCreateShader(shaderType);
    std::string shaderSource = Utils::readFile(shaderPath).c_str();
    glShaderSource(shader, 1, (const GLchar *const *) &shaderSource, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << strupr(shaderPath) << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shader;
}

ShaderProgram::ShaderProgram() {
    shaderProgram = glCreateProgram();
    fragmentShader = this->CreateShader(GL_FRAGMENT_SHADER, FRAGMENT_SHADER_PATH);
    vertexShader = this->CreateShader(GL_VERTEX_SHADER, VERTEX_SHADER_PATH);
    glAttachShader(shaderProgram, fragmentShader);
    glAttachShader(shaderProgram, vertexShader);
    glLinkProgram(shaderProgram);
}

void ShaderProgram::Start() {
    glUseProgram(shaderProgram);
}

void ShaderProgram::Stop() {
    glUseProgram(0);
}

ShaderProgram::~ShaderProgram() {
    this->Stop();
    glDetachShader(shaderProgram, fragmentShader);
    glDetachShader(shaderProgram, vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteProgram(shaderProgram);
}
