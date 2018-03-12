//
// Created by Joonas on 10/20/2016.
//

#ifndef SUMMIT_ENGINE_MESH_H
#define SUMMIT_ENGINE_MESH_H


#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
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


#endif //SUMMIT_ENGINE_MESH_H
