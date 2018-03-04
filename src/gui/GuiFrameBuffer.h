//
// Created by Joonas on 11/7/2017.
//

#ifndef GAME_GUIFRAMEBUFFER_H
#define GAME_GUIFRAMEBUFFER_H

#ifndef __gl_h_
#include <glad/glad.h>
#endif

#include "vector"
#include "../Model.h"

class GuiFrameBuffer {

    GLuint renderedTexture = 0;

    GLuint VAO, VBO, EBO;

    std::vector<Vertex> vertices;

    std::vector<GLuint> indices;

public:
    glm::vec3 cursorColor;

    GuiFrameBuffer();

    void RenderToCollisionFrameBuffer();

    void DrawCollisionBuffer();

    GLuint collisionFrameBuffer = 0;

    void ReadColor(double x, double y);

private:
    void SetupMesh();

    void GenerateCollisionFramebuffer();

    void GenerateCollisionTexture();

    void ConfigureCollisionFrameBuffer();

    void UnbindFramebuffer();

    void GenerateQuad();

};


#endif //GAME_GUIFRAMEBUFFER_H
