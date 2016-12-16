//
// Created by Joonas on 10/27/2016.
//

#ifndef OPENGL_TERRAIN_H
#define OPENGL_TERRAIN_H


#include <vector>
#include <vec3.hpp>
#include "Model.h"

class Terrain {
    GLuint VAO, VBO, EBO;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
public:
    Terrain();

    void Draw();

    void setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);

    void generateUV(int vertexIndex, glm::vec2 uv_coord);
};


#endif //OPENGL_TERRAIN_H
