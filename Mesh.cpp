//
// Created by Joonas on 10/20/2016.
//

#include <glm/gtc/type_ptr.hpp>
#include "Mesh.h"
#include "shaders/ShaderProgram.h"
#include "shaders/ShaderManager.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures) {
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;

    this->setupMesh();
}

void Mesh::setupMesh() {
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
                 indices.data(), GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid*)0);

    // Vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, normal));

    // Vertex UV coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, uv_coord));

    glBindVertexArray(0);
}

void Mesh::Draw() {
    int diffuseNr = 0;
    for(GLuint i = 0; i < this->textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit before binding
        // Retrieve texture number (the N in diffuse_textureN)
        std::string name = this->textures[i].type;
        if(name == "diffuse")
            diffuseNr++;
            const char* shader_attribute =  std::string("diffuse" + diffuseNr).c_str();
        glUniform1f(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, shader_attribute), i);
        glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
    }
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
