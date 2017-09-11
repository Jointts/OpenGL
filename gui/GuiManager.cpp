//
// Created by Joonas on 05/09/2017.
//

#include "GuiManager.h"

GuiManager *GuiManager::guiManager = 0;
Gui *GuiManager::gui = 0;

GuiManager::GuiManager() {
    gui = new Gui();
}

GuiManager* GuiManager::getInstance() {
    if(!guiManager){
        guiManager = new GuiManager();
    }
    return guiManager;
}