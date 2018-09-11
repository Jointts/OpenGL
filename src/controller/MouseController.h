//
// Created by jointts on 9.03.18.
//

#ifndef SUMMIT_ENGINE_MOUSECONTROLLER_H
#define SUMMIT_ENGINE_MOUSECONTROLLER_H

#include <vector>
#include "BaseController.h"
#include "ControllerManager.h"
#include <GLFW/glfw3.h>

class MouseController : public BaseController {
public:
    static MouseController *getInstance();
private:
    friend class ControllerManager;
    static MouseController *mouseController;
    static void ReceivePosEvent(GLFWwindow *pWwindow, double xpos, double ypos);
    static void ReceiveKeyEvent(GLFWwindow *window, int button, int action, int mods);
    static void ReceiveScrollEvent(GLFWwindow *window, double xoffset, double yoffset);
};

#endif //SUMMIT_ENGINE_MOUSECONTROLLER_H
