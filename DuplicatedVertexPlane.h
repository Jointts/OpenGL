//
// Created by Joonas on 01/09/2017.
//

#ifndef OPENGL_DUPLICATEDVERTEXPLANE_H
#define OPENGL_DUPLICATEDVERTEXPLANE_H


#include <jmorecfg.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include "Model.h"

class DuplicatedVertexPlane {
public:
    int sizeX;
    int sizeZ;
    bool hasCollision;

    GLuint VAO;
    GLuint VBO;

    btRigidBody *rigidBody;

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;

    DuplicatedVertexPlane(int sizeX, int sizeY, bool hasCollision);
    DuplicatedVertexPlane(int sizeX, int sizeY, const char *imagePath, bool hasCollision);

    void setImage(const char *imagePath);
    void generateVertices();
    void setupMesh(std::vector<Vertex> vertices);
    void generateCollision();
    void Draw();

private:
    std::vector<float> heightCoords;

    void populateHeightCoords();
};


#endif //OPENGL_DUPLICATEDVERTEXPLANE_H
