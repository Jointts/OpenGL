//
// Created by Joonas on 10/11/2016.
//

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/DefaultLogger.hpp>
#include <iostream>
#include <ext.hpp>
#include <LinearMath/btVector3.h>
#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>
#include "Model.h"
#include "Mesh.h"
#include "shaders/ShaderManager.h"
#include "renderer/RenderManager.h"
#include "Utils.h"

Model::Model() {
    createAssimpLog();
}

Model::Model(std::string meshPath) {
    model_file = meshPath;
    importFile();
}

void Model::importFile() {
    Assimp::Importer importer;

    if (model_file.empty()) {
        Assimp::DefaultLogger::get()->error("No input file specified for object import, exiting.");
        return;
    }

    // Temprorary fix to the Y Up problem is to include the flag aiProcess_PreTransformVertices, however this will remove all animations
    const aiScene *scene = importer.ReadFile(model_file, aiProcess_Triangulate | aiProcess_FlipUVs |
                                                         aiProcess_PreTransformVertices);

    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        Assimp::DefaultLogger::get()->error("Import of file " + model_file + " failed.");
        return;
    }

//    aiNode* RootNode = FixRotation(scene->mRootNode);

    processNode(scene->mRootNode, scene);

    Assimp::DefaultLogger::get()->info("Import of file " + model_file + " successful.");
}

//aiNode* Model::FixRotation(aiNode* rootNode) {
//    rootNode->mTransformation = rootNode->mTransformation-> * glm::rotate(glm::mat4(1.0f), -90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
//    for( rootNode->mChildren)
//    return rootNode;
//}

void Model::createAssimpLog() {
    // Change this line to normal if you not want to analyse the import process
    //Assimp::Logger::LogSeverity severity = Assimp::Logger::NORMAL;
    Assimp::Logger::LogSeverity severity = Assimp::Logger::VERBOSE;

    // Create a logger instance for Console Output
    Assimp::DefaultLogger::create("", severity, aiDefaultLogStream_STDOUT);
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    // Process all the node's meshes (if any)
    for (auto j = 0; j < node->mNumMeshes; ++j) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[j]];
        meshes.push_back(processMesh(mesh, scene));
    }

    // Then do the same for each of its children
    for (auto i = 0; i < node->mNumChildren; i++) {
        this->processNode(node->mChildren[i], scene);
    }

}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> diffuseMaps;

    for (int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;

        /* Read the vertex positions */
        if (mesh->HasPositions()) {
            vertex.position.x = mesh->mVertices[i].x;
            vertex.position.y = mesh->mVertices[i].y;
            vertex.position.z = mesh->mVertices[i].z;
        } else {
            std::string meshName(mesh->mName.C_Str());
            Assimp::DefaultLogger::get()->info("Mesh " + meshName + " has no Vertex positions");
        }

        /* Read the normals */
        if (mesh->HasNormals()) {
            vertex.normal.x = mesh->mNormals[i].x;
            vertex.normal.y = mesh->mNormals[i].y;
            vertex.normal.z = mesh->mNormals[i].z;
        } else {
            std::string meshName(mesh->mName.C_Str());
            Assimp::DefaultLogger::get()->info("Mesh " + meshName + " has no normals");
        }

        /* Read the uv coords */
        if (mesh->HasTextureCoords(0)) {
            vertex.uv_coord.x = mesh->mTextureCoords[0][i].x;
            vertex.uv_coord.y = mesh->mTextureCoords[0][i].y;
        } else {
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
    if (scene->HasMaterials()) {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        diffuseMaps = processMaterial(aiTextureType_DIFFUSE, material, "diffuse");
    }

    return Mesh(vertices, indices, diffuseMaps);
}

std::vector<Texture>
Model::processMaterial(aiTextureType textureType, aiMaterial *material, std::string textureTypeString) {
    std::vector<Texture> textures;
    aiString path;
    std::string directory = "res/";
    for (GLuint i = 0; i < material->GetTextureCount(textureType); i++) {
        material->GetTexture(textureType, i, &path);
        std::string formattedPath = std::string(path.data);
        std::replace(formattedPath.begin(), formattedPath.end(), '\\', '/');
        std::string texture_path = directory + formattedPath;
        Texture texture;
        texture.id = Utils::TextureFromFile(texture_path.c_str(), false);
        texture.type = textureTypeString;
        textures.push_back(texture);
    }
    return textures;
}

void Model::Draw() {
    RenderManager::getInstance()->RenderBaseShader();
    glUniformMatrix4fv(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "model"), 1,
                       GL_FALSE, glm::value_ptr(model));
    if (drawOutline) {
        glUniform1i(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "hit"), 1);
    } else {
        glUniform1i(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "hit"), 0);
    }
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

