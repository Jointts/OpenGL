//
// Created by Joonas on 26/12/2017.
//

#ifndef OPENGL_CHARACTERINSTANCE_H
#define OPENGL_CHARACTERINSTANCE_H


#include "../geometry/Quad.h"

class CharacterInstance : public Quad{
public:

    void SetTexture(unsigned int textureId);

	CharacterInstance(int width, int height, int xMargin = 0, int yMargin = 0);

	void Draw(glm::vec3 color);
};


#endif //OPENGL_CHARACTERINSTANCE_H
