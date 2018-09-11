//
// Created by jointts on 25.08.18.
//

#include "KeyBoardController.h"
#include "../EventHandler.h"

std::map<int, Event *> KeyBoardController::keyMap = {};

void KeyBoardController::BindKey(int key, Event *event) {
    BindKeyState(key);
    BindKeyEvent(key, event);
}

void KeyBoardController::BindKeyEvent(int key, Event *event) {
    event->eventType = EventType::KEYBOARD;
    keyMap.insert(std::pair<int, Event *>(key, event));
}

void KeyBoardController::BindKeyState(int key) {
    insertKey(key);
}

void KeyBoardController::ReceiveKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (checkButtonInput(key, KeyState::CLICKED)) {
        Event *event = keyMap.at(key);
        event->Execute();
    }
}