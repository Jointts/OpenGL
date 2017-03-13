//
// Created by Joonas on 1/2/2017.
//

#include "ShaderManager.h"

ShaderManager *ShaderManager::shaderManager = 0;
ShaderProgram *ShaderManager::shaderProgram = 0;

ShaderManager::ShaderManager() {
    this->shaderProgram = new ShaderProgram();
}

ShaderManager *ShaderManager::getInstance() {
    if(!shaderManager){
        shaderManager = new ShaderManager;
    }
    return shaderManager;
}
