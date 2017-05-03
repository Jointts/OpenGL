//
// Created by Joonas on 12/04/2017.
//

#include <stb_image.h>
#include <BulletCollision/CollisionShapes/btTriangleMesh.h>
#include <BulletCollision/CollisionShapes/btConvexShape.h>
#include <BulletCollision/CollisionShapes/btConvexTriangleMeshShape.h>
#include <LinearMath/btDefaultMotionState.h>
#include <BulletCollision/CollisionShapes/btSphereShape.h>
#include "Quad.h"
#include "../Utils.h"
#include "../ShaderManager.h"
#include "../Entity.h"
#include "../physics/PhysicsManager.h"

Quad::Quad(int width, int height) {
    this->width = width;
    this->height = height;

    Vertex vertex1;
    vertex1.position = glm::vec3(0.0, 0.0, 0.0);
    vertex1.uv_coord = glm::vec2(0.0, 0.0);
    vertices.push_back(vertex1);

    Vertex vertex2;
    vertex2.position = glm::vec3(0.0, this->height, 0.0);
    vertex2.uv_coord = glm::vec2(0.0, 1.0);
    vertices.push_back(vertex2);

    Vertex vertex3;
    vertex3.position = glm::vec3(this->width, this->height, 0.0);
    vertex3.uv_coord = glm::vec2(1.0, 1.0);
    vertices.push_back(vertex3);

    Vertex vertex4;
    vertex4.position = glm::vec3(this->width, 0.0, 0.0);
    vertex4.uv_coord = glm::vec2(1.0, 0.0);
    vertices.push_back(vertex4);

    indices = {0, 1, 2, 2, 3, 0};

    setupMesh(vertices, indices);
}

void Quad::setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
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

    // Vertex UV coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, uv_coord));

}

void Quad::Draw() {
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(2);
    if(textureId){
        glActiveTexture(GL_TEXTURE0);
        glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->guiShader->shaderProgramID, "diffuse"), textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }
    glDrawElements(GL_TRIANGLES, (GLsizei) indices.size(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}
