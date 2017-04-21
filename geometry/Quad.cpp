//
// Created by Joonas on 12/04/2017.
//

#include <stb_image.h>
#include <BulletCollision/CollisionShapes/btTriangleMesh.h>
#include <BulletCollision/CollisionShapes/btConvexShape.h>
#include <BulletCollision/CollisionShapes/btConvexTriangleMeshShape.h>
#include <LinearMath/btDefaultMotionState.h>
#include "Quad.h"
#include "../Utils.h"
#include "../ShaderManager.h"
#include "../Entity.h"
#include "../physics/PhysicsManager.h"

Quad::Quad(int width, int height) {
    this->width = width;
    this->height = height;

    Vertex vertex1;
    vertex1.position = glm::vec3(0.0 + marginLeft, 0.0 + marginBottom, 0.0);
    vertex1.uv_coord = glm::vec2(0.0, 0.0);
    vertices.push_back(vertex1);

    Vertex vertex2;
    vertex2.position = glm::vec3(0.0 + marginLeft, this->height + marginBottom, 0.0);
    vertex2.uv_coord = glm::vec2(0.0, 1.0);
    vertices.push_back(vertex2);

    Vertex vertex3;
    vertex3.position = glm::vec3(this->width + marginLeft, this->height + marginBottom, 0.0);
    vertex3.uv_coord = glm::vec2(1.0, 1.0);
    vertices.push_back(vertex3);

    Vertex vertex4;
    vertex4.position = glm::vec3(this->width + marginLeft, 0.0 + marginBottom, 0.0);
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

    textureId = Utils::TextureFromFile("res/nice_circle.png", true);
}

void Quad::UpdatePosition(){
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
}

float Quad::getMarginLeft() const {
    return marginLeft;
}

void Quad::setMarginLeft(float marginLeft) {
    this->marginLeft = marginLeft;
    vertices[0].position.x = marginLeft;
    vertices[1].position.x = marginLeft;
    vertices[2].position.x = width + marginLeft;
    vertices[3].position.x = width + marginLeft;
    UpdatePosition();
}

float Quad::getMarginRight() const {
    return marginRight;
}

void Quad::setMarginRight(float marginRight) {
    float displayWidth = 1440.0f;
    this->marginRight = marginRight;
    vertices[0].position.x = displayWidth - marginRight;
    vertices[1].position.x = displayWidth - marginRight;
    vertices[2].position.x = displayWidth - (width + marginRight);
    vertices[3].position.x = displayWidth - (width + marginRight);
    UpdatePosition();
}

float Quad::getMarginTop() const {
    return marginTop;
}

void Quad::setMarginTop(float marginTop) {
    float displayHeight = 900.0f;
    this->marginTop = marginTop;
    vertices[0].position.y = displayHeight - marginTop;
    vertices[1].position.y = displayHeight - (height + marginTop);
    vertices[2].position.y = displayHeight - (height + marginTop);
    vertices[3].position.y = displayHeight - marginTop;
    UpdatePosition();
}

float Quad::getMarginBottom() const {
    return marginBottom;
}

void Quad::setMarginBottom(float marginBottom) {
    this->marginBottom = marginBottom;
    vertices[0].position.y = marginBottom;
    vertices[1].position.y = height + marginBottom;
    vertices[2].position.y = height + marginBottom;
    vertices[3].position.y = marginBottom;
    UpdatePosition();
}

void Quad::ChangeTexture(GLchar* path){
    textureId = Utils::TextureFromFile(path, true);
}

void Quad::GenerateCollision(){
    btTriangleMesh* trimesh = new btTriangleMesh();

    for (int i = 0; i * 3 < indices.size(); i++)
    {
        int index0 = indices[i * 3];
        int index1 = indices[i * 3 + 1];
        int index2 = indices[i * 3 + 2];

        btVector3 vertex0(vertices[index0].position.x, vertices[index0].position.y, vertices[index0].position.z);
        btVector3 vertex1(vertices[index1].position.x, vertices[index1].position.y, vertices[index1].position.z);
        btVector3 vertex2(vertices[index2].position.x, vertices[index2].position.y, vertices[index2].position.z);

        trimesh->addTriangle(vertex0, vertex1, vertex2);
    }

    btConvexShape *convexShape = new btConvexTriangleMeshShape(trimesh);

    btDefaultMotionState* motionstate = new btDefaultMotionState(btTransform(
            btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)
    ));

    btScalar mass = 1;

    btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
            0,               // mass, in kg. 0 -> Static object, will never move.
            motionstate,
            convexShape,        // collision shape of body
            btVector3(0,0,0)    // local inertia
    );

    rigidBody = new btRigidBody(rigidBodyCI);

    PhysicsManager::getInstance()->dynamicsWorld->addRigidBody(rigidBody);

}


void Quad::Draw() {
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(2);
    glActiveTexture(GL_TEXTURE0);
    glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->guiShader->shaderProgramID, "diffuse"), textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glDrawElements(GL_TRIANGLES, (GLsizei) indices.size(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}
