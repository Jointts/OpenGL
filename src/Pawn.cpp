//
// Created by Joonas on 23/06/2017.
//

#include "Pawn.h"

Pawn::Pawn(GLchar *modelPath, bool generateCollision) : Entity(modelPath, generateCollision) {
    entityController = new EntityController(model, this);
}
