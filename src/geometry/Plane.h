//
// Created by Joonas on 12/14/2016.
//

#ifndef OPENGL_PLANE_H
#define OPENGL_PLANE_H


#include <vector>
#include "../Model.h"

class Plane {

    glm::mat4 model;
    int       distribution                 = 100;

    void GenerateIndices();

protected:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    void setupMesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
public:
    Plane();

    int                  sizeX;
    int                  sizeZ;
    bool                 generateHeightMap = true;
    std::vector<Texture> textures;
    std::vector<float>   heightCoords;


    Plane(int sizeX, int sizeZ, int tileSize, bool generateHeightMap);

    virtual void Draw();
    void GenerateVertices();
    void UpdateMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
    void GenerateNormals();
    void GenerateUVCoords(int currentIndex, int nextRow);
    void AddTexture(const char *texturePath);
};


#endif //OPENGL_PLANE_H
