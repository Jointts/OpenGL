//
// Created by Joonas on 16/04/2017.
//

#ifndef SUMMIT_ENGINE_ENTITY_H
#define SUMMIT_ENGINE_ENTITY_H

#ifndef __gl_h_

#include <glad/glad.h>

#endif

#include <BulletDynamics/Dynamics/btRigidBody.h>
#include "Model.h"

enum EntityType {
    BASIC,
    TREE,
    TERRAIN
};

class Entity {

    void GenerateCollision();

public:
    EntityType  entityType = BASIC;
    glm::vec3   scale      = glm::vec3(1.f, 1.f, 1.f);
    bool        hasCollision;
    btRigidBody *rigidBody;
    Model       *model;

    Entity() = delete;

    Entity(GLchar *modelPath, bool generateCollision);
    virtual void Rotate(float angle, glm::vec3 axis);
    virtual void Scale(glm::vec3 axis);
    virtual void Translate(glm::vec3 axis);

    virtual void ClickEvent();
};


#endif //SUMMIT_ENGINE_ENTITY_H
