//
// Created by Joonas on 16/04/2017.
//

#ifndef SUMMIT_ENGINE_DEBUGDRAWER_H
#define SUMMIT_ENGINE_DEBUGDRAWER_H


#include <LinearMath/btIDebugDraw.h>
#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <vector>
#include "renderer/RenderManager.h"

struct DebugVertex{
    glm::vec3 position;
    glm::vec3 color;
};


class DebugDrawer : public btIDebugDraw
{

public:

    GLuint VAO, VBO;

    std::vector<DebugVertex> vertices;

    void setup(){
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(DebugVertex), (GLvoid*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(DebugVertex), (GLvoid*)offsetof(DebugVertex, position));

        glBindVertexArray(0);
    };

    void drawLine(const btVector3& from, const btVector3& to, const btVector3& color) override
    {
        glm::vec3 vertexColor = glm::vec3((GLfloat) color.getX(), (GLfloat) color.getY(), (GLfloat) color.getZ());
        DebugVertex debugVertex;

        debugVertex.position = glm::vec3((GLfloat) from.getX(), (GLfloat) from.getY(), (GLfloat) from.getZ());
        debugVertex.color = vertexColor;
        vertices.push_back(debugVertex);

        debugVertex.position = glm::vec3((GLfloat) to.getX(), (GLfloat) to.getY(), (GLfloat) to.getZ());
        debugVertex.color = vertexColor;
        vertices.push_back(debugVertex);
    }

    void draw3dText(const btVector3& location, const char* text) override { }

    void setDebugMode(int mode) override { this->mode = mode; }

    int getDebugMode() const override{ return this->mode; }

    void drawContactPoint(const btVector3 &PointOnB, const btVector3 &normalOnB, btScalar distance, int lifeTime,
                          const btVector3 &color) override {

    }

    void reportErrorWarning(const char *warningString) override {
        printf("ERROR::BULLET %s", warningString);
    }

    void Draw(){
        RenderManager::getInstance()->RenderDebugShader();
        if(vertices.size() != 0){
            glBindVertexArray(VAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(DebugVertex) * vertices.size(), vertices.data(), GL_DYNAMIC_DRAW);
            glEnableVertexAttribArray(0);
            glEnableVertexAttribArray(1);
            glDrawArrays(GL_LINES, 0, (GLsizei) vertices.size());
            glBindVertexArray(0);
            vertices.clear();
        }
    }

private:

    int mode;
};


#endif //SUMMIT_ENGINE_DEBUGDRAWER_H
