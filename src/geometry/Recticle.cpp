//
// Created by jointts on 20.03.18.
//

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <cstdint>
#include <vector>
#include <stb_image_write.h>
#include <cmath>
#include <iostream>
#include "Recticle.h"

Recticle::Recticle(int width, int height, int radius) : width(width), height(height), radius(radius) {
    GenerateMask();
}

void Recticle::GenerateMask() {
    std::vector<uint8_t> pixels(width * height * 3, 255);

    int numOfElements = 0;

    for (int x = 0; x < this->width; ++x) {
        for (int y = 0; y < this->height; ++y) {
            if(IsPointInArea(x, y)){
                int pixelCoord = (x * this->height + y) * 3;;
                pixels[pixelCoord] = 125;
                pixels[pixelCoord + 1] = 125;
                pixels[pixelCoord + 2] = 125;
            }
            numOfElements++;
        }
    }

    stbi_write_jpg("/home/jointts/CLionProjects/SE/test_AA.jpg", this->width, this->height, 3, pixels.data(), 100);
}

bool Recticle::IsPointInArea(int x, int y){
    x -= (this->width / 2);
    y -= (this->height / 2);

    double width = (double) this->width;
    double height = (double) this->height;
    double radius = this->radius;

    double aPow = 2 * width / radius;
    double bPow = 2 * height / radius;

    double aDiv = abs(x * 2) / width;
    double bDiv = abs(y * 2) / height;

    double aResult = pow(aDiv, aPow);
    double bResult = pow(bDiv, bPow);

    int result = aResult + bResult;

    return result > 0;

}
