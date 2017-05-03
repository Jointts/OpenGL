//
// Created by Joonas on 01/05/2017.
//

#ifndef OPENGL_GUIPHYSICS_H
#define OPENGL_GUIPHYSICS_H


#include "../Entity.h"

class GuiPhysics {

    btRigidBody *rigidBody;

public:
    static Entity *lastHitEntity;

    static void getHitEntityType(Entity *hitEntity);

    void RayCast(double mouseX, double mouseY);

    void InitPhysics();

    btDiscreteDynamicsWorld *dynamicsWorld;

    void Tick();
};


#endif //OPENGL_GUIPHYSICS_H
