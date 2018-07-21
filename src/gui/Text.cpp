//
// Created by Joonas on 26/12/2017.
//

#include "Text.h"
#include "FontManager.h"
#include "../renderer/RenderManager.h"

Text::Text(std::string str, std::string fontName, glm::vec3 color) {
    this->color = color;
    Font* font;
    int characterOffset = 0;

    font = FontManager::getInstance()->getFont(fontName);


    for (auto& ch : str) {
        Character character = font->characters.at(ch);
        CharacterInstance* characterInstance = new CharacterInstance(character.width, character.height, 50, 0);

        characterInstance->SetPosition(characterOffset, -(character.height - character.bearingY));
        characterInstance->setupMesh(characterInstance->vertices, characterInstance->indices);


        characterInstance->SetTexture(character.textureID);
        characters.push_back(characterInstance);
        characterOffset += character.advance >> 6;
    }
}

void Text::Draw() {
    RenderManager::getInstance()->RenderGuiShader();

    for (auto& characterInstance : characters) {
        characterInstance->Draw(color);
    }
}
