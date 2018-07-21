//
// Created by Joonas on 26/12/2017.
//

#ifndef SUMMIT_ENGINE_TEXT_H
#define SUMMIT_ENGINE_TEXT_H


#include "Font.h"
#include "CharacterInstance.h"

class Text {
public:
    std::vector<CharacterInstance*> characters;
    glm::vec3                       color;
    CharacterInstance* characterInstance;

    Text() = delete;
    Text(std::string str, std::string fontName, glm::vec3 color = glm::vec3(255));

    void Draw();
};


#endif //SUMMIT_ENGINE_TEXT_H
