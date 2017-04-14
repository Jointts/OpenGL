//
// Created by Joonas on 1/2/2017.
//

#include "ShaderManager.h"

ShaderManager *ShaderManager::shaderManager = 0;

ShaderProgram *ShaderManager::baseShader = 0;
ShaderProgram *ShaderManager::celShader = 0;
ShaderProgram *ShaderManager::waterShader = 0;
ShaderProgram *ShaderManager::guiShader = 0;

char* BASE_SHADER_VERTEX_PATH = (char *) "shaders/vertex.glsl";
char* BASE_SHADER_FRAGMENT_PATH = (char *) "shaders/fragment.glsl";
char* CEL_SHADER_VERTEX_PATH = (char *) "shaders/cel/vertex.glsl";
char* CEL_SHADER_FRAGMENT_PATH = (char *) "shaders/cel/fragment.glsl";
char* WATER_SHADER_FRAGMENT_PATH = (char *) "shaders/water/fragment.glsl";
char* WATER_SHADER_VERTEX_PATH = (char *) "shaders/water/vertex.glsl";
char* GUI_SHADER_VERTEX_PATH = (char *) "shaders/gui/vertex.glsl";
char* GUI_SHADER_FRAGMENT_PATH = (char *) "shaders/gui/fragment.glsl";

ShaderManager::ShaderManager() {
    this->baseShader = new ShaderProgram(BASE_SHADER_VERTEX_PATH, BASE_SHADER_FRAGMENT_PATH);
    this->celShader = new ShaderProgram(CEL_SHADER_VERTEX_PATH, CEL_SHADER_FRAGMENT_PATH);
    this->waterShader = new ShaderProgram(WATER_SHADER_VERTEX_PATH, WATER_SHADER_FRAGMENT_PATH);
    this->guiShader = new ShaderProgram(GUI_SHADER_VERTEX_PATH, GUI_SHADER_FRAGMENT_PATH);
}

ShaderManager *ShaderManager::getInstance() {
    if(!shaderManager){
        shaderManager = new ShaderManager;
    }
    return shaderManager;
}
