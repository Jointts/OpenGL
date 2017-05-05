//
// Created by Joonas on 01/05/2017.
//

#ifndef OPENGL_WORLDPHYSICS_H
#define OPENGL_WORLDPHYSICS_H


#include "../Entity.h"

class WorldPhysics {
public:
    bool mouseOneClicked = false;

    btRigidBody *rigidBody;

    btDiscreteDynamicsWorld *dynamicsWorld;

    void InitPhysics();

    void RayCast(double mouseX, double mouseY);

    void getHitEntityType(Entity *hitEntity);

    static Entity *lastHitEntity;

    void Tick();
};


#endif //OPENGL_WORLDPHYSICS_H
