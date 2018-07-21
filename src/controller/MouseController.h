//
// Created by jointts on 9.03.18.
//

#ifndef SUMMIT_ENGINE_MOUSECONTROLLER_H
#define SUMMIT_ENGINE_MOUSECONTROLLER_H

#include <vector>
#include <map>
#include "MouseEvent.h"

class MouseController {
public:
    double mouseX = 0;
    double mouseY = 0;

    // TODO: MouseController should not implement the singleton pattern, should be obtained from ControllerManager instead

    static MouseController *getInstance();
    bool checkButtonInput(int key, MouseEvent event);
    void resetClickedStates();
    void updateButtonState(int button, int action);
    void insertKey(int button);
private:
    std::map<int, MouseEvent> buttonStates = {};

    static MouseController *mouseController;
};

#endif //SUMMIT_ENGINE_MOUSECONTROLLER_H
