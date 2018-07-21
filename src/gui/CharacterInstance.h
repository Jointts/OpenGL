//
// Created by Joonas on 26/12/2017.
//

#ifndef SUMMIT_ENGINE_CHARACTERINSTANCE_H
#define SUMMIT_ENGINE_CHARACTERINSTANCE_H


#include "../geometry/Quad.h"

class CharacterInstance : public Quad {
public:

    CharacterInstance(int width, int height, int xMargin = 0, int yMargin = 0);

    void SetTexture(unsigned int textureId);
    void Draw(glm::vec3 color);
};


#endif //SUMMIT_ENGINE_CHARACTERINSTANCE_H
