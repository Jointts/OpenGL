//
// Created by Joonas on 30/04/2017.
//

#ifndef OPENGL_TIME_H
#define OPENGL_TIME_H


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


#endif //OPENGL_TIME_H
