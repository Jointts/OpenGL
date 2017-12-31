//
// Created by Joonas on 26/12/2017.
//

#ifndef OPENGL_CHARACTERINSTANCE_H
#define OPENGL_CHARACTERINSTANCE_H


#include "../geometry/Quad.h"

class CharacterInstance : public Quad{
public:
    CharacterInstance(int width, int height);

    void SetTexture(uint textureId);
};


#endif //OPENGL_CHARACTERINSTANCE_H
