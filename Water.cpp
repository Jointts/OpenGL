//
// Created by Joonas on 12/14/2016.
//

#include <vec3.hpp>
#include <ext.hpp>
#include <stb_image.h>
#include "Water.h"
#include "ShaderProgram.h"
#include "Utils.h"

const int CHUNK_SIZE = 100;
const int MAX_HEIGHT = 128;
const int SEED = 123456;
const float ocean_level = -1.1f;

Water::Water() {
    float zOffset = 0.0f;
    for (int z = 0; z < CHUNK_SIZE; z ++) {
        float xOffset = 0.0f;
        for (int x = 0; x < CHUNK_SIZE; x ++) {
            float generated_noise = glm::simplex(glm::vec3(xOffset, 0.0f, zOffset));
            Vertex vertex;
            vertex.position = glm::vec3(x, -10.0f, z);
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

void Water::generateUV(int vertexIndex, glm::vec2 uv_coord){
    vertices[vertexIndex].uv_coord = uv_coord;
}

void Water::setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
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

void Water::Draw() {

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