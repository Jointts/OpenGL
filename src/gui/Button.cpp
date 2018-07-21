//
// Created by Joonas on 11/7/2017.
//

#include "Button.h"

Button::Button(int width, int height) : GuiWidget(width, height) {
}

void Button::Click() {
    if (clickEvent == nullptr) {
        GuiWidget::Click();
    } else {
        clickEvent();
    }
}
