//
// Created by Joonas on 01/09/2017.
//

#include <LinearMath/btDefaultMotionState.h>
#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>
#include "DuplicatedVertexPlane.h"
#include "RenderManager.h"
#include "Utils.h"
#include "ShaderManager.h"
#include "physics/PhysicsManager.h"

DuplicatedVertexPlane::DuplicatedVertexPlane(int sizeX, int sizeY, bool hasCollision) {
    this->sizeX = sizeX;
    this->sizeZ = sizeY;
    this->hasCollision = hasCollision;
    generateVertices();
    setupMesh(vertices);
    generateCollision();
}

DuplicatedVertexPlane::DuplicatedVertexPlane(int sizeX, int sizeY, const char *imagePath, bool hasCollision) {
    DuplicatedVertexPlane(sizeX, sizeY, hasCollision);
    setImage(imagePath);
}

void DuplicatedVertexPlane::setImage(const char *imagePath) {
    Texture texture;
    texture.id = Utils::TextureFromFile(imagePath, false);
    texture.type = "diffuse";
    textures.push_back(texture);
}

//  00 10 -> 1 polygon -> 00:10:01 2 polygon -> 01:10:11
//  01 11

void DuplicatedVertexPlane::generateVertices() {
    for (int x = 0; x < sizeX; ++x) {
        for (int y = 0; y < sizeZ; ++y) {
            Vertex vertex;
            vertex.position.x = x;
            vertex.position.z = y;
            vertex.uv_coord.x = 0;
            vertex.uv_coord.y = 0;
            vertex.normal = glm::vec3(0.f, 1.f, 0.f);
            vertices.push_back(vertex);
            vertex.position.x = x + 1;
            vertex.position.z = y;
            vertex.uv_coord.x = 1;
            vertex.uv_coord.y = 0;
            vertex.normal = glm::vec3(0.f, 1.f, 0.f);
            vertices.push_back(vertex);
            vertex.position.x = x;
            vertex.position.z = y + 1;
            vertex.uv_coord.x = 0;
            vertex.uv_coord.y = 1;
            vertex.normal = glm::vec3(0.f, 1.f, 0.f);
            vertices.push_back(vertex);
            vertex.position.x = x;
            vertex.position.z = y + 1;
            vertex.uv_coord.x = 0;
            vertex.uv_coord.y = 1;
            vertex.normal = glm::vec3(0.f, 1.f, 0.f);
            vertices.push_back(vertex);
            vertex.position.x = x + 1;
            vertex.position.z = y;
            vertex.uv_coord.x = 1;
            vertex.uv_coord.y = 0;
            vertex.normal = glm::vec3(0.f, 1.f, 0.f);
            vertices.push_back(vertex);
            vertex.position.x = x + 1;
            vertex.position.z = y + 1;
            vertex.uv_coord.x = 1;
            vertex.uv_coord.y = 1;
            vertex.normal = glm::vec3(0.f, 1.f, 0.f);
            vertices.push_back(vertex);
            heightCoords.push_back(0.f);
            heightCoords.push_back(0.f);
            heightCoords.push_back(0.f);
            heightCoords.push_back(0.f);
        }
    }
}

void DuplicatedVertexPlane::setupMesh(std::vector<Vertex> vertices) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) 0);

    // Vertex UV coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) offsetof(Vertex, uv_coord));
}

void DuplicatedVertexPlane::Draw() {
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
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei) vertices.size());
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void DuplicatedVertexPlane::generateCollision() {
    if (hasCollision) {
        int width = sizeX + 1;
        int height = sizeZ + 1;

        btCollisionShape *heightfieldShape =
                new btHeightfieldTerrainShape(width, height, heightCoords.data(), btScalar(1),
                                              btScalar(0.f), btScalar(0.f), 1, PHY_FLOAT, false);
        btAssert(heightfieldShape && "null heightfield");

        //  Correct the offset from bullet (originally centers the entire collision object to 0 coord)
        btTransform startTransform;
        startTransform.setIdentity();
        startTransform.setOrigin(btVector3(width / 2 - 0.5f, 0, height / 2 - 0.5f));


        btDefaultMotionState *motionstate = new btDefaultMotionState(startTransform);

        btScalar mass = 0;

        btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
                mass,               // mass, in kg. 0 -> Static object, will never move.
                motionstate,
                heightfieldShape,        // collision shape of body
                btVector3(0, 0, 0)    // local inertia
        );


        rigidBody = new btRigidBody(rigidBodyCI);
        PhysicsManager::getInstance()->worldPhysics->dynamicsWorld->addRigidBody(rigidBody);
    }
}

