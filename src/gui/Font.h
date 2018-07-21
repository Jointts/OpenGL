//
// Created by Joonas on 26/12/2017.
//

#ifndef SUMMIT_ENGINE_FONT_H
#define SUMMIT_ENGINE_FONT_H


#include "GuiWidget.h"
#include <ft2build.h>
#include <map>
#include FT_FREETYPE_H

struct Character {
    unsigned int textureID;

    unsigned short width;
    unsigned short height;

    unsigned short advance;

    unsigned short bearingX;
    unsigned short bearingY;

};

class Font {
    FT_Library ft;
    FT_Face    face;

    void Cleanup();
    void InitializeFont(char *fontPath);
    Character LoadCharacter(int character);
    GLuint LoadCharacterTexture();
    void LoadAllCharacters();
public:

    std::map<char, Character> characters;

    Font() = delete;
    explicit Font(char *fontPath);
};


#endif //SUMMIT_ENGINE_FONT_H
