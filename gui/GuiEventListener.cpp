//
// Created by Joonas on 11/7/2017.
//

#include "GuiEventListener.h"
#include "GuiManager.h"
#include "../ControllerManager.h"

void GuiEventListener::CheckEvents() {
    glm::vec3 cursorColor = GuiManager::getInstance()->guiFrameBuffer->cursorColor;
    std::vector<GuiWidget*> guiWidgets = GuiManager::getInstance()->guiWidgets;
    for(GuiWidget* guiWidget : guiWidgets){
        if(guiWidget->collisionColor == cursorColor && ControllerManager::mouseOneClickEventPropagate) guiWidget->Click();
    }
}