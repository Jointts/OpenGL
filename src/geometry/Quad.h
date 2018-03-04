//
// Created by Joonas on 12/04/2017.
//

#ifndef OPENGL_QUAD_H
#define OPENGL_QUAD_H


#ifndef __gl_h_

#include <glad/glad.h>

#endif

#include <vector>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include "../Model.h"

class Quad {
public:
    Quad(int width, int height, int xPos = 0, int yPos = 0);
	virtual void GenerateMesh();

	GLuint textureId;
    GLuint collisionTextureId;
    GLuint VAO, VBO, EBO;
    std::vector<Vertex> vertices;

    std::vector<GLuint> indices;

    btRigidBody *rigidBody;

    virtual void setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);

    float width = 100;

    float height = 100;

    virtual void Draw(int textureId, GLenum textureUnit);
	void SetPosition(int xPos, int yPos);
};


#endif //OPENGL_QUAD_H
