//
// Created by Joonas on 06/10/2016.
//

#ifndef SUMMIT_ENGINE_DISPLAYMANAGER_H
#define SUMMIT_ENGINE_DISPLAYMANAGER_H

#include "Display.h"

class GLFWwindow;

class DisplayManager {
public:
    DisplayManager();

    static DisplayManager *getInstance();

    Display *display;
private:
    static DisplayManager *displayManager;
};


#endif //SUMMIT_ENGINE_DISPLAYMANAGER_H
