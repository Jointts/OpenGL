//
// Created by Joonas on 05/09/2017.
//

#ifndef OPENGL_GUIMANAGER_H
#define OPENGL_GUIMANAGER_H


#include "GuiWidget.h"
#include "GuiCollision.h"

class GuiManager {

public:
    static GuiManager *guiManager;

    GuiManager();

    static GuiManager* getInstance();

    static GuiCollision* guiCollision;

    void addWidgetToRenderQueue(GuiWidget* guiWidget);

    std::vector<GuiWidget*> guiWidgets;
};


#endif //OPENGL_GUIMANAGER_H
