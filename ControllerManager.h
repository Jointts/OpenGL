//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_CONTROLLERMANAGER_H
#define OPENGL_CONTROLLERMANAGER_H


#include <GLFW/glfw3.h>
#include "DisplayManager.h"
#include "CameraManager.h"

class ControllerManager {
public:
    ControllerManager();

    static int EXIT_KEY;

    void startUp();
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void mouse_callback(GLFWwindow *window, double xpos, double ypos);
    static ControllerManager *getInstance();

private:
    static ControllerManager *controllerManager;

};


#endif //OPENGL_CONTROLLERMANAGER_H
