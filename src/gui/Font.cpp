//
// Created by Joonas on 26/12/2017.
//

#include <iostream>
#include "Font.h"

Font::Font(char *fontPath) {
    InitializeFont(fontPath);
    LoadAllCharacters();
    Cleanup();
}

void Font::InitializeFont(char *fontPath) {
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

    if (FT_New_Face(ft, fontPath, 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
}

void Font::LoadAllCharacters() {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    for (int x = 0; x < 128; x++) {
        char      characterID = (char) x;
        Character character   = LoadCharacter(x);
        characters.insert(std::pair<char, Character>(characterID, character));
    }
}

Character Font::LoadCharacter(int charIn) {
    FT_Set_Pixel_Sizes(face, 0, (unsigned int) 128);

    if (FT_Load_Char(face, charIn, FT_LOAD_RENDER))
        std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;

    Character character = Character{
            LoadCharacterTexture(),
            (unsigned short) face->glyph->bitmap.width,
            (unsigned short) face->glyph->bitmap.rows,
            (unsigned short) face->glyph->advance.x,
            (unsigned short) face->glyph->bitmap_left,
            (unsigned short) face->glyph->bitmap_top
    };

    return character;
}

GLuint Font::LoadCharacterTexture() {
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
    );
    glGenerateMipmap(GL_TEXTURE_2D);
    // Set texture options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return texture;
}

void Font::Cleanup() {
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}
