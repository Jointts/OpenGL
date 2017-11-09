//
// Created by Joonas on 11/9/2017.
//

#ifndef GAME_GAMESTATEMANAGER_H
#define GAME_GAMESTATEMANAGER_H


#include "GameState.h"

class GameStateManager {
public:
    static GameStateManager* gameStateManager;
    static GameStateManager *getInstance();

    GameState *getActiveGameState();

private:
    GameState* activeGameState;

    GameState setActiveGameState(GameState *gameState);

    void renderActiveGameState();
};


#endif //GAME_GAMESTATEMANAGER_H
