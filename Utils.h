//
// Created by joonas on 19.09.16.
//

#ifndef OPENGL_UTILS_H
#define OPENGL_UTILS_H

#include "string"
#include <vec3.hpp>


class Utils {
public:
    static std::string readFile(const char *filePath);

    static glm::vec3 color_RGB(float r, float g, float b);

    static glm::vec3 GetNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);
};


#endif //OPENGL_UTILS_H
