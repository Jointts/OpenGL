//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_DISPLAYMANAGER_H
#define OPENGL_DISPLAYMANAGER_H

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


#endif //OPENGL_DISPLAYMANAGER_H
