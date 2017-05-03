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
GuiPhysics *PhysicsManager::guiPhysics = 0;
WorldPhysics *PhysicsManager::worldPhysics = 0;

PhysicsManager::PhysicsManager() {
    guiPhysics = new GuiPhysics();
    worldPhysics = new WorldPhysics();
}

PhysicsManager *PhysicsManager::getInstance() {
    if(!physicsManager){
        physicsManager = new PhysicsManager;
    }
    return physicsManager;
}

void PhysicsManager::Tick(){
    guiPhysics->Tick();
    worldPhysics->Tick();
}
