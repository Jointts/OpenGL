//
// Created by jointts on 20.03.18.
//

#ifndef SUMMITENGINE_RECTICLE_H
#define SUMMITENGINE_RECTICLE_H


class Recticle {
    int r, g, b = 0;
    int width   = 0, height = 0, radius = 0;
    bool IsPointInArea(int x, int y);
public:
    Recticle(int width, int height, int radius = 0);

    void GenerateMask();
};


#endif //SUMMITENGINE_RECTICLE_H
