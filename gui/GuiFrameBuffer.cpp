//
// Created by Joonas on 11/7/2017.
//

#include <iostream>
#include "GuiWidget.h"
#include "GuiFrameBuffer.h"
#include "../ShaderManager.h"

GuiFrameBuffer::GuiFrameBuffer() {
    GenerateQuad();
    SetupMesh();

    GenerateCollisionFramebuffer();
    GenerateCollisionTexture();
    ConfigureCollisionFrameBuffer();
    UnbindFramebuffer();
}

void GuiFrameBuffer::GenerateCollisionFramebuffer() {
    glGenFramebuffers(1, &collisionFrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, collisionFrameBuffer);
}

void GuiFrameBuffer::GenerateCollisionTexture() {
    // The texture we're going to render to
    glGenTextures(1, &renderedTexture);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, renderedTexture);

    // Give an empty image to OpenGL ( the last "0" )
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, 3440, 1440, 0,GL_RGBA, GL_UNSIGNED_BYTE, 0);

    // Poor filtering. Needed !
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void GuiFrameBuffer::ConfigureCollisionFrameBuffer() {
    // Set "renderedTexture" as our colour attachement #0
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, renderedTexture, 0);

    // Set the list of draw buffers.
    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers); // "1" is the size of DrawBuffers

    // Always check that our framebuffer is ok
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) exit(-999);
}

void GuiFrameBuffer::RenderToCollisionFrameBuffer() {
    // Render to our framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, collisionFrameBuffer);
    glClearDepth(1.0f);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void GuiFrameBuffer::DrawCollisionBuffer() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(2);

    if (renderedTexture) {
        glActiveTexture(renderedTexture);
        glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->guiShader->shaderProgramID, "diffuse"),
                    renderedTexture);
        glBindTexture(GL_TEXTURE_2D, renderedTexture);
    }

    glDrawElements(GL_TRIANGLES, (GLsizei) indices.size(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}

void GuiFrameBuffer::GenerateQuad() {
    Vertex vertex1;
    vertex1.position = glm::vec3(0.0, 0.0, 0.0);
    vertex1.uv_coord = glm::vec2(0.0, 0.0);
    vertices.push_back(vertex1);

    Vertex vertex2;
    vertex2.position = glm::vec3(0.0, 1440.0, 0.0);
    vertex2.uv_coord = glm::vec2(0.0, 1.0);
    vertices.push_back(vertex2);

    Vertex vertex3;
    vertex3.position = glm::vec3(3440.0, 1440.0, 0.0);
    vertex3.uv_coord = glm::vec2(1.0, 1.0);
    vertices.push_back(vertex3);

    Vertex vertex4;
    vertex4.position = glm::vec3(3440.0, 0.0, 0.0);
    vertex4.uv_coord = glm::vec2(1.0, 0.0);
    vertices.push_back(vertex4);

    indices = {0, 1, 2, 2, 3, 0};
}

void GuiFrameBuffer::SetupMesh() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid *) 0);

    // Vertex UV coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, uv_coord));
}

void GuiFrameBuffer::ReadColor(double x, double y) {
    std::vector<unsigned char> pixelData(1 * 4);
    glBindFramebuffer(GL_FRAMEBUFFER, collisionFrameBuffer);
    glReadPixels((int) x, 1440 - (int) y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &pixelData[0]);

    cursorColor = glm::vec3((int)pixelData[0], (int)pixelData[1], (int)pixelData[2]);
}

void GuiFrameBuffer::UnbindFramebuffer() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
