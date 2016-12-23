//
// Created by Joonas on 10/27/2016.
//

#include <stb_perlin.h>
#include <iostream>
#include <ext.hpp>
#include <glad/glad.h>
#include <stb_image.h>
#include "Terrain.h"
#include "../Utils.h"
#include "../ShaderProgram.h"

const int CHUNK_SIZE = 100;
int MID_POINT;
int MID_POINT_2;
const int MAX_HEIGHT = 128;
const int SEED = 123456;
const float ocean_level = -1.1f;
glm::vec3 lastVector = glm::vec3();

Terrain::Terrain() {
    srand(time(NULL));
    MID_POINT = rand()%50 + 25;
    MID_POINT_2 = rand()%50 + 25;

    float zOffset = 0.0f;
    for (int z = 0; z < CHUNK_SIZE; z ++) {
        float xOffset = 0.0f;
        for (int x = 0; x < CHUNK_SIZE; x ++) {
            float dist1 = std::sqrt(std::pow(x - MID_POINT, 2) + std::pow(z - MID_POINT, 2));
            float dist2 = std::sqrt(std::pow(x - MID_POINT_2, 2) + std::pow(z - MID_POINT_2, 2));
            float total_distance = (dist1 + dist2) / 2;
            float generated_noise = glm::simplex(glm::vec3(xOffset, 0.0f, zOffset));
            float noise = (generated_noise * 3.0f - total_distance) / 3.0f;
            if (noise < -10.0f)noise= -11.0f;
            Vertex vertex;
            vertex.position = glm::vec3(x, noise, z);
            lastVector = glm::vec3(xOffset, 0, zOffset);
            vertices.push_back(vertex);
            xOffset += 0.2f;
        }
        zOffset += 0.2f;
    }

    for (int y = 0; y < CHUNK_SIZE - 1; y++) {
        for (int x = 0; x < CHUNK_SIZE - 1; x++) {
            int currentIndex = x + y * CHUNK_SIZE;
            // First triangle
            indices.push_back((GLuint) currentIndex);
            generateUV(currentIndex, glm::vec2(0.0f, 0.0f));
            indices.push_back((GLuint) (currentIndex + CHUNK_SIZE));
            generateUV(currentIndex, glm::vec2(0.0f, 1.0f));
            indices.push_back((GLuint) (currentIndex + CHUNK_SIZE + 1));
            generateUV(currentIndex, glm::vec2(1.0f, 1.0f));

            vertices[currentIndex].normal = Utils::GetNormal(vertices[currentIndex].position,
                                               vertices[currentIndex + CHUNK_SIZE].position,
                                               vertices[currentIndex + CHUNK_SIZE + 1].position);

            // Second triangle
            indices.push_back((GLuint) currentIndex);
            generateUV(currentIndex, glm::vec2(0.0f, 0.0f));
            indices.push_back((GLuint) (currentIndex + 1));
            generateUV(currentIndex, glm::vec2(1.0f, 0.0f));
            indices.push_back((GLuint) (currentIndex + CHUNK_SIZE + 1));
            generateUV(currentIndex, glm::vec2(1.0f, 1.0f));

            vertices[currentIndex + CHUNK_SIZE + 1].normal = Utils::GetNormal(vertices[currentIndex].position,
                                                                       vertices[currentIndex + CHUNK_SIZE].position,
                                                                       vertices[currentIndex + CHUNK_SIZE + 1].position);
        }
    }

    setupMesh(vertices, indices);
}

void Terrain::generateUV(int vertexIndex, glm::vec2 uv_coord){
    vertices[vertexIndex].uv_coord = uv_coord;
}

void Terrain::setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
    glUniform1i(glGetUniformLocation(ShaderProgram::getInstance()->shaderProgramID, "isTerrain"), 1);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, uv_coord));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) 0);
}

void Terrain::Draw() {
    GLuint texture;
    int width;
    int height;
    int bytesPerPixel;

    unsigned char *pixelData = stbi_load("res\\grass.jpg", &width, &height, &bytesPerPixel, STBI_rgb);
    GLfloat zPlane[] = { 0.0f, 0.0f, 1.0f, 0.0f };

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGenfv(GL_S, GL_OBJECT_PLANE, zPlane);
    glTexGenfv(GL_T, GL_OBJECT_PLANE, zPlane);

    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glUniform1f(glGetUniformLocation(ShaderProgram::getInstance()->shaderProgramID, "diffuse1"), 1);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(pixelData);

    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glDrawElements(GL_TRIANGLES, (GLsizei) indices.size(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

