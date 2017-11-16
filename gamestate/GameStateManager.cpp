//
// Created by Joonas on 11/9/2017.
//

#include "GameStateManager.h"

GameStateManager *GameStateManager::gameStateManager = 0;

GameStateManager *GameStateManager::getInstance() {
    if (gameStateManager == nullptr) {
        gameStateManager = new GameStateManager();
    }
    return gameStateManager;
}

void GameStateManager::renderActiveGameState() {
    if (getActiveGameState() != nullptr) {
        getActiveGameState()->Draw();
    }
}

GameState *GameStateManager::getActiveGameState() {
    return activeGameState;
}

void GameStateManager::setActiveGameState(GameState *gameState) {
    activeGameState = gameState;
}
