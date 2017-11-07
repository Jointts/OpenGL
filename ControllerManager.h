//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_CONTROLLERMANAGER_H
#define OPENGL_CONTROLLERMANAGER_H


#include <GLFW/glfw3.h>
#include "DisplayManager.h"
#include "camera/CameraManager.h"
#include "Entity.h"

class ControllerManager {
public:

    ControllerManager();

    static bool mouseOneClicked;

    static bool mouseOneReleased;

    static int EXIT_KEY;

    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    static void mouse_callback(GLFWwindow *window, double xpos, double ypos);
    static bool mouseOneClickEventPropagate;

    static ControllerManager *getInstance();

private:

    static ControllerManager *controllerManager;

    static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
};


#endif //OPENGL_CONTROLLERMANAGER_H
