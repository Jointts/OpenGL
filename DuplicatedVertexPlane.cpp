//
// Created by Joonas on 01/09/2017.
//

#include <LinearMath/btDefaultMotionState.h>
#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>
#include <random>
#include "DuplicatedVertexPlane.h"
#include "RenderManager.h"
#include "Utils.h"
#include "ShaderManager.h"
#include "physics/PhysicsManager.h"
#include <noise/noise.h>
#include <BulletCollision/CollisionShapes/btBvhTriangleMeshShape.h>
#include <BulletCollision/CollisionShapes/btTriangleMesh.h>

using namespace noise;

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
    std::default_random_engine eng((std::random_device())());
    tMesh = new btTriangleMesh();

    for (int x = 0; x < sizeX; ++x) {
        for (int z = 0; z < sizeZ; ++z) {
            std::uniform_real_distribution<float> red_random_factor(0, 100.0);
            std::uniform_real_distribution<float> red_random_factor2(0, 100.0);
            int vertex_previous;

            int row = x * z;
            int index = z;
            int previousVerticesStartIndex = row + index - 6;

            module::Perlin myModule;
            myModule.SetOctaveCount (10);
            myModule.SetPersistence(0.5);
            int distribution = 50;

            //Color for the first polygon
            float red = 150 + red_random_factor(eng);
            //Color for the second polygon
            float red2 = 150 + red_random_factor2(eng);

            // Heights for the 4 (6) vertices
            double y1 = myModule.GetValue((double) x / distribution, 1, (double) z / distribution);
            double y2 = myModule.GetValue((double) (x + 1) / distribution, 1, (double) z / distribution);
            double y3 = myModule.GetValue((double) x / distribution, 1, (double) (z + 1) / distribution);
            double y4 = myModule.GetValue((double) (x + 1) / distribution, 1, (double) (z + 1) / distribution);

            Vertex vertex1;
            vertex1.position.x = x;
            vertex1.position.y = y1;
            vertex1.position.z = z;
            vertex1.uv_coord.x = 0;
            vertex1.uv_coord.y = 0;
            vertex1.color = Utils::color_RGB(red, 255, 0);
            vertex1.normal = glm::vec3(0.f, 1.f, 0.f);

            Vertex vertex2;
            vertex2.position.x = x + 1;
            vertex2.position.y = y2;
            vertex2.position.z = z;
            vertex2.uv_coord.x = 1;
            vertex2.uv_coord.y = 0;
            vertex2.color = Utils::color_RGB(red, 255, 0);
            vertex2.normal = glm::vec3(0.f, 1.f, 0.f);


            Vertex vertex3;
            vertex3.position.x = x;
            vertex3.position.y = y3;
            vertex3.position.z = z + 1;
            vertex3.uv_coord.x = 0;
            vertex3.uv_coord.y = 1;
            vertex3.color = Utils::color_RGB(red, 255, 0);
            vertex3.normal = glm::vec3(0.f, 1.f, 0.f);

            glm::vec3 normal = Utils::GetNormal(
                    glm::vec3(vertex1.position.x, vertex1.position.y, vertex1.position.z),
                    glm::vec3(vertex2.position.x, vertex2.position.y, vertex2.position.z),
                    glm::vec3(vertex3.position.x, vertex3.position.y, vertex3.position.z)
            );

            vertex1.normal = normal;
            vertex2.normal = normal;
            vertex3.normal = normal;

            btVector3 vector1 = btVector3(vertex1.position.x, vertex1.position.y, vertex1.position.z);
            btVector3 vector2 = btVector3(vertex2.position.x, vertex2.position.y, vertex2.position.z);
            btVector3 vector3 = btVector3(vertex3.position.x, vertex3.position.y, vertex3.position.z);

            tMesh->addTriangle(vector1, vector2, vector3);

            vertices.push_back(vertex1);
            vertices.push_back(vertex2);
            vertices.push_back(vertex3);

            Vertex vertex4;
            vertex4.position.x = x;
            vertex4.position.y = y3;
            vertex4.position.z = z + 1;
            vertex4.uv_coord.x = 0;
            vertex4.uv_coord.y = 1;
            vertex4.color = Utils::color_RGB(red2, 255, 0);
            vertex4.normal = glm::vec3(0.f, 1.f, 0.f);

            Vertex vertex5;
            vertex5.position.x = x + 1;
            vertex5.position.y = y2;
            vertex5.position.z = z;
            vertex5.uv_coord.x = 1;
            vertex5.uv_coord.y = 0;
            vertex5.color = Utils::color_RGB(red2, 255, 0);
            vertex5.normal = glm::vec3(0.f, 1.f, 0.f);

            Vertex vertex6;
            vertex6.position.x = x + 1;
            vertex6.position.y = y4;
            vertex6.position.z = z + 1;
            vertex6.uv_coord.x = 1;
            vertex6.uv_coord.y = 1;
            vertex6.color = Utils::color_RGB(red2, 255, 0);
            vertex6.normal = glm::vec3(0.f, 1.f, 0.f);

            glm::vec3 normal2 = Utils::GetNormal(
                    glm::vec3(vertex4.position.x, vertex4.position.y, vertex4.position.z),
                    glm::vec3(vertex5.position.x, vertex5.position.y, vertex5.position.z),
                    glm::vec3(vertex6.position.x, vertex6.position.y, vertex6.position.z)
            );

            vertex4.normal = normal2;
            vertex5.normal = normal2;
            vertex6.normal = normal2;

            btVector3 vector4 = btVector3(vertex4.position.x, vertex4.position.y, vertex4.position.z);
            btVector3 vector5 = btVector3(vertex5.position.x, vertex5.position.y, vertex5.position.z);
            btVector3 vector6 = btVector3(vertex6.position.x, vertex6.position.y, vertex6.position.z);

            tMesh->addTriangle(vector4, vector5, vector6);

            vertices.push_back(vertex4);
            vertices.push_back(vertex5);
            vertices.push_back(vertex6);
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

    // Vertex Normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, normal));

    // Vertex UV coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) offsetof(Vertex, uv_coord));

    // Vertex Color
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, color));
}

void DuplicatedVertexPlane::Draw() {
    RenderManager::getInstance()->RenderBaseShader();
//    int diffuseNr = 0;
//    for (GLuint i = 0; i < this->textures.size(); i++) {
//        glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit before binding
//        // Retrieve texture number (the N in diffuse_textureN)
//        std::string name = this->textures[i].type;
//        if (name == "diffuse")
//            diffuseNr++;
//        const char *shader_attribute = std::string("diffuse1").c_str();
//        int uniformLocation = (int) glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID,
//                                                         shader_attribute);
//        glUniform1f(uniformLocation, i);
//        glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
//    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(3);
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei) vertices.size());
    glDisableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glDisableVertexAttribArray(3);
    glBindVertexArray(0);
}

void DuplicatedVertexPlane::generateCollision() {
    if (hasCollision) {

        btTransform startTransform;
        startTransform.setIdentity();

        btBvhTriangleMeshShape* shape = new btBvhTriangleMeshShape(tMesh, true);
        btDefaultMotionState *motionstate = new btDefaultMotionState(startTransform);

        btScalar mass = 0;

        btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
                mass,               // mass, in kg. 0 -> Static object, will never move.
                motionstate,
                shape,        // collision shape of body
                btVector3(0, 0, 0)    // local inertia
        );


        rigidBody = new btRigidBody(rigidBodyCI);
        PhysicsManager::getInstance()->worldPhysics->dynamicsWorld->addRigidBody(rigidBody);
    }
}

