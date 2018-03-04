#include "Hexagon.h"
#include "../renderer/RenderManager.h"
#include "../shaders/ShaderManager.h"
#include <glm/gtc/type_ptr.inl>
#include "../camera/CameraManager.h"
#include "../Utils.h"

Hexagon::Hexagon(GLuint texture_id, const glm::vec2 center_point)
	: textureId(texture_id),
	centerPoint(center_point)
{
	GenerateVertices();
	SetupMesh();
}

void Hexagon::GenerateVertices()
{
	glm::vec3 redColor = glm::vec3(1.0f, 0.0f, 0.0f);

	glm::vec3 centerVertexPos;
	centerVertexPos.x = centerPoint.x * gridOffsetX;
	centerVertexPos.z = centerPoint.y * gridOffsetY;
	centerVertexPos.y = 0;

	if(int(centerPoint.y) % 2 != 0)
	{
		centerVertexPos.x += 4;
	}

	this->centerVertexPos = centerVertexPos;

	Vertex centerVertex;
	centerVertex.position = centerVertexPos;
//	centerVertex.color = redColor;
	centerVertex.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	centerVertex.uv_coord = glm::vec2(0.5f, 0.5f);
	vertices.push_back(centerVertex);
	
	glm::vec3 topLeftVertexPos;
	topLeftVertexPos.x = centerVertexPos.x - 4;
	topLeftVertexPos.z = centerVertexPos.z + 2;
	topLeftVertexPos.y = 0;
	Vertex topLeft;
	topLeft.position = topLeftVertexPos;
//	topLeft.color = redColor;
	topLeft.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	topLeft.uv_coord = glm::vec2(0.0f, 0.75f);
	vertices.push_back(topLeft);

	glm::vec3 bottomLeftVertexPos;
	bottomLeftVertexPos.x = centerVertexPos.x - 4;
	bottomLeftVertexPos.z = centerVertexPos.z - 2;
	bottomLeftVertexPos.y = 0;
	Vertex bottomLeft;
	bottomLeft.position = bottomLeftVertexPos;
//	bottomLeft.color = redColor;
	bottomLeft.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	bottomLeft.uv_coord = glm::vec2(0.0f, 0.25f);
	vertices.push_back(bottomLeft);

	glm::vec3 topRightVertexPos;
	topRightVertexPos.x = centerVertexPos.x + 4;
	topRightVertexPos.z = centerVertexPos.z + 2;
	topRightVertexPos.y = 0;
	Vertex topRight;
	topRight.position = topRightVertexPos;
//	topRight.color = redColor;
	topRight.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	topRight.uv_coord = glm::vec2(1.0f, 0.75f);
	vertices.push_back(topRight);

	glm::vec3 bottomRightVertexPos;
	bottomRightVertexPos.x = centerVertexPos.x + 4;
	bottomRightVertexPos.z = centerVertexPos.z - 2;
	bottomRightVertexPos.y = 0;
	Vertex bottomRight;
	bottomRight.position = bottomRightVertexPos;
//	bottomRight.color = redColor;
	bottomRight.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	bottomRight.uv_coord = glm::vec2(1.0f, 0.25f);
	vertices.push_back(bottomRight);

	glm::vec3 topVertexPos;
	topVertexPos.x = centerVertexPos.x;
	topVertexPos.z = centerVertexPos.z + 4;
	topVertexPos.y = 0;
	Vertex top;
	top.position = topVertexPos;
//	top.color = redColor;
	top.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	top.uv_coord = glm::vec2(0.5f, 1.0f);
	vertices.push_back(top);

	glm::vec3 bottomVertexPos;
	bottomVertexPos.x = centerVertexPos.x;
	bottomVertexPos.z = centerVertexPos.z - 4;
	bottomVertexPos.y = 0;
	Vertex bottom;
	bottom.position = bottomVertexPos;
//	bottom.color = redColor;
	bottom.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	bottom.uv_coord = glm::vec2(0.5f, 0.0f);
	vertices.push_back(bottom);
}

void Hexagon::SetupMesh()
{
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
		(GLvoid *)0);

	// Vertex Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid *)offsetof(Vertex, normal));

	// Vertex UV coordinates
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, uv_coord));

//	// Vertex Color
//	glEnableVertexAttribArray(3);
//	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
//		(GLvoid *)offsetof(Vertex, color));
}

// TODO: Implement set texture
void Hexagon::SetTexture(char* imagePath)
{
	Texture texture;
	texture.id = Utils::TextureFromFile(imagePath, false);
	texture.type = "diffuse";
	textures.push_back(texture);
}

void Hexagon::Draw()
{
	GLint modelLoc = glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0)));
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDisable(GL_CULL_FACE);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	int diffuseNr = 0;
	for (GLuint i = 0; i < this->textures.size(); i++) {
	    glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit before binding
	    // Retrieve texture number (the N in diffuse_textureN)
	    std::string name = this->textures[i].type;
	    if (name == "diffuse")
	        diffuseNr++;
	    int uniformLocation = (int) glGetUniformLocation(ShaderManager::getInstance()->baseShader->shaderProgramID,
			"diffuse1");
	    glUniform1f(uniformLocation, i);
	    glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
	}
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
//	glEnableVertexAttribArray(3);
	glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
//	glDisableVertexAttribArray(3);
	glBindVertexArray(0);
}
