//
// Created by jointts on 13.03.18.
//

#include "Slider.h"
#include "../controller/MouseController.h"

Slider::Slider(int width, int height) : GuiWidget(width, height) {
    bar             = new GuiWidget(5, static_cast<int>(this->height + 10));
    barBoundaryMinX = vertices[0].position.x;
    barBoundaryMaxX = vertices[4].position.x;
}

void Slider::Hold() {
    double mouseX = MouseController::getInstance()->mouseX;

    if (mouseX < barBoundaryMaxX && mouseX > barBoundaryMinX) {
        barValue = (mouseX - barBoundaryMinX) / (barBoundaryMaxX - barBoundaryMinX);
        bar->setMarginLeft(static_cast<float>(mouseX));
    }
}
