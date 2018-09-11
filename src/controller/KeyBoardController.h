//
// Created by jointts on 25.08.18.
//

#ifndef SUMMITENGINE_KEYBOARDCONTROLLER_H
#define SUMMITENGINE_KEYBOARDCONTROLLER_H

#include "../Event.h"
#include <GLFW/glfw3.h>
#include <map>
#include "BaseController.h"

class KeyBoardController : public BaseController {
    static void BindKeyState(int key);
    static void BindKeyEvent(int key, Event* event);
public:
    static std::map<int, Event *> keyMap;
    static void BindKey(int key, Event* event);
    static void ReceiveKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods);
};


#endif //SUMMITENGINE_KEYBOARDCONTROLLER_H
