//
// Created by jointts on 9.03.18.
//

#include <GLFW/glfw3.h>
#include <algorithm>
#include <iostream>
#include "MouseController.h"
#include "../display/DisplayManager.h"

MouseController *MouseController::mouseController = 0;

MouseController *MouseController::getInstance() {
    if (!mouseController) {
        mouseController = new MouseController();
    }
    return mouseController;
}

void MouseController::insertKey(int button){
    if(!(buttonStates.find(button) != buttonStates.end())) {
        buttonStates.insert(std::pair<const int, MouseEvent>(button, MouseEvent::CLICK));
    }
}

void MouseController::updateButtonState(int button, int action) {
    MouseEvent *currentState = &buttonStates.at(button);
    int stateValue = static_cast<int>(*currentState);

    if(stateValue == MouseEvent::RELEASED && action == GLFW_PRESS){
        *currentState = MouseEvent::CLICK;
    }
    if(stateValue == MouseEvent::HOLD && action == GLFW_RELEASE){
        *currentState = MouseEvent::CLICKED;
    }
    if(stateValue == MouseEvent::CLICK && action == GLFW_PRESS){
        *currentState = MouseEvent::HOLD;
    }
}

void MouseController::resetClickedStates() {
    std::for_each(buttonStates.begin(), buttonStates.end(), [](std::pair<const int, MouseEvent> &button){
        if(button.second == MouseEvent::CLICKED){
            button.second = MouseEvent::RELEASED;
        }
    });
}

bool MouseController::checkButtonInput(int key, MouseEvent event) {
    bool inputMatches = false;
    std::for_each(buttonStates.begin(), buttonStates.end(), [key, event, &inputMatches, this](std::pair<const int, MouseEvent> &button){
        int action = glfwGetMouseButton(DisplayManager::getInstance()->display->window, key);
        updateButtonState(button.first, action);
        if(button.first == key && button.second == event){
            inputMatches = true;
        }
    });

    return inputMatches;
}
