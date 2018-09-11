//
// Created by Joonas on 23/06/2017.
//

#ifndef SUMMIT_ENGINE_PAWN_H
#define SUMMIT_ENGINE_PAWN_H


#include "Entity.h"
#include "EntityController.h"

class Pawn : public Entity {
public:
    Pawn(GLchar *modelPath, bool generateCollision);

public:
    EntityController *entityController;
};


#endif //SUMMIT_ENGINE_PAWN_H
