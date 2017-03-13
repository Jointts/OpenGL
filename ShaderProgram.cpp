//
// Created by Joonas on 29/09/2016.
//

#include <iostream>
#include "ShaderProgram.h"
#include "Utils.h"

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
    shaderProgramID = glCreateProgram();
    fragmentShader = CreateShader(GL_FRAGMENT_SHADER, FRAGMENT_SHADER_PATH);
    vertexShader = CreateShader(GL_VERTEX_SHADER, VERTEX_SHADER_PATH);
    glAttachShader(shaderProgramID, fragmentShader);
    glAttachShader(shaderProgramID, vertexShader);
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
