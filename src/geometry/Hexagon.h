#ifndef OPENGL_HEXAGON_H
#define OPENGL_HEXAGON_H

#ifndef __gl_h_

#include <glad/glad.h>

#endif

#include <vector>
#include "../Model.h"

class Hexagon
{
public:
	GLuint textureId;
	GLuint collisionTextureId;
	GLuint VAO, VBO, EBO;
	std::vector<Vertex> vertices;
	std::vector<Texture> textures;
	int gridOffsetX = 8;
	int gridOffsetY = 6;

	std::vector<GLuint> indices = {0, 1, 2, 0, 5, 1, 0, 3, 5, 0, 4, 3, 0, 6, 4, 0, 2, 6};
	const glm::vec2 centerPoint = glm::vec2(0.0f, 0.0f);
	glm::vec3 centerVertexPos;

	Hexagon(GLuint texture_id, const glm::vec2 center_point);
	void GenerateVertices();
	void SetupMesh();
	void SetTexture(char* imagePath);
	virtual void Draw();
};

#endif  OPENGL_HEXAGON_H
