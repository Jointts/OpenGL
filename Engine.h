//
// Created by Joonas on 29/09/2016.
//

#ifndef OPENGL_ENGINE_H
#define OPENGL_ENGINE_H

#ifndef __gl_h_
#include <glad/glad.h>
#endif
#include "ShaderProgram.h"
#include "Display.h"
#include "ControllerManager.h"
#include "DisplayManager.h"
#include "camera/CameraManager.h"

class Engine {
public:
    int Start();
};


#endif //OPENGL_ENGINE_H
