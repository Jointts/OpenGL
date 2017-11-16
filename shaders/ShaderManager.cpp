//
// Created by Joonas on 1/2/2017.
//

#include "ShaderManager.h"

ShaderManager *ShaderManager::shaderManager = 0;

ShaderProgram *ShaderManager::baseShader = 0;
ShaderProgram *ShaderManager::celShader = 0;
ShaderProgram *ShaderManager::waterShader = 0;
ShaderProgram *ShaderManager::guiShader = 0;
ShaderProgram *ShaderManager::debugShader = 0;

char *BASE_SHADER_VERTEX_PATH = (char *) "shaders/glsl/vertex.glsl";
char *BASE_SHADER_FRAGMENT_PATH = (char *) "shaders/glsl/fragment.glsl";

char *WATER_SHADER_VERTEX_PATH = (char *) "shaders/glsl/water/vertex.glsl";
char *WATER_SHADER_FRAGMENT_PATH = (char *) "shaders/glsl/water/fragment.glsl";

char *CEL_SHADER_VERTEX_PATH = (char *) "shaders/glsl/cel/vertex.glsl";
char *CEL_SHADER_FRAGMENT_PATH = (char *) "shaders/glsl/cel/fragment.glsl";

char *GUI_SHADER_VERTEX_PATH = (char *) "shaders/glsl/gui/vertex.glsl";
char *GUI_SHADER_FRAGMENT_PATH = (char *) "shaders/glsl/gui/fragment.glsl";

char *DEBUG_SHADER_VERTEX_PATH = (char *) "shaders/glsl/debug/vertex.glsl";
char *DEBUG_SHADER_FRAGMENT_PATH = (char *) "shaders/glsl/debug/fragment.glsl";

ShaderManager::ShaderManager() {
    this->baseShader = new ShaderProgram(BASE_SHADER_VERTEX_PATH, BASE_SHADER_FRAGMENT_PATH);
    this->celShader = new ShaderProgram(CEL_SHADER_VERTEX_PATH, CEL_SHADER_FRAGMENT_PATH);
    this->waterShader = new ShaderProgram(WATER_SHADER_VERTEX_PATH, WATER_SHADER_FRAGMENT_PATH);
    this->guiShader = new ShaderProgram(GUI_SHADER_VERTEX_PATH, GUI_SHADER_FRAGMENT_PATH);
    this->debugShader = new ShaderProgram(DEBUG_SHADER_VERTEX_PATH, DEBUG_SHADER_FRAGMENT_PATH);
}

ShaderManager *ShaderManager::getInstance() {
    if (!shaderManager) {
        shaderManager = new ShaderManager;
    }
    return shaderManager;
}
