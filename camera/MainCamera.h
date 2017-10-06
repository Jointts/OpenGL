//
// Created by Joonas on 12/04/2017.
//

#ifndef OPENGL_MAINCAMERA_H
#define OPENGL_MAINCAMERA_H


#ifndef __gl_h_
#include <glad/glad.h>
#endif
#include "Camera.h"


class MainCamera : public Camera {
public:
    float startingSpeed = 0.1f;

    float accelerationSpeed = 0.2f;

    float maxSpeed = 2.0f;

    float currentSpeed = 0.0f;

    MainCamera();

    void MoveLeft();

    void MoveRight();

    void MoveForward();

    void MoveBack();

    void UpdateCamera();

    void MoveUp();

    void MoveDown();
};


#endif //OPENGL_MAINCAMERA_H
