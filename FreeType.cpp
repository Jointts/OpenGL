//
// Created by Joonas on 15/04/2017.
//

#include <iostream>
#include <glad/glad.h>
#include "FreeType.h"

void FreeType::Initalize() {
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

    LoadCharacters((GLchar *) "/Users/joonas/CLionProjects/OpenGL/res/fonts/Lato-Regular.ttf");
}

void FreeType::LoadCharacters(GLchar *fontPath) {

    FT_Face face;
    // TODO: Find a way to load fonts with relative paths
    if (FT_New_Face(ft, fontPath, 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    for (FT_ULong index = 0; index < 128; index++) {

        FT_Set_Pixel_Sizes(face, 0, 48);

        if (FT_Load_Char(face, index, FT_LOAD_RENDER))
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;

        GLuint textureId;

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED,
                     GL_UNSIGNED_INT, face->glyph->bitmap.buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        Character character = Character {
                textureId,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                face->glyph->advance.x
        };

        characters.insert(std::pair<FT_ULong, Character>(index, character));
    }

}

void FreeType::SetupRendering(){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_VERTEX_ARRAY, VBO);

}





