//
// Created by Joonas on 11/9/2017.
//

#ifndef GAME_MENUGAMESTATE_H
#define GAME_MENUGAMESTATE_H


#include "GameState.h"
#include "../gui/GuiWidget.h"

class MenuGameState : public GameState{
public:
    void RenderGameState();

private:
    std::vector<GuiWidget*> guiWidgets;

};


#endif //GAME_MENUGAMESTATE_H
