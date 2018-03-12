//
// Created by Joonas on 12/23/2016.
//

#ifndef SUMMIT_ENGINE_WATER_H
#define SUMMIT_ENGINE_WATER_H


#include "../geometry/Plane.h"


class Water : public Plane {

public:

    float oscillatingSpeed = 1.0f;

    float oscillatingMagnitude = 0.2f;

    Water(int sizeX, int sizeZ, int tileSize, bool generateHeightMap);

    void UpdateShader();

    void Draw() override;

};


#endif //SUMMIT_ENGINE_WATER_H
