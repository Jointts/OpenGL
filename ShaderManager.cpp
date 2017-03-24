//
// Created by Joonas on 1/2/2017.
//

#include "ShaderManager.h"

ShaderManager *ShaderManager::shaderManager = 0;

ShaderProgram *ShaderManager::baseShader = 0;
ShaderProgram *ShaderManager::celShader = 0;

char* BASE_SHADER_VERTEX_PATH = (char *) "shaders/vertex.glsl";
char* BASE_SHADER_FRAGMENT_PATH = (char *) "shaders/fragment.glsl";
char* CEL_SHADER_VERTEX_PATH = (char *) "shaders/cel/vertex.glsl";
char* CEL_SHADER_FRAGMENT_PATH = (char *) "shaders/cel/fragment.glsl";

ShaderManager::ShaderManager() {
    this->baseShader = new ShaderProgram(BASE_SHADER_VERTEX_PATH, BASE_SHADER_FRAGMENT_PATH);
    this->celShader = new ShaderProgram(CEL_SHADER_VERTEX_PATH, CEL_SHADER_FRAGMENT_PATH);
}

ShaderManager *ShaderManager::getInstance() {
    if(!shaderManager){
        shaderManager = new ShaderManager;
    }
    return shaderManager;
}
