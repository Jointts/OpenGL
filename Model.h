//
// Created by Joonas on 10/11/2016.
//

#ifndef OPENGL_MODEL_H
#define OPENGL_MODEL_H


#include <vec3.hpp>
#include <vec2.hpp>
#include <assimp/scene.h>
#ifndef __gl_h_
#include <glad/glad.h>
#endif
#include <vector>
#include <detail/type_mat4x4.hpp>
#include "shaders/ShaderProgram.h"
#include <map>
#include "Animation.h"

const int MAX_BONES_PER_VERTEX = 4;

struct Bone
{
	unsigned int BoneID;
	float Weight;
};

struct Texture {
    GLuint id;
    std::string type;
};

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv_coord;
    glm::vec3 color;
	int boneIDs[MAX_BONES_PER_VERTEX] = {};
	int boneWeights[MAX_BONES_PER_VERTEX] = {};
};

class Mesh;

class Model {
	Animation* activeAnimation = nullptr;
public:
	std::map<unsigned int, aiMatrix4x4*> boneOffsetMatrices;

    bool drawOutline = false;

    Model(std::string meshPath);

    glm::mat4 model = glm::mat4(1.0f);

    Model();

    void createAssimpLog();

    void importFile();

    void processNode(aiNode *node, const aiScene *scene);

    std::string model_file;

    std::vector<Mesh> meshes;

	std::vector<aiBone*> bones;

	std::vector<Animation*> animations = {};

    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	void ProcessBones(aiBone** bones, int numOfBones, std::vector<Vertex> vertices, int vertexStartIndex);
	void ProcessAnimations(aiAnimation** animations, int animationCount);

	std::vector<Texture>
    processMaterial(aiTextureType textureType, aiMaterial *material, std::string textureTypeString);

    void Rotate(GLfloat angle, glm::vec3 axis);

    void Translate(glm::vec3 axis);

    void Scale(glm::vec3 axis);
	void SetAnimation(int animationToPlay);
	void PlayAnimation();

	void Draw();

    aiNode * FixRotation(aiNode *rootNode);
};


#endif //OPENGL_MODEL_H
