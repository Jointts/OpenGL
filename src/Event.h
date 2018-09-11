//
// Created by jointts on 25.08.18.
//

#ifndef SUMMITENGINE_EVENT_H
#define SUMMITENGINE_EVENT_H

#include <vector>
#include <functional>
#include "EventType.h"
#include "EventHandler.h"

class Event {
protected:
    std::function<void()> eventAction;
public:
    Event() = delete;

    Event(const std::function<void()> eventAction) : eventAction(eventAction) {}

    virtual void Execute() {
        eventAction();
        EventHandler::NotifyListeners(this);
    };

    EventType eventType;
};


#endif //SUMMITENGINE_EVENT_H
