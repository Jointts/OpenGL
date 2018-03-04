//
// Created by Joonas on 30/04/2017.
//

#include <GLFW/glfw3.h>
#include "Time.h"

const double PI = 3.141592653589793;
double Time::currentExecTime = 0;
double Time::lastExecTime = 0;
double Time::deltaTime = 0;
double Time::fps = 0;
double Time::fullWaterCycle = 2 * PI;
double Time::currentCycle = 0;

double Time::calculateFrameTime(){
    currentExecTime = glfwGetTime();
    deltaTime = currentExecTime - lastExecTime;
    lastExecTime = currentExecTime;
    fps = 1 / deltaTime;
    //printf("Time: %lf\n", deltaTime);
    //printf("FPS: %lf\n", fps);

    currentCycle += deltaTime;

    if(currentCycle > fullWaterCycle){
        currentCycle = 0;
    }

    return deltaTime;
}