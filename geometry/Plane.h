//
// Created by Joonas on 12/14/2016.
//

#ifndef OPENGL_PLANE_H
#define OPENGL_PLANE_H


#include <vector>
#include "../Model.h"

class Plane {

    GLuint VAO, VBO, EBO;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    int sizeX;
    int sizeZ;
    int distribution = 100;

    void GenerateIndices();

    void setupMesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

public:
    Plane();

    virtual void Draw();

    void GenerateVertices();

    void GenerateRivers();

    bool generateHeightMap = true;

    Plane(int sizeX, int sizeZ, int tileSize, bool generateHeightMap);
};


#endif //OPENGL_PLANE_H
