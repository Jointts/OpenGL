//
// Created by Joonas on 12/14/2016.
//

#include <vec3.hpp>
#include <ext.hpp>
#include <stb_image.h>
#include "Plane.h"

Plane::Plane(int sizeX, int sizeZ, int tileSize) {
    this->sizeX = sizeX;
    this->sizeZ = sizeZ;
    GenerateVertices();
    GenerateIndices();
    setupMesh(vertices, indices);
}

void Plane::GenerateVertices() {
    for (int z = 0; z < sizeZ + 1; z++) {
        for (int x = 0; x < sizeX + 1; x++) {
            Vertex vertex1;
            vertex1.position = glm::vec3(x, 0.0f, z);
            vertices.push_back(vertex1);
        }
    }
}

void Plane::GenerateIndices() {
    for (int z = 0; z < sizeZ; z++) {
        for (int x = 0; x < sizeX; x++) {
            int currentIndex = sizeZ * z + x;
            int nextRowIndex = sizeZ * (z + 1) + x + 1;
            if(z > 0){
                nextRowIndex += 1;
                currentIndex += 1;
            }
            indices.push_back((const unsigned int &) currentIndex);
            indices.push_back((const unsigned int &) (currentIndex + 1));
            indices.push_back((const unsigned int &) (nextRowIndex));
            indices.push_back((const unsigned int &) (nextRowIndex));
            indices.push_back((const unsigned int &) (currentIndex + 1));
            indices.push_back((unsigned int &&) (nextRowIndex + 1));
        }
    }

//    indices.push_back(2);
//    indices.push_back((unsigned int &&) (nextRow + 2));
//    indices.push_back(3);
//    indices.push_back(3);
//    indices.push_back((unsigned int &&) (nextRow + 2));
//    indices.push_back((unsigned int &&) (nextRow + 3));
//
//    indices.push_back(4);
//    indices.push_back((unsigned int &&) (nextRow + 4));
//    indices.push_back(5);
//    indices.push_back(5);
//    indices.push_back((unsigned int &&) (nextRow + 4));
//    indices.push_back((unsigned int &&) (nextRow + 5));


}

void Plane::setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, uv_coord));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) 0);
}

void Plane::Draw() {
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glDrawElements(GL_TRIANGLES, (GLsizei) indices.size(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}

Plane::Plane() {

}
