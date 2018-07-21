//
// Created by Joonas on 05/05/2017.
//

#ifndef SUMMIT_ENGINE_ENTITYMANAGER_H
#define SUMMIT_ENGINE_ENTITYMANAGER_H

#include <vector>
#include "EntityController.h"
#include "Player.h"

class EntityManager {
public:

    std::vector<Entity *> entities;
    static Player         *player;
    static EntityManager  *entityManager;

    static EntityManager *getInstance();
};


#endif //SUMMIT_ENGINE_ENTITYMANAGER_H
