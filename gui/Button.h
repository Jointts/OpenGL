//
// Created by Joonas on 11/7/2017.
//

#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H


#include "GuiWidget.h"

class Button : public GuiWidget{
public:
    std::function<void()> clickEvent;

    Button(int width, int height);
    void Click() override;
};


#endif //GAME_BUTTON_H
