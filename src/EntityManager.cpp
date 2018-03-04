//
// Created by Joonas on 05/05/2017.
//

#include "EntityManager.h"

EntityManager* EntityManager::entityManager = 0;
Player* EntityManager::player = 0;

EntityManager* EntityManager::getInstance(){
    if(!entityManager){
        entityManager = new EntityManager();
    }
    return entityManager;
}
