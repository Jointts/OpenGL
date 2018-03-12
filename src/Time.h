//
// Created by Joonas on 30/04/2017.
//

#ifndef SUMMIT_ENGINE_TIME_H
#define SUMMIT_ENGINE_TIME_H


class Time {
    static double currentExecTime;
    static double lastExecTime;
    static double deltaTime;
    static double fps;
    static double fullWaterCycle;

public:
    static double calculateFrameTime();

    static double currentCycle;
};


#endif //SUMMIT_ENGINE_TIME_H
