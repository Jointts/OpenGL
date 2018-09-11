//
// Created by jointts on 26.08.18.
//

#ifndef SUMMITENGINE_BASECONTROLLER_H
#define SUMMITENGINE_BASECONTROLLER_H


#include <map>
#include "KeyState.h"


class BaseController {
public:
    static std::map<int, KeyState> buttonStates;
    static void insertKey(int button);
    static void updateButtonState(int button, int action);
    void resetClickedStates();
    static bool checkButtonInput(int key, KeyState event);
};


#endif //SUMMITENGINE_BASECONTROLLER_H
