//
// Created by Joonas on 16/04/2017.
//

#include <LinearMath/btDefaultMotionState.h>
#include <BulletCollision/CollisionShapes/btBoxShape.h>
#include <BulletCollision/CollisionShapes/btTriangleMesh.h>
#include <BulletCollision/CollisionShapes/btConvexTriangleMeshShape.h>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Entity.h"
#include "physics/PhysicsManager.h"
#include "Mesh.h"
#include "RenderManager.h"
#include "Utils.h"
#include "Tree.h"

Entity::Entity(GLchar* modelPath, bool generateCollision = false) {
    model = new Model(modelPath);

    if(generateCollision && model){
        this->hasCollision = true;
        GenerateCollision();
    }

    RenderManager::getInstance()->entities.push_back((Entity *&&) this);
}

void Entity::GenerateCollision(){
    btTriangleMesh* trimesh = new btTriangleMesh();

    for (auto &&mesh :model->meshes) {
        for (int i = 0; i * 3 < mesh.indices.size(); i++)
        {
            int index0 = mesh.indices[i * 3];
            int index1 = mesh.indices[i * 3 + 1];
            int index2 = mesh.indices[i * 3 + 2];

            btVector3 vertex0(mesh.vertices[index0].position.x, mesh.vertices[index0].position.y, mesh.vertices[index0].position.z);
            btVector3 vertex1(mesh.vertices[index1].position.x, mesh.vertices[index1].position.y, mesh.vertices[index1].position.z);
            btVector3 vertex2(mesh.vertices[index2].position.x, mesh.vertices[index2].position.y, mesh.vertices[index2].position.z);

            trimesh->addTriangle(vertex0, vertex1, vertex2);
        }
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
    rigidBody->setUserPointer(this);

    PhysicsManager::getInstance()->dynamicsWorld->addRigidBody(rigidBody);
}

void Entity::Rotate(float angle, glm::vec3 axis){
    btScalar physicsMatrix[16];
    rigidBody->getWorldTransform().getOpenGLMatrix(physicsMatrix);
    glm::mat4 rotatedMatrix = glm::rotate(Utils::BulletToGlm(physicsMatrix), angle, axis);
    rigidBody->setWorldTransform(Utils::glmToBullet(rotatedMatrix));
}

void Entity::Scale(glm::vec3 axis){
    btScalar physicsMatrix[16];
    rigidBody->getWorldTransform().getOpenGLMatrix(physicsMatrix);
    glm::mat4 scaledMatrix = glm::scale(Utils::BulletToGlm(physicsMatrix), axis);
    rigidBody->setWorldTransform(Utils::glmToBullet(scaledMatrix));
}

void Entity::Translate(glm::vec3 axis){
    btScalar physicsMatrix[16];
    rigidBody->getWorldTransform().getOpenGLMatrix(physicsMatrix);
    glm::mat4 translatedMatrix = glm::translate(Utils::BulletToGlm(physicsMatrix), axis);
    rigidBody->setWorldTransform(Utils::glmToBullet(translatedMatrix));
}
