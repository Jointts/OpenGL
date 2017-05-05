//
// Created by Joonas on 05/05/2017.
//

#include "EntityManager.h"

EntityManager* EntityManager::entityManager = 0;
EntityController* EntityManager::playerController = 0;

EntityManager::EntityManager() {
    playerController = new EntityController();
}

EntityManager* EntityManager::getInstance(){
    if(!entityManager){
        entityManager = new EntityManager();
    }
    return entityManager;
}
