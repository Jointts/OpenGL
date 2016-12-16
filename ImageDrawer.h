//
// Created by Joonas on 11/17/2016.
//

#ifndef OPENGL_IMAGEDRAWER_H
#define OPENGL_IMAGEDRAWER_H
#include <glad/glad.h>

class ImageDrawer {
public:
    ImageDrawer();
    GLubyte color[2][2][4];
    void generate();
    void draw();
    static ImageDrawer *getInstance();
private:
    static ImageDrawer *imageDrawer;

    void voronoi();
};


#endif //OPENGL_IMAGEDRAWER_H
