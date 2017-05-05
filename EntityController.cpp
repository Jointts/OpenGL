//
// Created by Joonas on 05/05/2017.
//

#include <LinearMath/btScalar.h>
#include <BulletCollision/CollisionShapes/btBoxShape.h>
#include <BulletCollision/CollisionDispatch/btCollisionDispatcher.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>
#include <BulletCollision/CollisionShapes/btCapsuleShape.h>
#include <ext.hpp>
#include "EntityController.h"
#include "physics/PhysicsManager.h"
#include "camera/CameraManager.h"

EntityController::EntityController() {
    SetupCollision();
}

void EntityController::SetupCollision(){
    btDiscreteDynamicsWorld *m_dynamicsWorld = PhysicsManager::getInstance()->worldPhysics->dynamicsWorld;

    btTransform startTransform;
    startTransform.setIdentity();
    startTransform.setOrigin (btVector3(3.0f, 3.0f, 3.0f));

    m_ghostObject = new btPairCachingGhostObject();
    m_ghostObject->setWorldTransform(startTransform);
    btScalar characterHeight=1.75;
    btScalar characterWidth =1.75;
    btConvexShape* capsule = new btCapsuleShape(characterWidth,characterHeight);
    m_ghostObject->setCollisionShape (capsule);
    m_ghostObject->setCollisionFlags (btCollisionObject::CF_CHARACTER_OBJECT);

    btScalar stepHeight = btScalar(0.35);
    m_character = new btKinematicCharacterController (m_ghostObject, capsule, stepHeight);

    m_character->setWalkDirection(btVector3(0.2, 0.0, 0.2));

    m_character->setUp(btVector3(0.0, 1.0, 0.0));

    m_dynamicsWorld->addCollisionObject(m_ghostObject,btBroadphaseProxy::CharacterFilter, btBroadphaseProxy::StaticFilter|btBroadphaseProxy::DefaultFilter);

    m_dynamicsWorld->addAction(m_character);

}

void EntityController::MoveToCoord(glm::vec3 worldCoord){
    targetCoord = worldCoord;

    glm::vec3 sourceCoord = glm::vec3(
            m_ghostObject->getWorldTransform().getOrigin().getX(),
            m_ghostObject->getWorldTransform().getOrigin().getY(),
            m_ghostObject->getWorldTransform().getOrigin().getZ()
    );

    glm::vec3 finalVector = glm::normalize(worldCoord - sourceCoord);

    currentWalkDirection = movementSpeed * btVector3(finalVector.x, 0, finalVector.z);

    m_character->setWalkDirection(currentWalkDirection);
}

//  Should be called on every tick of the physics engine
void EntityController::CheckPosition(){
    glm::vec3 sourceCoord = glm::vec3(
            m_ghostObject->getWorldTransform().getOrigin().getX(),
            m_ghostObject->getWorldTransform().getOrigin().getY(),
            m_ghostObject->getWorldTransform().getOrigin().getZ()
    );

    if(m_character->getLinearVelocity().getX() != 0 && m_character->getLinearVelocity().getZ() != 0){
        //  We are moving, check if we are near the target, if so, start slowing down and eventually stop

        glm::vec3 coordDistance = glm::abs(targetCoord - sourceCoord);

        if(coordDistance.x <= 1.0f && coordDistance.z <= 1.0f){
            m_character->setWalkDirection(btVector3(0, 0, 0));
        }
    }

    CameraManager::getInstance()->mainCamera->cameraPos = glm::vec3(sourceCoord.x, 10.0f, sourceCoord.z + 5.0f);
    CameraManager::getInstance()->mainCamera->UpdateCamera();
}

float EntityController::getMovementSpeed() const {
    return movementSpeed;
}

void EntityController::setMovementSpeed(float movementSpeed) {
    EntityController::movementSpeed = movementSpeed;
}
