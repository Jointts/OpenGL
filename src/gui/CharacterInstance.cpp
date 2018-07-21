//
// Created by Joonas on 26/12/2017.
//

#include "CharacterInstance.h"
#include "../shaders/ShaderManager.h"

CharacterInstance::CharacterInstance(int width, int height, int xMargin, int yMargin) : Quad(width, height) {
    SetPosition(xMargin, yMargin);
    setupMesh(vertices, indices);
}

void CharacterInstance::Draw(glm::vec3 color) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(2);
    if (textureId) {
        glActiveTexture(0);
        glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->guiShader->shaderProgramID, "diffuse"),
                    textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }
    glUniform3f(glGetUniformLocation(ShaderManager::getInstance()->guiShader->shaderProgramID, "textColor"), color.r,
                color.g, color.b);
    glUniform1i(glGetUniformLocation(ShaderManager::getInstance()->guiShader->shaderProgramID, "renderText"), 1);
    glDrawElements(GL_TRIANGLES, (GLsizei) indices.size(), GL_UNSIGNED_INT, 0);
    glUniform1i(glGetUniformLocation(ShaderManager::getInstance()->guiShader->shaderProgramID, "renderText"), 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}

void CharacterInstance::SetTexture(unsigned int textureId) {
    this->textureId = textureId;
}
