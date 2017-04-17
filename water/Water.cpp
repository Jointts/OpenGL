//
// Created by Joonas on 12/23/2016.
//

#include "Water.h"

Plane plane;

Water::Water(int x, int y, int tileSize){
    plane = Water::Plane(x, y, tileSize, false);
}

