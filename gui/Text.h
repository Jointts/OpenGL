//
// Created by Joonas on 26/12/2017.
//

#ifndef OPENGL_TEXT_H
#define OPENGL_TEXT_H


#include "Font.h"
#include "CharacterInstance.h"

class Text {
public:
    Text(char* str);

    CharacterInstance* characterInstance;

    void Draw();
};


#endif //OPENGL_TEXT_H
