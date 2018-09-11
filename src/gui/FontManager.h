//
// Created by Joonas on 26/12/2017.
//

#ifndef SUMMIT_ENGINE_FONTMANAGER_H
#define SUMMIT_ENGINE_FONTMANAGER_H


#include "Font.h"

class FontManager {
    // TODO: Scan all fonts, dont hardcode it here
    std::map<const std::string, char *> fontsToLoad{
            {"LATO_LIGHT", "/home/jointts/CLionProjects/SE/src/gui/fonts/lato/Lato-Light.ttf"}
    };
    std::map<std::string, Font *>       fonts = {};
    static FontManager                  *fontManager;

    void addFont(std::string fontName, char *fontPath);
    void addFonts();
public:

    FontManager();
    Font *getFont(std::string fontName);
    static FontManager *getInstance();

};


#endif //SUMMIT_ENGINE_FONTMANAGER_H
