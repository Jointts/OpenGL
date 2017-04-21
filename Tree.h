//
// Created by Joonas on 21/04/2017.
//

#ifndef OPENGL_TREE_H
#define OPENGL_TREE_H


#include "Entity.h"

class Tree : public Entity{
public:
    Tree(GLchar *modelPath, bool generateCollision);
    void printShit();
};


#endif //OPENGL_TREE_H
