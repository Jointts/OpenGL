//
// Created by Joonas on 05/05/2017.
//

#ifndef OPENGL_ENTITYMANAGER_H
#define OPENGL_ENTITYMANAGER_H

#include "EntityController.h"

class EntityManager {
public:
    EntityManager();

    static EntityController *playerController;
    static EntityManager *entityManager;

    static EntityManager * getInstance();
};


#endif //OPENGL_ENTITYMANAGER_H
