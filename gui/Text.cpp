//
// Created by Joonas on 26/12/2017.
//

#include "Text.h"
#include "Font.h"
#include "FontManager.h"

Text::Text(char *str) {
    Font *font = FontManager::getInstance()->getFont("LATO_LIGHT");
    Character character = font->characters.at('a');

    characterInstance = new CharacterInstance(character.width, character.height);
    characterInstance->SetTexture(character.textureID);
}

void Text::Draw(){
    characterInstance->Draw();
}
