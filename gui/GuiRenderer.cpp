//
// Created by Joonas on 11/7/2017.
//

#include "GuiRenderer.h"
#include "GuiManager.h"

void GuiRenderer::RenderGui() {
    for(GuiWidget* widget : GuiManager::getInstance()->guiWidgets){
        widget->Draw();
        if(debugMode){
            widget->DrawCollision();
        }
    }
}
