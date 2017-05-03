//
// Created by Joonas on 12/23/2016.
//

#ifndef OPENGL_WATER_H
#define OPENGL_WATER_H


#include "../geometry/Plane.h"


class Water: public Plane{

public:

    float oscillatingSpeed = 1.0f;

    float oscillatingMagnitude = 0.2f;

    Water(int sizeX, int sizeZ, int tileSize, bool generateHeightMap);

    void UpdateShader();

    void Draw() override;

};


#endif //OPENGL_WATER_H
