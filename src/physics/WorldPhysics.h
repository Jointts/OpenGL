//
// Created by Joonas on 01/05/2017.
//

#ifndef OPENGL_WORLDPHYSICS_H
#define OPENGL_WORLDPHYSICS_H


#include "../Entity.h"

class WorldPhysics {
public:
    static Entity           *lastHitEntity;
    bool                    debugDrawing    = false;
    bool                    mouseOneClicked = false;
    btRigidBody             *rigidBody;
    btDiscreteDynamicsWorld *dynamicsWorld;

    void InitPhysics();
    void RayCast(double mouseX, double mouseY);
    void getHitEntityType(Entity *hitEntity);
    void Tick();
    void AddPlayer();
};


#endif //OPENGL_WORLDPHYSICS_H
