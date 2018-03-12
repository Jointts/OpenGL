//
// Created by Joonas on 23/06/2017.
//

#ifndef SUMMIT_ENGINE_PLAYER_H
#define SUMMIT_ENGINE_PLAYER_H


#include "Pawn.h"

class Player : public Pawn{
public:

    Player(GLchar *modelPath, bool generateCollision);
    void Rotate(float angle, glm::vec3 axis) override;
    void Scale(glm::vec3 axis) override;
    void Translate(glm::vec3 axis) override;
    void setMovementSpeed(float speed);
};


#endif //SUMMIT_ENGINE_PLAYER_H
