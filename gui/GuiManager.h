//
// Created by Joonas on 05/09/2017.
//

#ifndef OPENGL_GUIMANAGER_H
#define OPENGL_GUIMANAGER_H


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


#endif //OPENGL_GUIMANAGER_H
