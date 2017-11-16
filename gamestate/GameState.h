//
// Created by Joonas on 11/9/2017.
//

#ifndef GAME_GAMESTATE_H
#define GAME_GAMESTATE_H


class GameState {

public:
    virtual void Init() = 0;

    virtual void Cleanup() = 0;

    virtual void Pause() = 0;

    virtual void Resume() = 0;

    virtual void HandleEvents() = 0;

    virtual void Update() = 0;

    virtual void Draw() = 0;

    ~GameState();
};


#endif //GAME_GAMESTATE_H
