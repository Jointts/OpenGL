#include "../geometry/Hexagon.h"
#include <map>

enum TileType
{
	TILE_GRASS,
	TILE_FOREST
};

static std::map<TileType, char*> TileModels = {
	{TILE_FOREST, "res/forest.FBX"}
}; 

class Tile : public Hexagon
{
private:
	Model* tileModel;

public:
	TileType tileType;

	Tile(GLuint texture_id, const glm::vec2& center_point, TileType tileType);

	void getTileModel();
	void moveTileModelToCenter();
	void Draw() override;
};