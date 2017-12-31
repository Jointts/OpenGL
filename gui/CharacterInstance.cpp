//
// Created by Joonas on 26/12/2017.
//

#include "CharacterInstance.h"

CharacterInstance::CharacterInstance(int width, int height) : Quad(width, height) {}

void CharacterInstance::SetTexture(uint textureId) {
    this->textureId = textureId;
}
