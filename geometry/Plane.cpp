//
// Created by Joonas on 12/14/2016.
//

#include <glm/vec3.hpp>
#include <glm/ext.hpp>
#include "Plane.h"
#include "../shaders/ShaderManager.h"
#include "../Utils.h"
#include "../renderer/RenderManager.h"
#include <noise/noise.h>
#include <iostream>
#include <random>

using namespace noise;

Plane::Plane(int sizeX, int sizeZ, int tileSize, bool generateHeightMap)
        : generateHeightMap(generateHeightMap) {
    this->sizeX = sizeX;
    this->sizeZ = sizeZ;
    GenerateVertices();
    GenerateIndices();
    GenerateNormals();
    setupMesh(vertices, indices);
}

void Plane::AddTexture(const char *texturePath) {
    Texture texture;
    texture.id = Utils::TextureFromFile(texturePath, false);
    texture.type = "diffuse";
    textures.push_back(texture);
}

void Plane::GenerateVertices() {
    std::default_random_engine eng((std::random_device()) ());

    module::Perlin myModule;
    myModule.SetOctaveCount(10);
    myModule.SetPersistence(0.5);
    double y = 0.0;
    for (int z = 0; z < sizeZ + 1; z++) {
        for (int x = 0; x < sizeX + 1; x++) {
            Vertex vertex1;
            y = 0;
            if (generateHeightMap) {
                y = myModule.GetValue((double) x / distribution, 0.5, (double) z / distribution);
            }

            std::uniform_real_distribution<float> red_random_factor(0, 100.0);

            float red = 150 + red_random_factor(eng);

            heightCoords.push_back((float &&) (float) y);
            std::cout << y << std::endl;
            vertex1.position = glm::vec3(x, (float) y * 10, z);
            vertex1.color = Utils::color_RGB(red, 255, 0);

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

void Plane::GenerateUVCoords(int currentIndex, int nextRow) {
    vertices[currentIndex].uv_coord = glm::vec2(0.0f, 1.0f);
    vertices[currentIndex + 1].uv_coord = glm::vec2(1.0f, 1.0f);
    vertices[nextRow + currentIndex].uv_coord = glm::vec2(0.0f, 0.0f);
    vertices[nextRow + currentIndex + 1].uv_coord = glm::vec2(1.0f, 0.0f);
}

void Plane::GenerateNormals() {
    for (int z = 0; z < sizeZ; ++z) {
        for (int x = 0; x < sizeX; x++) {
            GLuint currentIndex = (GLuint) (x + z * sizeX + z);
            GLuint nextRow = (GLuint) (sizeX + 1);

            glm::vec3 v1 = vertices[currentIndex + 1].position;
            glm::vec3 v2 = vertices[currentIndex].position;
            glm::vec3 v3 = vertices[nextRow + currentIndex].position;
            glm::vec3 v4 = vertices[nextRow + currentIndex + 1].position;

            glm::vec3 edge1 = v2 - v1;
            glm::vec3 edge2 = v3 - v1;
            glm::vec3 edge3 = v3 - v2;
            glm::vec3 edge4 = v4 - v2;

            vertices[currentIndex + 1].normal = glm::cross(edge3, edge4);;
            vertices[nextRow + currentIndex].normal = glm::cross(edge3, edge4);;
            vertices[nextRow + currentIndex + 1].normal = glm::cross(edge3, edge4);;


            vertices[currentIndex].normal = glm::cross(edge1, edge2);
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

    // Vertex Normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) offsetof(Vertex, normal));

    // Vertex Color
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) offsetof(Vertex, color));
}

void Plane::UpdateMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) 0);

    // Vertex Color
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) offsetof(Vertex, color));
}

void Plane::Draw() {
    RenderManager::getInstance()->RenderBaseShader();

    int diffuseNr = 0;
    for (GLuint i = 0; i < this->textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit before binding
        // Retrieve texture number (the N in diffuse_textureN)
        std::string name = this->textures[i].type;
        if (name == "diffuse")
            diffuseNr++;
        const char *shader_attribute = std::string("diffuse1").c_str();
        int uniformLocation = (int) glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID,
                                                         shader_attribute);
        glUniform1f(uniformLocation, i);
        glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(3);
    glDrawElements(GL_TRIANGLES, (GLsizei) indices.size(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(3);
    glBindVertexArray(0);
}

Plane::Plane() {

}
