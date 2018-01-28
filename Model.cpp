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
    const aiScene *scene = importer.ReadFile(model_file, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        Assimp::DefaultLogger::get()->error("Import of file " + model_file + " failed.");
        return;
    }

//    aiNode* RootNode = FixRotation(scene->mRootNode);

    processNode(scene->mRootNode, scene);

	if (scene->HasAnimations())
	{
		ProcessAnimations(scene->mAnimations, scene->mNumAnimations);
	}

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

	/* Read the indices */
    for (int i = 0; i < mesh->mNumFaces; ++i) {
        aiFace face = mesh->mFaces[i];
        for (int j = 0; j < face.mNumIndices; ++j) {
            indices.push_back(face.mIndices[j]);
        }
    }

	/* Read the bones */
	if(mesh->HasBones())
	{
		int meshVertexStartIndex;
		if(meshes.size() == 0)
		{
			meshVertexStartIndex = 0;
		}else
		{
			meshVertexStartIndex = scene->mMeshes[meshes.size()]->mNumVertices - 1;
		}
		ProcessBones(mesh->mBones, mesh->mNumBones, vertices, meshVertexStartIndex);
	}

    /* Read the textures */
    if (scene->HasMaterials()) {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        diffuseMaps = processMaterial(aiTextureType_DIFFUSE, material, "diffuse");
    }

    return Mesh(vertices, indices, diffuseMaps);
}

void Model::ProcessBones(aiBone** bones, int numOfBones, std::vector<Vertex> vertices, int vertexStartIndex)
{
	for(int boneIndex = 0; boneIndex < numOfBones; boneIndex++)
	{
		aiBone* bone = bones[boneIndex];
		boneOffsetMatrices.insert(std::pair<unsigned int, aiMatrix4x4*>(boneIndex, &bone->mOffsetMatrix));
		for(int weightIndex = 0; weightIndex < bone->mNumWeights; weightIndex++)
		{
			aiVertexWeight vertexWeight = bone->mWeights[weightIndex];
			Vertex* vertexToUpdate = &vertices[vertexWeight.mVertexId];
			for(int boneId = 0; boneId < MAX_BONES_PER_VERTEX; boneId++)
			{
				if(vertexToUpdate->boneWeights[boneId] == 0.0)
				{
					vertexToUpdate->boneIDs[boneId] = boneIndex;
					vertexToUpdate->boneWeights[boneId] = vertexWeight.mWeight;
				}else
				{
					std::cout << "WARNING::ASSIMP::VERTEX_HAS_MORE_BONES_THAN_SUPPORTED count > " << MAX_BONES_PER_VERTEX << std::endl;
					assert(0);
				}
			}
		}
	}
}

// TODO: Load in animations, create Animation class as a container for them
void Model::ProcessAnimations(aiAnimation** animations, int animationCount)
{
	for (int index = 0; index < animationCount; index++) {
		aiAnimation* animation = animations[index];
		Animation* animToAdd = new Animation(animation->mTicksPerSecond, animation->mDuration, animation->mChannels, animation->mNumChannels, animation->mName);
		this->animations.push_back(animToAdd);
	}
	std::cout << "TEST";
}

std::vector<Texture> Model::processMaterial(aiTextureType textureType, aiMaterial *material, std::string textureTypeString) {
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
	Model::PlayAnimation();
    RenderManager::getInstance()->RenderBaseShader();
    glUniformMatrix4fv(glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "model"), 1,
                       GL_FALSE, glm::value_ptr(model));
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

void Model::SetAnimation(int animationToPlay)
{
	activeAnimation = animations[animationToPlay];
}

void Model::PlayAnimation()
{
	if(activeAnimation)
	{
		if(!activeAnimation->animationEnded)
		{
			activeAnimation->Play();
		}else
		{
			activeAnimation = nullptr;
		}
	}
}
