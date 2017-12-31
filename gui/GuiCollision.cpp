//
// Created by Joonas on 16/09/2017.
//
#include <iostream>
#include "GuiCollision.h"
#include "../RenderManager.h"
#include "../ShaderManager.h"

GuiCollision::GuiCollision() {
    GenerateFrameBuffer();
    BindTexture();
    CheckFrameBufferState();
}

void GuiCollision::GenerateFrameBuffer() {
    glGenFramebuffers(1, &fbo);
    glGenTextures(1, &texture);
    GenerateVertices();
}

void GuiCollision::BindTexture() {
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1440, 900, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
}

void GuiCollision::CheckFrameBufferState() {
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cout << "FrameBuffer is not in completed state";
    }
}

void GuiCollision::UnbindFrameBuffer() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GuiCollision::GenerateRedShit() {

}

void GuiCollision::GenerateVertices(){
    Vertex vertex1;
    vertex1.position = glm::vec3(0.0, 0.0, 0.0);
    vertex1.uv_coord = glm::vec2(0.0, 0.0);
    vertices.push_back(vertex1);

    Vertex vertex2;
    vertex2.position = glm::vec3(0.0, 1.0, 0.0);
    vertex2.uv_coord = glm::vec2(0.0, 1.0);
    vertices.push_back(vertex2);

    Vertex vertex3;
    vertex3.position = glm::vec3(1.0, 1.0, 0.0);
    vertex3.uv_coord = glm::vec2(1.0, 1.0);
    vertices.push_back(vertex3);

    Vertex vertex4;
    vertex4.position = glm::vec3(1.0, 0.0, 0.0);
    vertex4.uv_coord = glm::vec2(1.0, 0.0);
    vertices.push_back(vertex4);

    indices = {0, 1, 2, 2, 3, 0};

    setupMesh(vertices, indices);
}

void GuiCollision::setupMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
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

void GuiCollision::GetCursorColor() {
    static const GLfloat g_quad_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            -1.0f,  1.0f, 0.0f,
            -1.0f,  1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            1.0f,  1.0f, 0.0f,
    };
    RenderManager::getInstance()->RenderGuiShader();


    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // we're not using the stencil buffer now
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    RenderManager::getInstance()->DrawGuiCollision();
    GLfloat color[3];
    //std::cout << "\nMouseX:" << mouseX << "MouseY: " << 900 - mouseY;
    glEnable(GL_DEPTH_TEST);
    glReadBuffer( GL_COLOR_ATTACHMENT0 );
    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    BindTexture();
    glDrawBuffers(1, DrawBuffers);
    glReadPixels(mouseX, 900 - mouseY, 1, 1, GL_RGB, GL_FLOAT, &color);
    if(color[0] * 255 == 255){
        std::cout << "Shir";
    }
    std::cout << "\nPixels are "
              << "\n R: "
              << color[0] * 255
              << "\n G: "
              << color[1] * 255
              << "\n B: "
              << color[2] * 255;
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(2);
    if(textureId){
        glActiveTexture(GL_TEXTURE0);
        glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->guiShader->shaderProgramID, "diffuse"), textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }
    glDrawElements(GL_TRIANGLES, (GLsizei) indices.size(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}

