//
// Created by Joonas on 21/04/2017.
//

#include "Tree.h"

Tree::Tree(GLchar *modelPath, bool generateCollision) : Entity(modelPath, generateCollision) {
    entityType = TREE;
}

void Tree::printShit() {
    printf("Its a subclass of tree");
}

void Tree::ClickEvent() {
    printf("Eat shit");
}
