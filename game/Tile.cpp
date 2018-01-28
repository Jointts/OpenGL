#include "Tile.h"
#include <iostream>

Tile::Tile(GLuint texture_id, const glm::vec2& center_point, TileType tileType)
	: Hexagon(texture_id, center_point), tileType(tileType)
{
	getTileModel();
	moveTileModelToCenter();
}

void Tile::getTileModel()
{
	try
	{
		char* modelPath = TileModels.at(tileType);
		tileModel = new Model(modelPath);
	}catch(std::out_of_range)
	{
		std::cout << "TILE::NO_MATCHING_MODEL_TYPE" << std::endl;
		exit(-200);
	}
}

void Tile::moveTileModelToCenter()
{
	tileModel->Translate(glm::vec3(centerVertexPos.x, centerVertexPos.y, centerVertexPos.z));
}

void Tile::Draw()
{
	Hexagon::Draw();
	tileModel->Draw();
}
