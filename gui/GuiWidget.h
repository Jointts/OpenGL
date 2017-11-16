//
// Created by Joonas on 01/05/2017.
//

#ifndef OPENGL_GUIWIDGET_H
#define OPENGL_GUIWIDGET_H


#include "../geometry/Quad.h"
#include "GuiFrameBuffer.h"
#include <functional>

class GuiWidget : public Quad {
public:
    GuiWidget(int width, int height);

    void setMarginBottom(float marginBottom);

    void setTexture(GLchar *path);

    float getMarginBottom() const;

    void setMarginTop(float marginTop);

    float getMarginTop() const;

    void setMarginRight(float marginRight);

    float getMarginRight() const;

    void setMarginLeft(float marginLeft);

    float getMarginLeft() const;

    void UpdatePosition();

    void Draw();

    void DrawCollision();

    virtual void Click();

    glm::vec3 collisionColor = glm::vec3();
//
//    void BindClickEvent(std::function clickEvent);
private:
//    std::function clickEvent;
    float marginLeft = 0;
    float marginRight = 0;

    float marginTop = 0;

    float marginBottom = 0;

    GuiFrameBuffer *guiFrameBuffer;
};


#endif //OPENGL_GUIWIDGET_H
