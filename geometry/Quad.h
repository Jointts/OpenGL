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
    GLuint VAO, VBO, EBO;
    std::vector<Vertex> vertices;

    std::vector<GLuint> indices;

    btRigidBody* rigidBody;

    void setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);

    void Draw();

    float getMarginLeft() const;

    void setMarginLeft(float marginLeft);

    float getMarginRight() const;

    void setMarginRight(float marginRight);

    float getMarginTop() const;

    void setMarginTop(float marginTop);

    float getMarginBottom() const;

    void setMarginBottom(float marginBottom);

    void ChangeTexture(GLchar* path);
private:
    float width = 100;
    float height = 100;
    float marginLeft = 0;
    float marginRight = 0;
    float marginTop = 0;

    float marginBottom = 0;

    void UpdatePosition();

    void GenerateCollision();
};


#endif //OPENGL_QUAD_H
