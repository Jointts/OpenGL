//
// Created by Joonas on 05/09/2017.
//

#ifndef SUMMIT_ENGINE_GUIMANAGER_H
#define SUMMIT_ENGINE_GUIMANAGER_H


#include "GuiFrameBuffer.h"
#include "GuiRenderer.h"
#include "GuiEventListener.h"

class GuiManager {
    int GetNextUid();
public:
    static GuiManager      * guiManager;
    static GuiFrameBuffer  * guiFrameBuffer;
    static GuiRenderer     * guiRenderer;
    static GuiEventListener* guiEventListener;
    std::vector<GuiWidget*> guiWidgets;

    GuiManager();

    static GuiManager* getInstance();

    glm::vec3 CalculateNextCollisionColor();
};


#endif //SUMMIT_ENGINE_GUIMANAGER_H
