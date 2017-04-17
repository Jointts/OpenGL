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

class PhysicsManager {


public:
    btRigidBody *rigidBody;

    btDiscreteDynamicsWorld *dynamicsWorld;

    void InitPhysics();

    static PhysicsManager *physicsManager;

    static PhysicsManager *getInstance();

    void UpdatePositions();
};


#endif //OPENGL_PHYSICSMANAGER_H
