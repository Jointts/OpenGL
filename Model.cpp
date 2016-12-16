//
// Created by Joonas on 10/11/2016.
//

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/DefaultLogger.hpp>
#include <iostream>
#include <stb_image.h>
#include <ext.hpp>
#include "Model.h"
#include "Mesh.h"
#include "ShaderProgram.h"

Model::Model(){
    createAssimpLog();
}

void Model::importFile() {
    Assimp::Importer importer;

    if(model_file.empty()){
        Assimp::DefaultLogger::get()->error("No input file specified for object import, exiting.");
        return;
    }

    const aiScene* scene = importer.ReadFile(model_file, aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        Assimp::DefaultLogger::get()->error("Import of file " + model_file + " failed.");
        return;
    }

    processNode(scene->mRootNode, scene);

    Assimp::DefaultLogger::get()->info("Import of file " + model_file + " successful.");
}

void Model::createAssimpLog() {
    // Change this line to normal if you not want to analyse the import process
    //Assimp::Logger::LogSeverity severity = Assimp::Logger::NORMAL;
    Assimp::Logger::LogSeverity severity = Assimp::Logger::VERBOSE;

    // Create a logger instance for Console Output
    Assimp::DefaultLogger::create("",severity, aiDefaultLogStream_STDOUT);
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    // Process all the node's meshes (if any)
    for (auto j = 0; j < node->mNumMeshes; ++j) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[j]];
        meshes.push_back(processMesh(mesh, scene));
    }

    // Then do the same for each of its children
    for(auto i = 0; i < node->mNumChildren; i++)
    {
        this->processNode(node->mChildren[i], scene);
    }

}

Mesh Model::processMesh(aiMesh *mesh, const aiScene* scene) {
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> diffuseMaps;

    for (int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;

        /* Read the vertex positions */
        if(mesh->HasPositions()){
            vertex.position.x = mesh->mVertices[i].x;
            vertex.position.y = mesh->mVertices[i].y;
            vertex.position.z = mesh->mVertices[i].z;
        }else{
            std::string meshName(mesh->mName.C_Str());
            Assimp::DefaultLogger::get()->info("Mesh " + meshName + " has no Vertex positions");
        }

        /* Read the normals */
        if(mesh->HasNormals()){
            vertex.normal.x = mesh->mNormals[i].x;
            vertex.normal.y = mesh->mNormals[i].y;
            vertex.normal.z = mesh->mNormals[i].z;
        }else{
            std::string meshName(mesh->mName.C_Str());
            Assimp::DefaultLogger::get()->info("Mesh " + meshName + " has no normals");
        }

        /* Read the uv coords */
        if(mesh->HasTextureCoords(0)){
            vertex.uv_coord.x = mesh->mTextureCoords[0][i].x;
            vertex.uv_coord.y = mesh->mTextureCoords[0][i].y;
        }else{
            std::string meshName(mesh->mName.C_Str());
            Assimp::DefaultLogger::get()->info("Mesh " + meshName + " has no UV coordinates");
        }

        vertices.push_back(vertex);
    }

    for (int i = 0; i < mesh->mNumFaces; ++i) {
        aiFace face = mesh->mFaces[i];
        for (int j = 0; j < face.mNumIndices; ++j) {
            indices.push_back(face.mIndices[j]);
        }
    }

    /* Read the textures */
    if(scene->HasMaterials()){
        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
        diffuseMaps = processMaterial(aiTextureType_DIFFUSE, material, "diffuse");
    }

    return Mesh(vertices, indices, diffuseMaps);
}

GLuint TextureFromFile(const char* path)
{
    int width;
    int height;
    int bytesPerPixel;
    GLuint textureID;
    Assimp::DefaultLogger::get()->info("Loading texture from: " + std::string(path));
    unsigned char *pixelData = stbi_load(path, &width, &height, &bytesPerPixel, STBI_rgb);

    if(!pixelData){
        Assimp::DefaultLogger::get()->warn("Texture with path '" + std::string(path) + "' cannot be loaded");
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(pixelData);
    return textureID;
}

std::vector<Texture> Model::processMaterial(aiTextureType textureType, aiMaterial *material, std::string textureTypeString){
    std::vector<Texture> textures;
    aiString path;
    std::string directory = "res\\";
    for(GLuint i = 0; i < material->GetTextureCount(textureType); i++){
        material->GetTexture(textureType, i, &path);
        std::string texture_path = directory + path.C_Str();
        Texture texture;
        texture.id = TextureFromFile(texture_path.c_str());
        texture.type = textureTypeString;
        textures.push_back(texture);
    }
    return textures;
}

void Model::Draw(){
    glUniformMatrix4fv(glGetUniformLocation(ShaderProgram::getInstance()->shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));
    for (int i = 0; i < meshes.size(); ++i) {
        meshes[i].Draw();
    }
}

void Model::Rotate(GLfloat angle, glm::vec3 axis) {
    model = glm::rotate(model, angle, axis);
}

void Model::Translate(glm::vec3 axis) {
    model = glm::translate(model, axis);
}

void Model::Scale(glm::vec3 axis) {
    model = glm::scale(model, axis);
}
