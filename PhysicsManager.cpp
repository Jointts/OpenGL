//
// Created by Joonas on 3/16/2017.
//

#include "PhysicsManager.h"

PhysicsManager *PhysicsManager::physicsManager = 0;

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
    btDiscreteDynamicsWorld *dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0, -9.81f, 0));
}

PhysicsManager *PhysicsManager::getInstance() {
    if(!physicsManager){
        physicsManager = new PhysicsManager;
    }
    return physicsManager;
}