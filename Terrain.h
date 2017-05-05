//
// Created by Joonas on 21/04/2017.
//

#ifndef OPENGL_TERRAIN_H
#define OPENGL_TERRAIN_H


#include <map>
#include "geometry/Plane.h"

class Terrain : public Plane{
public:
    btRigidBody *rigidBody;

    Terrain(int sizeX, int sizeZ, int tileSize, bool generateHeightMap);

    void generateCollision();

    std::vector<int> ChooseRiverStartIndices(std::vector<int> vector);

    std::vector<int> GetPossibleRiverStartIndices();

    void GenerateRivers();

    std::map<int,int> traversedVertices;

    void CarvePath(int index);
};


#endif //OPENGL_TERRAIN_H
