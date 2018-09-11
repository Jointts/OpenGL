//
// Created by Joonas on 05/05/2017.
//

#ifndef SUMMIT_ENGINE_PLAYERCONTROLLER_H
#define SUMMIT_ENGINE_PLAYERCONTROLLER_H

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <glm/vec3.hpp>
#include <BulletDynamics/Character/btKinematicCharacterController.h>
#include "Model.h"
#include "Entity.h"

class EntityController {

public:
    float getMovementSpeed() const;
    btPairCachingGhostObject *m_ghostObject;

    EntityController(Model *attachedModel);
    EntityController(Model *attachedModel, Entity *entity);

    void MoveToCoord(glm::vec3 worldCoord);
    void setMovementSpeed(float movementSpeed);
    void CheckPosition();
    void SetMoveDirection(glm::vec3 moveDirection);

private:
    float                          movementSpeed = 1.0f;
    Entity                         *entity;
    Model                          *attachedModel;
    btVector3                      currentWalkDirection;
    glm::vec3                      targetCoord;
    btKinematicCharacterController *m_character;

    void SetupCollision();
    void FaceCoord(glm::vec3 coordToFace);

};


#endif //SUMMIT_ENGINE_PLAYERCONTROLLER_H
