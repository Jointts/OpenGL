//
// Created by Joonas on 01/05/2017.
//

#include <BulletCollision/CollisionShapes/btSphereShape.h>
#include <iostream>
#include "GuiWidget.h"
#include "../Utils.h"
#include "../renderer/RenderManager.h"
#include "GuiManager.h"

GuiWidget::GuiWidget(int width, int height) : Quad(width, height) {
    guiFrameBuffer = GuiManager::getInstance()->guiFrameBuffer;
    GuiManager::getInstance()->guiWidgets.push_back(this);
    SetCollisionColor(GuiManager::getInstance()->CalculateNextCollisionColor());
}

void GuiWidget::UpdateVertexData() {
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
}

float GuiWidget::getMarginLeft() const {
    return marginLeft;
}

void GuiWidget::setMarginLeft(float marginLeft) {
    this->marginLeft       = marginLeft;
    vertices[0].position.x = marginLeft;
    vertices[1].position.x = marginLeft;
    vertices[2].position.x = width + marginLeft;
    vertices[3].position.x = width + marginLeft;
    UpdateVertexData();
}

void GuiWidget::SetCollisionColor(glm::vec3 collisionColor) {
    vertices[0].color    = collisionColor;
    vertices[1].color    = collisionColor;
    vertices[2].color    = collisionColor;
    vertices[3].color    = collisionColor;
    this->collisionColor = collisionColor;
    UpdateVertexData();
}

float GuiWidget::getMarginRight() const {
    return marginRight;
}

void GuiWidget::setMarginRight(float marginRight) {
    float displayWidth = 1440.0f;
    this->marginRight      = marginRight;
    vertices[0].position.x = displayWidth - marginRight;
    vertices[1].position.x = displayWidth - marginRight;
    vertices[2].position.x = displayWidth - (width + marginRight);
    vertices[3].position.x = displayWidth - (width + marginRight);
    UpdateVertexData();
}

float GuiWidget::getMarginTop() const {
    return marginTop;
}

void GuiWidget::setMarginTop(float marginTop) {
    float displayHeight = 900.0f;
    this->marginTop        = marginTop;
    vertices[0].position.y = displayHeight - marginTop;
    vertices[1].position.y = displayHeight - (height + marginTop);
    vertices[2].position.y = displayHeight - (height + marginTop);
    vertices[3].position.y = displayHeight - marginTop;
    UpdateVertexData();
}

float GuiWidget::getMarginBottom() const {
    return marginBottom;
}

void GuiWidget::setMarginBottom(float marginBottom) {
    this->marginBottom     = marginBottom;
    vertices[0].position.y = marginBottom;
    vertices[1].position.y = height + marginBottom;
    vertices[2].position.y = height + marginBottom;
    vertices[3].position.y = marginBottom;
    UpdateVertexData();
}

void GuiWidget::setTexture(GLchar* path) {
    textureId          = Utils::TextureFromFile(path, true);
    collisionTextureId = Utils::TextureFromFile("res/nice_circle_collision_round.png", true);
}

void GuiWidget::DrawCollision() {
    guiFrameBuffer->RenderToCollisionFrameBuffer();
    RenderManager::getInstance()->RenderGuiShader();
    Quad::Draw(collisionTextureId, GL_TEXTURE0);
    if (GuiManager::getInstance()->guiRenderer->debugMode) {
        guiFrameBuffer->DrawCollisionBuffer();
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GuiWidget::Draw() {
    RenderManager::getInstance()->RenderGuiShader();
    Quad::Draw(textureId, GL_TEXTURE0);
}

void GuiWidget::Click() {

}

void GuiWidget::Hold() {

}

const int GuiWidget::Uid() const {
    return static_cast<const int>(this->collisionColor.r + this->collisionColor.g + this->collisionColor.b);
}
