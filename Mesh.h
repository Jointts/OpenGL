//
// Created by Joonas on 10/20/2016.
//

#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H


#include <vec3.hpp>
#include <vec2.hpp>
#include <vector>
#include <glad/glad.h>
#include <assimp/types.h>
#include "string"
#include "Model.h"

class Mesh {

public:
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
    void setupMesh();
    void Draw();
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;
    GLuint VAO, VBO, EBO;
};


#endif //OPENGL_MESH_H
