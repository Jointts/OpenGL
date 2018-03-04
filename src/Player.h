//
// Created by Joonas on 23/06/2017.
//

#ifndef OPENGL_PLAYER_H
#define OPENGL_PLAYER_H


#include "Pawn.h"

class Player : public Pawn{
public:

    Player(GLchar *modelPath, bool generateCollision);
    void Rotate(float angle, glm::vec3 axis) override;
    void Scale(glm::vec3 axis) override;
    void Translate(glm::vec3 axis) override;
    void setMovementSpeed(float speed);
};


#endif //OPENGL_PLAYER_H
