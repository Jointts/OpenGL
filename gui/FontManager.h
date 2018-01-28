//
// Created by Joonas on 26/12/2017.
//

#ifndef OPENGL_FONTMANAGER_H
#define OPENGL_FONTMANAGER_H


#include "Font.h"

class FontManager {
    std::map <std::string, char*> fontsToLoad{
            {"LATO_LIGHT", "/Users/joonas/CLionProjects/OpenGL/gui/fonts/lato/Lato-Light.ttf"}
    };

    std::map<std::string, Font*> fonts = {};

    static FontManager *fontManager;
public:
    FontManager();

    static FontManager *getInstance();

    Font* getFont(std::string fontName);

    void addFont(std::string fontName, char* fontPath);

    void addFonts();
};


#endif //OPENGL_FONTMANAGER_H
