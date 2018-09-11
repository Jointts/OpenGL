//
// Created by Joonas on 11/7/2017.
//

#include "GuiEventHandler.h"
#include "GuiManager.h"
#include "../controller/ControllerManager.h"

void GuiEventHandler::CheckEvents() {
    glm::vec3 cursorColor = GuiManager::getInstance()->guiFrameBuffer->cursorColor;
    std::vector<GuiWidget *> guiWidgets = GuiManager::getInstance()->guiWidgets;
    for (GuiWidget *guiWidget : guiWidgets) {
        if (guiWidget->collisionColor == cursorColor && MouseController::getInstance()->checkButtonInput(GLFW_MOUSE_BUTTON_LEFT, KeyState::CLICKED)){
            guiWidget->Click();
        }
    }
}