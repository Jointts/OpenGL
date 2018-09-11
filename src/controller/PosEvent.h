//
// Created by jointts on 30.08.18.
//

#ifndef SUMMITENGINE_POSEVENT_H
#define SUMMITENGINE_POSEVENT_H


#include "../Event.h"
#include "../EventHandler.h"

class PosEvent : public Event{
    int xPos, yPos = 0;

    std::function<int, int()> eventAction;

    void Execute() {
        eventAction(xPos, yPos);
        EventHandler::NotifyListeners(this);
    }
};


#endif //SUMMITENGINE_POSEVENT_H
