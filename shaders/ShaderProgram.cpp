//
// Created by Joonas on 29/09/2016.
//

#include <iostream>
#include "ShaderProgram.h"
#include "../Utils.h"

GLuint ShaderProgram::CreateShader(GLuint shaderType, GLchar *shaderPath) {
    GLuint shader = glCreateShader(shaderType);
    std::string shaderSourceStr = Utils::readFile(shaderPath);
    const char *fragmentSource = shaderSourceStr.c_str();
    const char *shaderSource = fragmentSource;
    glShaderSource(shader, 1, (const GLchar *const *) &shaderSource, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    glGetShaderInfoLog(shader, 512, NULL, infoLog);

    //  We have found a critical error in shader setup, display error and exit program
    if (!success || (unsigned int) strlen(infoLog) != 0) {
        std::cout << "ERROR::SHADER::" << shaderPath << "::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }
    return shader;
}

ShaderProgram::ShaderProgram(char *vertexShader, char *fragmentShader)
        : VERTEX_SHADER_PATH(vertexShader), FRAGMENT_SHADER_PATH(fragmentShader) {
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
