//
// Created by jointts on 13.03.18.
//

#ifndef SUMMITENGINE_SLIDER_H
#define SUMMITENGINE_SLIDER_H

#include "GuiWidget.h"

class Slider : public GuiWidget {
public:
    std::function<void()> holdEvent;

    Slider(int width, int height);

    void Hold();
private:
    GuiWidget* bar;
    double   barValue = 0;
    float    barBoundaryMinX;
    float    barBoundaryMaxX;
};

#endif //SUMMITENGINE_SLIDER_H
