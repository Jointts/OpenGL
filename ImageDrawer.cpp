//
// Created by Joonas on 11/17/2016.
//

#include "ImageDrawer.h"

ImageDrawer *ImageDrawer::imageDrawer = 0;

ImageDrawer::ImageDrawer() {

}

void ImageDrawer::voronoi(){
    
}

void ImageDrawer::generate() {
    // red
    color[0][0][0] = 255;
    color[0][0][1] = 0;
    color[0][0][2] = 0;
    color[0][0][3] = 0;

    // green
    color[0][1][0] = 0;
    color[0][1][1] = 255;
    color[0][1][2] = 0;
    color[0][1][3] = 0;

    // blue
    color[1][0][0] = 0;
    color[1][0][1] = 0;
    color[1][0][2] = 255;
    color[1][0][3] = 0;

    // white
    color[1][1][0] = 255;
    color[1][1][1] = 255;
    color[1][1][2] = 255;
    color[1][1][3] = 0;
}


void ImageDrawer::draw() {
    glMatrixMode(GL_MODELVIEW);
    glDrawPixels(2, 2, GL_RGBA, GL_UNSIGNED_BYTE, color);
    glFlush();
}

ImageDrawer *ImageDrawer::getInstance() {
    if (!imageDrawer) {
        imageDrawer = new ImageDrawer();
    }
    return imageDrawer;
}
