//
// Created by Joonas on 23/06/2017.
//

#include <ext.hpp>
#include "Player.h"
#include "EntityManager.h"
#include "exceptions/PlayerAlreadyExistsException.h"
#include "Utils.h"

Player::Player(GLchar *modelPath, bool generateCollision) : Pawn(modelPath, generateCollision) {
    if(EntityManager::getInstance()->player != 0){
        throw PlayerAlreadyExistsException();
    }
    EntityManager::getInstance()->player = this;
}

void Player::Rotate(float angle, glm::vec3 axis) {
    ATTRIBUTE_ALIGNED16(btScalar physicsMatrix[16]);
    btTransform transform = entityController->m_ghostObject->getWorldTransform();
    transform.getOpenGLMatrix(physicsMatrix);
    glm::mat4 rotatedMatrix = glm::rotate(Utils::BulletToGlm(physicsMatrix), angle, axis);
    entityController->m_ghostObject->setWorldTransform(Utils::glmToBullet(rotatedMatrix));
}

void Player::Scale(glm::vec3 axis) {
    ATTRIBUTE_ALIGNED16(btScalar physicsMatrix[16]);
    btTransform transform = entityController->m_ghostObject->getWorldTransform();
    transform.getOpenGLMatrix(physicsMatrix);
    glm::mat4 scaledMatrix = glm::scale(Utils::BulletToGlm(physicsMatrix), axis);
    entityController->m_ghostObject->setWorldTransform(Utils::glmToBullet(scaledMatrix));
}

void Player::Translate(glm::vec3 axis) {
    ATTRIBUTE_ALIGNED16(btScalar physicsMatrix[16]);
    btTransform transform = entityController->m_ghostObject->getWorldTransform();
    transform.getOpenGLMatrix(physicsMatrix);
    glm::mat4 translatedMatrix = glm::translate(Utils::BulletToGlm(physicsMatrix), axis);
    entityController->m_ghostObject->setWorldTransform(Utils::glmToBullet(translatedMatrix));
}
