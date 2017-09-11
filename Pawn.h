//
// Created by Joonas on 23/06/2017.
//

#ifndef OPENGL_PAWN_H
#define OPENGL_PAWN_H


#include "Entity.h"
#include "EntityController.h"

class Pawn : public Entity{
public:
    Pawn(GLchar *modelPath, bool generateCollision);

public:
    EntityController* entityController;
};


#endif //OPENGL_PAWN_H
