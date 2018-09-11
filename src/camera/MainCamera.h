//
// Created by Joonas on 12/04/2017.
//

#ifndef SUMMIT_ENGINE_MAINCAMERA_H
#define SUMMIT_ENGINE_MAINCAMERA_H


#ifndef __gl_h_

#include <glad/glad.h>

#endif

#include "Camera.h"


class MainCamera : public Camera {
public:
    MainCamera();
    void MoveByX(int x);
    void MoveByY(int y);
    void MoveByZ(int z);
    void UpdateCamera();
};


#endif //SUMMIT_ENGINE_MAINCAMERA_H
