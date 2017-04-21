//
// Created by Joonas on 3/16/2017.
//

#include <BulletCollision/CollisionShapes/btBoxShape.h>
#include <LinearMath/btIDebugDraw.h>
#include <gtc/matrix_transform.hpp>
#include "PhysicsManager.h"
#include "../DebugDrawer.h"
#include "../Entity.h"
#include "../camera/CameraManager.h"
#include "../Tree.h"

PhysicsManager *PhysicsManager::physicsManager = 0;
Entity *PhysicsManager::lastHitEntity = 0;

void PhysicsManager::InitPhysics() {
    // Initialize Bullet. This strictly follows http://bulletphysics.org/mediawiki-1.5.8/index.php/Hello_World,
    // even though we won't use most of this stuff.

    // Build the broadphase
    btBroadphaseInterface *broadphase = new btDbvtBroadphase();

    // Set up the collision configuration and dispatcher
    btDefaultCollisionConfiguration *collisionConfiguration = new btDefaultCollisionConfiguration();
    btCollisionDispatcher *dispatcher = new btCollisionDispatcher(collisionConfiguration);

    // The actual physics solver
    btSequentialImpulseConstraintSolver *solver = new btSequentialImpulseConstraintSolver;

    // The world.
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0, -9.81f, 0));

    DebugDrawer* debugDrawer = new DebugDrawer();
    debugDrawer->setup();

    debugDrawer->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
    dynamicsWorld->setDebugDrawer(debugDrawer);
}

PhysicsManager *PhysicsManager::getInstance() {
    if(!physicsManager){
        physicsManager = new PhysicsManager;
    }
    return physicsManager;
}

void PhysicsManager::RayCast(double mouseX, double mouseY) {
    GLint viewportWidth = 1440;
    GLint viewportHeight = 900;

    //  Since OpenGL coordinates start from the lower left corner, we need to correct the Y coordinate
    mouseY = viewportHeight - mouseY;

    glm::vec3 mouseScreenStartPos(mouseX, mouseY, 0.0f);
    glm::vec3 mouseScreenEndPos(mouseX, mouseY, 1.0f);

    glm::mat4 projection = CameraManager::getInstance()->mainCamera->perspective;
    glm::mat4 view = CameraManager::getInstance()->mainCamera->view;
    glm::mat4 model = glm::mat4();
    glm::vec4 viewport(0.0f, 0.0f, viewportWidth, viewportHeight);

    // Transform screen-space coordinates to world-space (Start and End Ray)
    glm::vec3 projectedMouseStartPos = glm::unProject(mouseScreenStartPos, view * model, projection, viewport);
    glm::vec3 projectedMouseEndPos = glm::unProject(mouseScreenEndPos, view * model, projection, viewport);

    //  Convert vectors to bullet vectors
    btVector3 bulletStartPos(projectedMouseStartPos.x, projectedMouseStartPos.y, projectedMouseStartPos.z);
    btVector3 bulletEndPos(projectedMouseEndPos.x, projectedMouseEndPos.y, projectedMouseEndPos.z);

    //  Cast the ray to the world space
    btCollisionWorld::ClosestRayResultCallback rayCallBack(bulletStartPos, bulletEndPos);
    PhysicsManager::getInstance()->dynamicsWorld->rayTest(bulletStartPos, bulletEndPos, rayCallBack);

    //  Check if the ray hit something
    if(rayCallBack.hasHit()) {
        Entity* hitEntity = (Entity*) rayCallBack.m_collisionObject->getUserPointer();
        getHitEntityType(hitEntity);
        hitEntity->model->drawOutline = true;
        lastHitEntity = hitEntity;
    }else{
        if(!lastHitEntity) return;
        lastHitEntity->model->drawOutline = false;
    }
}

void PhysicsManager::getHitEntityType(Entity *hitEntity) {
    Tree* tree = NULL;

    switch(hitEntity->entityType){
        case TREE:
            tree = (Tree*) hitEntity;
            tree->printShit();
            break;
        default:
            return;
    }
}
