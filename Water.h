//
// Created by Joonas on 12/14/2016.
//

#ifndef OPENGL_WATER_H
#define OPENGL_WATER_H


#include <vector>
#include "Model.h"

class Water {
    GLuint VAO, VBO, EBO;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    void generateUV(int vertexIndex, glm::vec2 uv_coord);

    void setupMesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

public:
    Water();

    void Draw();
};


#endif //OPENGL_WATER_H
