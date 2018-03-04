//
// Created by Joonas on 05/05/2017.
//

#ifndef OPENGL_PLAYERCONTROLLER_H
#define OPENGL_PLAYERCONTROLLER_H

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <glm/vec3.hpp>
#include <BulletDynamics/Character/btKinematicCharacterController.h>
#include "Model.h"
#include "Entity.h"

class EntityController {

public:
    EntityController(Model *attachedModel);

    EntityController(Model *attachedModel, Entity *entity);

    void MoveToCoord(glm::vec3 worldCoord);

    float getMovementSpeed() const;

    void setMovementSpeed(float movementSpeed);

    void CheckPosition();

    void SetMoveDirection(glm::vec3 moveDirection);

    btPairCachingGhostObject *m_ghostObject;
private:

    Model* attachedModel;

    btVector3 currentWalkDirection;

    glm::vec3 targetCoord;

    float movementSpeed = 1.0f;

    btKinematicCharacterController *m_character;

    void SetupCollision();

    void FaceCoord(glm::vec3 coordToFace);

    Entity* entity;
};


#endif //OPENGL_PLAYERCONTROLLER_H
