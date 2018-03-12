//
// Created by Joonas on 15/04/2017.
//

#ifndef SUMMIT_ENGINE_CHARACTER_H
#define SUMMIT_ENGINE_CHARACTER_H

#include <ft2build.h>

#ifndef __gl_h_
#include <glad/glad.h>
#endif

#include <glm/detail/type_vec.hpp>
#include <glm/vec2.hpp>
#include <map>
#include FT_FREETYPE_H

struct Character {
    GLuint textureId;
    glm::ivec2 size;
    glm::ivec2 bearing;
    FT_Pos advance;
};

class FreeType {
public:
    std::map<FT_ULong, Character> characters;

    FT_Library ft;

    void Initalize();

    void LoadCharacters(GLchar *fontPath);

    void SetupRendering();

    GLuint VAO, VBO;
};


#endif //SUMMIT_ENGINE_CHARACTER_H
