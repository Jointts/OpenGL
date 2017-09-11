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
#include "EntityManager.h"
#include "Utils.h"

EntityController::EntityController(Model* attachedModel, Entity* entity) {
    SetupCollision();
    this->attachedModel = attachedModel;
    this->entity = entity;
}

void EntityController::SetupCollision(){
    btDiscreteDynamicsWorld *m_dynamicsWorld = PhysicsManager::getInstance()->worldPhysics->dynamicsWorld;

    btTransform startTransform;
    startTransform.setIdentity();
    startTransform.setOrigin (btVector3(3.0f, 3.0f, 3.0f));
    startTransform.setRotation(btQuaternion(btVector3(1.0, 0.0, 0.0), glm::radians(90.0f)));

    m_ghostObject = new btPairCachingGhostObject();
    m_ghostObject->setWorldTransform(startTransform);
    btScalar characterHeight=1.75;
    btScalar characterWidth =1.75;
    btConvexShape* capsule = new btCapsuleShape(characterWidth,characterHeight);
    m_ghostObject->setCollisionShape (capsule);
    m_ghostObject->setCollisionFlags (btCollisionObject::CF_CHARACTER_OBJECT);

    btScalar stepHeight = btScalar(0.35);
    m_character = new btKinematicCharacterController (m_ghostObject, capsule, stepHeight);

    m_character->setWalkDirection(btVector3(0.0, 0.0, 0.0));

    m_character->setUp(btVector3(0.0, 1.0, 0.0));

    m_dynamicsWorld->addCollisionObject(m_ghostObject,btBroadphaseProxy::CharacterFilter, btBroadphaseProxy::StaticFilter|btBroadphaseProxy::DefaultFilter);

    m_dynamicsWorld->addAction(m_character);
}

void EntityController::FaceCoord(glm::vec3 coordToFace){
    btTransform currentTransform = m_ghostObject->getWorldTransform();

    glm::vec3 sourceCoord = glm::vec3(
            m_ghostObject->getWorldTransform().getOrigin().getX(),
            m_ghostObject->getWorldTransform().getOrigin().getY(),
            m_ghostObject->getWorldTransform().getOrigin().getZ()
    );

    glm::vec3 finalVector = glm::normalize(coordToFace - sourceCoord);

    float currentAngle = glm::radians(currentTransform.getRotation().getAngle());

    float angle = glm::degrees(std::atan2(finalVector.x, finalVector.z));

    angle = (int) (angle + 360) % 360;

    angle = glm::radians(angle);

    btQuaternion newRotation;

    newRotation.setEuler(currentAngle + angle, 0, 0);

    currentTransform.setRotation(newRotation);

    m_ghostObject->setWorldTransform(currentTransform);
}

void EntityController::MoveToCoord(glm::vec3 worldCoord){

    // Code for moving the collision object
    targetCoord = worldCoord;

    glm::vec3 sourceCoord = glm::vec3(
            m_ghostObject->getWorldTransform().getOrigin().getX(),
            m_ghostObject->getWorldTransform().getOrigin().getY(),
            m_ghostObject->getWorldTransform().getOrigin().getZ()
    );

    glm::vec3 finalVector = glm::normalize(worldCoord - sourceCoord);

    currentWalkDirection = movementSpeed * btVector3(finalVector.x, 0, finalVector.z);

    m_character->setWalkDirection(currentWalkDirection);

    FaceCoord(worldCoord);

    //Code for moving the actual model

}

void EntityController::SetMoveDirection(glm::vec3 moveDirection){
    m_character->setWalkDirection(movementSpeed * btVector3(moveDirection.x, moveDirection.y, moveDirection.z));
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

        if(coordDistance.x <= 0.5f && coordDistance.z <= 0.5f){
            m_character->setWalkDirection(btVector3(0, 0, 0));
        }
    }


    btScalar physicsMatrix[16];
    m_ghostObject->getWorldTransform().getOpenGLMatrix(physicsMatrix);
    attachedModel->model = Utils::BulletToGlm(physicsMatrix);

    CameraManager::getInstance()->mainCamera->cameraPos = glm::vec3(sourceCoord.x, sourceCoord.y + 10.0f, sourceCoord.z + 5.0f);
    CameraManager::getInstance()->mainCamera->UpdateCamera();
}

float EntityController::getMovementSpeed() const {
    return movementSpeed;
}

void EntityController::setMovementSpeed(float movementSpeed) {
    EntityController::movementSpeed = movementSpeed;
}
