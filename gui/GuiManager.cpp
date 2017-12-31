//
// Created by Joonas on 05/09/2017.
//

#include <vector>
#include "GuiManager.h"

GuiManager *GuiManager::guiManager = 0;
GuiCollision *GuiManager::guiCollision = 0;

GuiManager::GuiManager() {
    guiCollision = new GuiCollision();
}

GuiManager* GuiManager::getInstance() {
    if(!guiManager){
        guiManager = new GuiManager();
    }
    return guiManager;
}

void GuiManager::addWidgetToRenderQueue(GuiWidget *guiWidget) {
    guiWidgets.push_back(guiWidget);
}
