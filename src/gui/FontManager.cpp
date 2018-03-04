//
// Created by Joonas on 26/12/2017.
//

#include <iostream>
#include "FontManager.h"

FontManager *FontManager::fontManager = 0;

FontManager::FontManager() {
    addFonts();
}

FontManager *FontManager::getInstance() {
    if(!fontManager){
        fontManager = new FontManager();
    }
    return fontManager;
}

Font* FontManager::getFont(std::string fontName){
    return fontManager->fonts.at(fontName);
}

void FontManager::addFonts(){
//    std::map<std::string, char*>::iterator it;

    std::for_each(fontsToLoad.begin(), fontsToLoad.end(), [&](std::pair<const std::string, char*> &font){
        addFont(font.first, font.second);
    });

//    for ( it = fontsToLoad.begin(); it != fontsToLoad.end(); it++ )
//    {
//        addFont(it->first, it->second);
//    }
}

void FontManager::addFont(std::string fontName, char *fontPath) {
    Font *font =  new Font(fontPath);
    fonts.insert(std::pair<std::string, Font*>(fontName, font));
}
