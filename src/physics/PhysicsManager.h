//
// Created by Joonas on 3/16/2017.
//

#ifndef OPENGL_PHYSICSMANAGER_H
#define OPENGL_PHYSICSMANAGER_H


#include <LinearMath/btVector3.h>
#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>
#include <BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>
#include <BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <BulletCollision/BroadphaseCollision/btDbvtBroadphase.h>
#include "../Entity.h"
#include "WorldPhysics.h"

class PhysicsManager {


public:

    static PhysicsManager *physicsManager;

    PhysicsManager();

    static PhysicsManager *getInstance();

    static WorldPhysics *worldPhysics;

    void Tick();
};


#endif //OPENGL_PHYSICSMANAGER_H
