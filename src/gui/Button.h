//
// Created by Joonas on 11/7/2017.
//

#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H


#include "GuiWidget.h"

class Button : public GuiWidget {
public:

    Button(int width, int height);

    void Click() override;
    std::function<void()> clickEvent;
};


#endif //GAME_BUTTON_H
