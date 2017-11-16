//
// Created by Joonas on 11/7/2017.
//

#include "GuiEvents.h"
#include "../physics/PhysicsManager.h"
#include "GuiManager.h"

void GuiEvents::DEBUG_PHYSICS() {
    PhysicsManager::getInstance()->worldPhysics->debugDrawing = !PhysicsManager::getInstance()->worldPhysics->debugDrawing;
}

void GuiEvents::DEBUG_GUI() {
    GuiManager::getInstance()->guiRenderer->debugMode = !GuiManager::getInstance()->guiRenderer->debugMode;
}