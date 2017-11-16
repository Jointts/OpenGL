//
// Created by Joonas on 05/09/2017.
//

#include "GuiManager.h"

GuiManager *GuiManager::guiManager = 0;
GuiFrameBuffer *GuiManager::guiFrameBuffer = 0;
GuiRenderer *GuiManager::guiRenderer = 0;
GuiEventListener *GuiManager::guiEventListener = 0;

GuiManager::GuiManager() {
    guiFrameBuffer = new GuiFrameBuffer();
    guiRenderer = new GuiRenderer();
    guiEventListener = new GuiEventListener();
}

GuiManager *GuiManager::getInstance() {
    if (!guiManager) {
        guiManager = new GuiManager();
    }
    return guiManager;
}