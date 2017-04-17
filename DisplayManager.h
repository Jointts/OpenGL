//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_DISPLAYMANAGER_H
#define OPENGL_DISPLAYMANAGER_H

class GLFWwindow;

class DisplayManager {
public:
    int width = 0;

    int height = 0;

    DisplayManager(const char *title);

    GLFWwindow* window;
    static DisplayManager *getInstance();
    ~DisplayManager();
private:
    static DisplayManager *displayManager;
};


#endif //OPENGL_DISPLAYMANAGER_H
