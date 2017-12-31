//
// Created by Joonas on 16/09/2017.
//

#ifndef OPENGL_GUICOLLISION_H
#define OPENGL_GUICOLLISION_H

#ifndef __gl_h_
#include <glad/glad.h>
#include <vector>
#include "../Model.h"

#endif

class GuiCollision {
    GLuint textureId;
    GLuint collisionTextureId;
    GLuint VAO, VBO, EBO;
    std::vector<Vertex> vertices;

    int width, height = 200;

    std::vector<GLuint> indices;

    unsigned int fbo;

    void GenerateFrameBuffer();

    void GenerateRedShit();

    void UnbindFrameBuffer();

    void GenerateVertices();

    void setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
public:
    GuiCollision();

    void BindTexture();

    void CheckFrameBufferState();

    void GetCursorColor();

    unsigned int texture;
    int mouseX;
    int mouseY = 0;
};


#endif //OPENGL_GUICOLLISION_H
