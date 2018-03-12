//
// Created by Joonas on 29/09/2016.
//

#ifndef SUMMIT_ENGINE_ENGINE_H
#define SUMMIT_ENGINE_ENGINE_H

#ifndef __gl_h_
#include <glad/glad.h>
#endif
#include "shaders/ShaderProgram.h"
#include "display/Display.h"
#include "controller/ControllerManager.h"
#include "display/DisplayManager.h"
#include "camera/CameraManager.h"

class Engine {
public:
    int Start();
};


#endif //SUMMIT_ENGINE_ENGINE_H
