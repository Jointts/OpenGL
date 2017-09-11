//
// Created by Joonas on 05/09/2017.
//

#ifndef OPENGL_GUIMANAGER_H
#define OPENGL_GUIMANAGER_H


#include "Gui.h"

class GuiManager {

public:
    static GuiManager *guiManager;
    static Gui *gui;

    GuiManager::GuiManager();

    static GuiManager* GuiManager::getInstance();
};


#endif //OPENGL_GUIMANAGER_H
