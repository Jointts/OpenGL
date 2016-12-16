//
// Created by Joonas on 06/10/2016.
//

#ifndef OPENGL_DISPLAYMANAGER_H
#define OPENGL_DISPLAYMANAGER_H


class DisplayManager {
public:
    DisplayManager(int width, int height, const char *title);

    GLFWwindow* window;
    static DisplayManager *getInstance();
    ~DisplayManager();
private:
    static DisplayManager *displayManager;
};


#endif //OPENGL_DISPLAYMANAGER_H
