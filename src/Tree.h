//
// Created by Joonas on 21/04/2017.
//

#ifndef SUMMIT_ENGINE_TREE_H
#define SUMMIT_ENGINE_TREE_H


#include "Entity.h"

class Tree : public Entity{
public:
    Tree(GLchar *modelPath, bool generateCollision);
    void printShit();

    void ClickEvent() override;
};


#endif //SUMMIT_ENGINE_TREE_H
