//
// Created by Joonas on 05/05/2017.
//

#ifndef OPENGL_ENTITYMANAGER_H
#define OPENGL_ENTITYMANAGER_H

#include <vector>
#include "EntityController.h"
#include "Player.h"

class EntityManager {
public:

    static Player* player;

    static EntityManager *entityManager;

    static EntityManager * getInstance();

    std::vector<Entity *> entities;
};


#endif //OPENGL_ENTITYMANAGER_H
