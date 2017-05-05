//
// Created by Joonas on 05/05/2017.
//

#ifndef OPENGL_PLAYERCONTROLLER_H
#define OPENGL_PLAYERCONTROLLER_H

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <vec3.hpp>
#include <BulletDynamics/Character/btKinematicCharacterController.h>

class EntityController {

public:
    EntityController();

    void MoveToCoord(glm::vec3 worldCoord);

    float getMovementSpeed() const;

    void setMovementSpeed(float movementSpeed);

    void CheckPosition();

private:
    btVector3 currentWalkDirection;

    glm::vec3 targetCoord;

    float movementSpeed = 1.0f;

    btKinematicCharacterController *m_character;

    btPairCachingGhostObject *m_ghostObject;

    void SetupCollision();

};


#endif //OPENGL_PLAYERCONTROLLER_H
