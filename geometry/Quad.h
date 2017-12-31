//
// Created by Joonas on 12/04/2017.
//

#ifndef OPENGL_QUAD_H
#define OPENGL_QUAD_H


#include <OpenGL/OpenGL.h>
#include <vector>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include "../Model.h"

class Quad {
public:
    Quad(int width, int height);

    GLuint textureId;
    GLuint collisionTextureId;
    GLuint VAO, VBO, EBO;
    std::vector<Vertex> vertices;

    std::vector<GLuint> indices;

    btRigidBody* rigidBody;

    void setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);

    virtual void Draw();

    void GenerateCollision();

    float width = 100;

    float height = 100;

};


#endif //OPENGL_QUAD_H
