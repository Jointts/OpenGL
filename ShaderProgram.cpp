//
// Created by Joonas on 29/09/2016.
//

#include <iostream>
#include "ShaderProgram.h"
#include "Utils.h"

GLuint ShaderProgram::CreateShader(GLuint shaderType, GLchar *shaderPath) {
    GLuint shader = glCreateShader(shaderType);
    char* shaderSource = (char *) Utils::readFile(shaderPath).c_str();
    glShaderSource(shader, 1, (const GLchar *const *) &shaderSource, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << shaderPath << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shader;
}

ShaderProgram::ShaderProgram(char *vertexShader, char *fragmentShader)
: VERTEX_SHADER_PATH(vertexShader), FRAGMENT_SHADER_PATH(fragmentShader)
{
    shaderProgramID = glCreateProgram();
    this->fragmentShader = CreateShader(GL_FRAGMENT_SHADER, FRAGMENT_SHADER_PATH);
    this->vertexShader = CreateShader(GL_VERTEX_SHADER, VERTEX_SHADER_PATH);
    glAttachShader(shaderProgramID, this->fragmentShader);
    glAttachShader(shaderProgramID, this->vertexShader);
    glLinkProgram(shaderProgramID);
}

void ShaderProgram::Start() {
    glUseProgram(shaderProgramID);
}

void ShaderProgram::Stop() {
    glUseProgram(0);
}

ShaderProgram::~ShaderProgram() {
    Stop();
    glDetachShader(shaderProgramID, fragmentShader);
    glDetachShader(shaderProgramID, vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteProgram(shaderProgramID);
}
