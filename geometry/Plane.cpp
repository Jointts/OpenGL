//
// Created by Joonas on 12/14/2016.
//

#include <vec3.hpp>
#include <ext.hpp>
#include "Plane.h"
#include <noise/noise.h>
#include <iostream>

using namespace noise;

Plane::Plane(int sizeX, int sizeZ, int tileSize, bool generateHeightMap)
: generateHeightMap(generateHeightMap)
{
    this->sizeX = sizeX;
    this->sizeZ = sizeZ;
    GenerateVertices();
    GenerateIndices();
    setupMesh(vertices, indices);
}

void Plane::GenerateVertices() {
    module::Perlin myModule;
    myModule.SetOctaveCount (10);
    myModule.SetPersistence(0.5);
    double y = 0.0;
    for (int z = 0; z < sizeZ + 1; z++) {
        for (int x = 0; x < sizeX + 1; x++) {
            Vertex vertex1;
            if(generateHeightMap){
                y = myModule.GetValue((double) x / distribution, 0.5, (double) z / distribution);
                heightCoords.push_back((float &&) (float)y);
            }
            std::cout << y << std::endl;
            vertex1.position = glm::vec3(x, (float) y * 10, z);
            vertices.push_back(vertex1);
        }
    }
}
void Plane::GenerateIndices() {
    for (int z = 0; z < sizeZ; ++z) {
        for (int x = 0; x < sizeX; x++) {
            GLuint currentIndex = (GLuint) (x + z * sizeX + z);
            GLuint nextRow = (GLuint) (sizeX + 1);

            indices.push_back(currentIndex + 1);
            indices.push_back(currentIndex);
            indices.push_back(nextRow + currentIndex);

            indices.push_back(currentIndex + 1);
            indices.push_back(nextRow + currentIndex);
            indices.push_back(nextRow + currentIndex + 1);
        }
    }
}

void Plane::GenerateNormals() {
    for (int z = 0; z < sizeZ; ++z) {
        for (int x = 0; x < sizeX; x += 2) {
            GLuint currentIndex = (GLuint) (x + z * sizeX + z);
            GLuint nextRow = (GLuint) (sizeX + 1);

            glm::vec3 v1 = vertices[currentIndex + 1].position;
            glm::vec3 v2 = vertices[currentIndex].position;
            glm::vec3 v3 = vertices[nextRow + currentIndex].position;


            vertices[currentIndex + 1].normal;
            vertices[nextRow + currentIndex].normal;
            vertices[nextRow + currentIndex + 1].normal;
        }
    }
}

void Plane::setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) 0);
}

void Plane::UpdateMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices){
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) 0);
}

void Plane::Draw() {
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, (GLsizei) indices.size(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

Plane::Plane() {

}
