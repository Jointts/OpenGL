//
// Created by jointts on 25.08.18.
//

#ifndef SUMMITENGINE_EVENTHANDLER_H
#define SUMMITENGINE_EVENTHANDLER_H


#include "Event.h"

class EventHandler {

public:
    static void NotifyListeners(Event* event);
};


#endif //SUMMITENGINE_EVENTHANDLER_H
