//
// Created by Joonas on 05/09/2017.
//

#ifndef OPENGL_GUIMANAGER_H
#define OPENGL_GUIMANAGER_H



class GuiManager {

public:
    static GuiManager *guiManager;

    GuiManager();

    static GuiManager* getInstance();
};


#endif //OPENGL_GUIMANAGER_H
