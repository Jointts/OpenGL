//
// Created by Joonas on 05/09/2017.
//

#include "GuiManager.h"

GuiManager       *GuiManager::guiManager       = nullptr;
GuiFrameBuffer   *GuiManager::guiFrameBuffer   = nullptr;
GuiRenderer      *GuiManager::guiRenderer      = nullptr;
GuiEventListener *GuiManager::guiEventListener = nullptr;

// Currently supports 255 objects at max

GuiManager::GuiManager() {
    guiFrameBuffer   = new GuiFrameBuffer();
    guiRenderer      = new GuiRenderer();
    guiEventListener = new GuiEventListener();
}

GuiManager *GuiManager::getInstance() {
    if (!guiManager) {
        guiManager = new GuiManager();
    }
    return guiManager;
}

int GuiManager::GetNextUid() {
    auto maxElement = std::max_element(guiWidgets.begin(), guiWidgets.end(),
                                       [](GuiWidget *a, GuiWidget *b) -> bool {
                                           return a->Uid() < b->Uid();
                                       });
    return maxElement[0]->Uid() + 1;
}

glm::vec3 GuiManager::CalculateNextCollisionColor() {
    int       nextUid   = GetNextUid();
    int       remainder = nextUid % 255;
    const int colors    = nextUid / 255;

    glm::vec3 nextCollisionColor = glm::vec3(0, 0, 0);

    if (colors == 0) {
        nextCollisionColor.r = remainder;
    } else if (colors == 1) {
        nextCollisionColor.r = 255;
        nextCollisionColor.g = remainder;
    } else if (colors == 2) {
        nextCollisionColor.r = 255;
        nextCollisionColor.g = 255;
        nextCollisionColor.b = remainder;
    }

    return nextCollisionColor;
}