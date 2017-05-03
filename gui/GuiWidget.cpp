//
// Created by Joonas on 01/05/2017.
//

#include <BulletCollision/CollisionShapes/btSphereShape.h>
#include <LinearMath/btDefaultMotionState.h>
#include "GuiWidget.h"
#include "../Utils.h"
#include "../RenderManager.h"
#include "../physics/PhysicsManager.h"
#include <BulletCollision/CollisionShapes/btBox2dShape.h>

GuiWidget::GuiWidget(int width, int height) : Quad(width, height) {

}

void GuiWidget::UpdatePosition(){
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
}

float GuiWidget::getMarginLeft() const {
    return marginLeft;
}

void GuiWidget::setMarginLeft(float marginLeft) {
    this->marginLeft = marginLeft;
    vertices[0].position.x = marginLeft;
    vertices[1].position.x = marginLeft;
    vertices[2].position.x = width + marginLeft;
    vertices[3].position.x = width + marginLeft;
    UpdatePosition();
}

float GuiWidget::getMarginRight() const {
    return marginRight;
}

void GuiWidget::setMarginRight(float marginRight) {
    float displayWidth = 1440.0f;
    this->marginRight = marginRight;
    vertices[0].position.x = displayWidth - marginRight;
    vertices[1].position.x = displayWidth - marginRight;
    vertices[2].position.x = displayWidth - (width + marginRight);
    vertices[3].position.x = displayWidth - (width + marginRight);
    UpdatePosition();
}

float GuiWidget::getMarginTop() const {
    return marginTop;
}

void GuiWidget::setMarginTop(float marginTop) {
    float displayHeight = 900.0f;
    this->marginTop = marginTop;
    vertices[0].position.y = displayHeight - marginTop;
    vertices[1].position.y = displayHeight - (height + marginTop);
    vertices[2].position.y = displayHeight - (height + marginTop);
    vertices[3].position.y = displayHeight - marginTop;
    UpdatePosition();
}

float GuiWidget::getMarginBottom() const {
    return marginBottom;
}

void GuiWidget::setMarginBottom(float marginBottom) {
    this->marginBottom = marginBottom;
    vertices[0].position.y = marginBottom;
    vertices[1].position.y = height + marginBottom;
    vertices[2].position.y = height + marginBottom;
    vertices[3].position.y = marginBottom;
    UpdatePosition();
}

void GuiWidget::setTexture(GLchar *path){

    textureId = Utils::TextureFromFile(path, true);
}

void GuiWidget::GenerateCollision(){

    btSphereShape* btSphereShape_ =  new btSphereShape(3);

    btDefaultMotionState* motionstate = new btDefaultMotionState(btTransform(
            btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)
    ));

    btScalar mass = 1;

    btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
            0,               // mass, in kg. 0 -> Static object, will never move.
            motionstate,
            btSphereShape_,        // collision shape of body
            btVector3(0,0,0)    // local inertia
    );

    rigidBody = new btRigidBody(rigidBodyCI);
    rigidBody->setUserPointer(this);

    PhysicsManager::getInstance()->guiPhysics->dynamicsWorld->addRigidBody(rigidBody);
}

void GuiWidget::Draw() {
    RenderManager::getInstance()->RenderGuiShader();
    Quad::Draw();
}
