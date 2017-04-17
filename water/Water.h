//
// Created by Joonas on 12/23/2016.
//

#ifndef OPENGL_WATER_H
#define OPENGL_WATER_H


#include "../geometry/Plane.h"

class Water: public Plane{

public:
    Water(int x, int y, int tileSize);
};


#endif //OPENGL_WATER_H
