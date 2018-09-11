//
// Created by Joonas on 3/16/2017.
//

#include "PhysicsManager.h"

PhysicsManager* PhysicsManager::physicsManager = 0;
WorldPhysics  * PhysicsManager::worldPhysics   = 0;

PhysicsManager::PhysicsManager() {
    worldPhysics = new WorldPhysics();
}

PhysicsManager* PhysicsManager::getInstance() {
    if (!physicsManager) {
        physicsManager = new PhysicsManager;
    }
    return physicsManager;
}

void PhysicsManager::Tick() {
    worldPhysics->Tick();
}
