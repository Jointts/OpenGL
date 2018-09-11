//
// Created by Joonas on 01/05/2017.
//

#ifndef SUMMIT_ENGINE_GUIWIDGET_H
#define SUMMIT_ENGINE_GUIWIDGET_H

#include "../geometry/Quad.h"
#include "GuiFrameBuffer.h"
#include <functional>
#include <fstream>
//#include <cereal/archives/json.hpp>


class GuiWidget : public Quad {
public:
    bool      focused        = false;
    glm::vec3 collisionColor = glm::vec3();

    GuiWidget(int width, int height);

    void setMarginBottom(float marginBottom);
    void setTexture(GLchar* path);
    float getMarginBottom() const;
    void setMarginTop(float marginTop);
    float getMarginTop() const;
    void setMarginRight(float marginRight);
    float getMarginRight() const;
    void setMarginLeft(float marginLeft);
    float getMarginLeft() const;
    void UpdateVertexData();
    void Draw();
    void DrawCollision();
    virtual void Click();
    virtual void Hold();
    const int Uid() const;
private:
    //    std::function clickEvent;
    GuiWidget* parent;
    float marginLeft   = 0;
    float marginRight  = 0;
    float marginTop    = 0;
    float marginBottom = 0;

    GuiFrameBuffer* guiFrameBuffer;
    void SetCollisionColor(glm::vec3 collisionColor);
};

#endif //SUMMIT_ENGINE_GUIWIDGET_H
