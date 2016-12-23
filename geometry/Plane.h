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

    void GenerateIndices();

    void setupMesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

public:
    Plane();

    Plane(int sizeX, int sizeY, int tileSize);

    void Draw();

    void GenerateVertices();
};


#endif //OPENGL_PLANE_H
