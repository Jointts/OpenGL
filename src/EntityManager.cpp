//
// Created by Joonas on 05/05/2017.
//

#include "EntityManager.h"

EntityManager *EntityManager::entityManager = nullptr;
Player        *EntityManager::player        = nullptr;

EntityManager *EntityManager::getInstance() {
    if (!entityManager) {
        entityManager = new EntityManager();
    }
    return entityManager;
}
