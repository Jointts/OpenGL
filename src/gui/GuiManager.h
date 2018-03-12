//
// Created by Joonas on 05/09/2017.
//

#ifndef SUMMIT_ENGINE_GUIMANAGER_H
#define SUMMIT_ENGINE_GUIMANAGER_H


#include "GuiFrameBuffer.h"
#include "GuiRenderer.h"
#include "GuiEventListener.h"

class GuiManager {

public:
    static GuiManager *guiManager;
    static GuiFrameBuffer *guiFrameBuffer;
    std::vector<GuiWidget *> guiWidgets;

    GuiManager();

    static GuiManager *getInstance();

    static GuiRenderer *guiRenderer;

    static GuiEventListener *guiEventListener;
};


#endif //SUMMIT_ENGINE_GUIMANAGER_H
