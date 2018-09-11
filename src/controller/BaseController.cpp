//
// Created by jointts on 26.08.18.
//

#include <algorithm>
#include <GLFW/glfw3.h>
#include "MouseController.h"
#include "BaseController.h"
#include "../display/DisplayManager.h"

std::map<int, KeyState> BaseController::buttonStates = {};

void BaseController::insertKey(int button) {
    if (!(buttonStates.find(button) != buttonStates.end())) {
        buttonStates.insert(std::pair<const int, KeyState>(button, CLICK));
    }
}

void BaseController::updateButtonState(int button, int action) {
    KeyState *currentState = &buttonStates.at(button);
    auto       stateValue    = static_cast<int>(*currentState);

    if (stateValue == RELEASED && action == GLFW_PRESS) {
        *currentState = CLICK;
    }
    if (stateValue == HOLD && action == GLFW_RELEASE) {
        *currentState = CLICKED;
    }
    if (stateValue == CLICK && action == GLFW_PRESS) {
        *currentState = HOLD;
    }
}

void BaseController::resetClickedStates() {
    std::for_each(buttonStates.begin(), buttonStates.end(), [](std::pair<const int, KeyState> &button) {
        if (button.second == CLICKED) {
            button.second = RELEASED;
        }
    });
}

bool BaseController::checkButtonInput(int key, KeyState event) {
    bool inputMatches = false;
    std::for_each(buttonStates.begin(), buttonStates.end(),
                  [key, event, &inputMatches](std::pair<const int, KeyState> &button) {
                      int action = glfwGetMouseButton(DisplayManager::getInstance()->display->window, key);
                      updateButtonState(button.first, action);
                      if (button.first == key && button.second == event) {
                          inputMatches = true;
                      }
                  });

    return inputMatches;
}